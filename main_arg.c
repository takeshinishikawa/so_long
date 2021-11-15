/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakeshi <rtakeshi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:07:51 by rtakeshi          #+#    #+#             */
/*   Updated: 2021/11/14 22:01:06 by rtakeshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_wall_line(char *line, size_t len)
{
	size_t	needle;

	needle = 0;
	while (needle < len)
	{
		if (line[needle] == WALL)
			needle++;
		else
			return (0);
	}
	return (1);
}

//check if line limits is a Wall
int	check_mid_line(char *line, size_t len)
{
	if (line[0] == WALL && line[len - 1] == WALL)
		return (1);
	ft_printf("Error\nA wall is missing at the edges.\n");
	return (0);
}

//Check if mid_len has the correct line_size
void	check_line_len(char *line, t_game *game)
{
	if (ft_strlen(line) != game->line_len)
		ft_printf("Error\nAll lines must have the same number of chars.\n");
}

int	parse_map(char *map)
{
	int	needle;

	needle = 0;
	while (map[needle])
	{
		if (map[needle] != EXIT && map[needle] != WALL && \
		map[needle] != COLLECTIBLE && map[needle] != EMPTY \
		&& map[needle] != PLAYER)
			return (1);
		needle++;
	}
	return (0);
}

int	create_map(t_game *game)
{
	game->map = malloc(sizeof(char) * MAP_SIZE);
	if (game->map == NULL)
	{
		ft_printf("Error\nFailed to store the map. Please, try again.\n");
		free(game->map);
		return (0);
	}
	*(game->map) = 0;
	return (1);
}

//get_fd function
int	get_fd(t_game *game, char *argv)
{
	game->fd = open(argv, O_RDONLY);
	if (game->fd == -1)
	{
		ft_printf("Error\nFailed to open the file.\n");
		free(game->map);
		return (0);
	}
	game->line_number = 0;
	return (1);
}

//check first line and include in game->map
int	get_first_line(char **line, int *gnl_status, t_game *game)
{
	int	valid_map;

	valid_map = 0;
	if ((*gnl_status = get_next_line(game->fd, line)) > 0)
	{
		game->line_len = ft_strlen(*line);
		valid_map = check_wall_line(*line, game->line_len);
		if (valid_map == 0)
		{
			ft_printf("Error\nA wall is missing in the first line.\n");
			return (valid_map);
		}
	}
	return (0);
}

void	check_last_line(char **line, t_game *game)
{
	if (**line == 0)
		ft_printf("Error\nPlease, check the last line.\n");
	ft_strcat(game->map, *line);
	free (*line);
	*line = 0;
}

//check other lines and include in game->map
void	get_other_lines(char **line, int *gnl_status, t_game *game)
{
	while (*gnl_status > 0)
	{
		game->line_number++;
		game->valid_map = check_mid_line(*line, game->line_len);
		check_line_len(*line, game);
		ft_strcat(game->map, *line);
		free (*line);
		*line = 0;
		*gnl_status = get_next_line(game->fd, line);
		if (*gnl_status == 0)
		{
			game->valid_map = check_wall_line((game->map + ft_strlen(game->map) - game->line_len), game->line_len);
			if (game->valid_map == 0)
				check_last_line(line, game);
			free (*line);
		}
	}
}
//check map meets minimumm requisites
//VALIDATE QTT OF LINE/COLUMNS AT LEAST 4X4
void	check_min_config(t_game *game)
{
	if (game->line_len < 4 || game->line_number < 4)
	{
		ft_printf("Error\nValid map must have at least 4 lines/columns.\n");
		game->valid_map = 0;
		return ;
	}
	if (parse_map(game->map) == 1)
	{
		ft_printf("Error\nValid map must be composed by 0, 1, C, E and P.\n");
		game->valid_map = 0;
	}
	game->map_width = game->line_len * 50;
	game->map_height = game->line_number * 50;
	game->valid_map = 1;
}

void	load_img(t_game *game, t_img **img, char *path)
{
	*img = mlx_xpm_file_to_image(game->mlx, path, &game->map_width, &game->map_height);
	if (*img == NULL)
	{
		ft_printf("Error\nElement image could not be loaded.\n");
		game->valid_map = 0;
	}
}

void	init_img(t_game *game)
{
	load_img(game, &game->empty, PATH_0);
	load_img(game, &game->player, PATH_P_START);
	load_img(game, &game->collectible, PATH_C);
	load_img(game, &game->wall, PATH_1);
	load_img(game, &game->closed_exit, PATH_E_CLOSED);
	load_img(game, &game->opened_exit, PATH_E_OPENED);
}

void	game_default(t_game *game)
{
	game->moves = 0;
	game->exit_nbr = 0;
	game->player_nbr = 0;
	game->collectible_nbr = 0;
	//include here mlx pointer inits
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map_width, game->map_height, WINDOW_NAME);
	game->mlx_img = mlx_new_image(game->mlx, game->map_width, game->map_height);
	init_img(game);
}


void	init_game_struct(t_game *game)
{
	int	needle;

	needle = 0;
	game_default(game);
	while (game->map[needle++])
	{
		if (game->map[needle] == PLAYER)
			game->player_nbr++;
		if (game->map[needle] == COLLECTIBLE)
			game->collectible_nbr++;
		if (game->map[needle] == EXIT)
			game->exit_nbr++;
	}
}

int get_map(t_game *game, char *argv)
{
	char	*line;
	int		gnl_status;

	if (create_map(game) == 0)
		return (0);
	if (get_fd(game, argv) == 0)
		return (0);
	line = 0;
	gnl_status = 0;
	game->valid_map = get_first_line(&line, &gnl_status, game);
	get_other_lines(&line, &gnl_status, game);
	if (game->valid_map)
		check_min_config(game);
	else
		ft_printf("Error\nInvalid map, please check it.\n");
	close(game->fd);
	return (0);
}


//mlx_utils
unsigned int	mlx_rgb_to_int(int o, int r, int g, int b)
{
	return(o << 24 | r << 16 | g << 8 | b);
}

unsigned int	mlx_get_pixel(t_img *img, int x, int y)
{
	return(*(unsigned int *)(img->data + (x * img->bpp / 8 + y * img->size_line)));
}

void	mlx_draw_pixel(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->data + (x * img->bpp / 8 + y * img->size_line);
	*(unsigned int *)pixel = color;
}

void	draw_image(t_game *game, t_img *img, size_t line, size_t col)
{
	unsigned int	color;
	int				x;
	int				y;

	y = 0;
	while (y < 50)
	{
		x = 0;
		while (x < 50)
		{
			color = mlx_get_pixel(img, x, y);
			if (color != mlx_rgb_to_int(0, 255, 255, 255))
				mlx_draw_pixel(game->mlx_img, x + line, y + col, color);
			x++;
		}
		y++;
	}
}

void	print_img(t_game *game, char element, size_t line, size_t col)
{
	if (element == PLAYER)
		draw_image(game, game->player, line, col);
	if (element == COLLECTIBLE)
		draw_image(game, game->collectible, line, col);
	if (element == EMPTY)
		draw_image(game, game->empty, line, col);
	if (element == WALL)
		draw_image(game, game->wall, line, col);
	if (element == EXIT && game->collectible_nbr)
		draw_image(game, game->closed_exit, line, col);
	if (element == EXIT && !game->collectible_nbr)
		draw_image(game, game->opened_exit, line, col);
}

void	print_map(t_game *game)
{
	size_t	line;
	size_t	full_line;

	game->p_x = -50;
	game->p_y = 0;
	while (game->p_y < (int)game->line_number)
	{
		line = 0;
		full_line = game->line_len * game->p_y;
		while (line < game->line_len)
		{
			print_img(game, game->map[line + full_line], game->p_x += 50, game->p_y * 49);
			line++;
		}
		game->p_y++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->mlx_img, 0, 0);
}


void	erase_images(t_game *game)
{
	mlx_destroy_image(game->mlx, game->empty);
	mlx_destroy_image(game->mlx, game->player);
	mlx_destroy_image(game->mlx, game->collectible);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->closed_exit);
	mlx_destroy_image(game->mlx, game->opened_exit);
	mlx_destroy_image(game->mlx, game->mlx_img);
}

int	close_game(t_game *game)
{
	free(game->map);
	erase_images(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(1);
}

int	min_window(t_game *game)
{
	print_map(game);
	return (1);
}

void	find_p_position(t_game *game)
{
	unsigned int	line;
	unsigned int	full_line;

	full_line = 0;
	while (full_line < game->line_number)
	{
		line = 0;
		while (line < game->line_len)
		{
			if (game->map[line + full_line * game->line_len] == PLAYER)
				break;
			line++;
		}
		if (game->map[line + full_line * game->line_len] == PLAYER)
			break;
		full_line++;
	}
	game->p_x = line;
	game->p_y = full_line;
}

//movements.c

int		validate_move(char c, t_game *game)
{
	if (c == WALL)
	{
		ft_printf("Cannot move into a wall.\n");
		return (1);
	}
	else if (c == EXIT && game->collectible_nbr)
	{
		ft_printf("Exit is closed, you must get all collectables.\n");
		return (1);
	}
	return (0);
}

void	refresh_map(t_game *game, int x, int y)
{
	game->map[game->p_x + x + (game->p_y + y) * game->line_len] = PLAYER;
	game->map[game->p_x + game->p_y * game->line_len] = EMPTY;
	game->moves++;
	ft_printf("Number of movements: %i\n", game->moves);
}

void	refresh_p_img(t_game *game, char *address)
{
	mlx_destroy_image(game->mlx, game->player);
	load_img(game, &game->player, address);
}

void	move(t_game *game, int x, int y, char *path1, char *path2)
{
	char	target;

	refresh_p_img(game, path1);
	print_map(game);
	find_p_position(game);
	target = game->map[game->p_x + x + (game->p_y + y) * game->line_len];
	if (validate_move(target, game) == 1)
		return ;
	else if (target == EXIT && !game->collectible_nbr)
	{
		ft_printf("You found the exit.\n");
		refresh_map(game, x, y);
		close_game(game);
	}
	else if (target == COLLECTIBLE)
	{
		ft_printf("Got a collectable.\n");
		game->collectible_nbr--;
	}
	refresh_map(game, x, y);
	refresh_p_img(game, path2);
}

int	check_key(int key, t_game *game)
{
	if (key == LEFT)
		move(game, -1, 0, PATH_P_A1, PATH_P_A2);
	if (key == DOWN)
		move(game, 0, +1, PATH_P_S1, PATH_P_S2);
	if (key == RIGHT)
		move(game, +1, 0, PATH_P_D1, PATH_P_D2);
	if (key == UP)
		move(game, 0, -1, PATH_P_W1, PATH_P_W2);
	if (key == ESC)
		close_game(game);
	print_map(game);
	return (1);
}


int	main(int argc, char **argv)
{
	t_game	game;

	if (check_map(argc, argv) != 0)
		return (-1);
	if (get_map(&game, argv[1]) != 0)
		exit (1);
	if (game.valid_map)
		init_game_struct(&game);
	else
	{
		free(game.map);
		exit(1);
	}
	print_map(&game);
	mlx_key_hook(game.win, check_key, &game);
	mlx_hook(game.win, 33, 1L << 5, close_game, &game);
	mlx_hook(game.win, 15, 1L << 16, min_window, &game);
	mlx_loop(game.mlx);
	mlx_destroy_display(game.mlx);
	free(game.mlx);
}
