/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakeshi <rtakeshi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:07:51 by rtakeshi          #+#    #+#             */
/*   Updated: 2021/11/13 15:28:40 by rtakeshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_wall_line(char *line, size_t len)
{
	size_t	needle;

	needle = 0;
	while (needle < len)
	{
		if (line[needle] == '1')
			needle++;
		else
			return (0);
	}
	return (1);
}

//check if line limits is a Wall
int	check_mid_line(char *line, size_t len)
{
	if (line[0] == '1' && line[len - 1] == '1')
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
		if (map[needle] != '0' && map[needle] != '1' && map[needle] != 'C'\
		 && map[needle] != 'E' && map[needle] != 'P')
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
	int	valid_map;

	while (*gnl_status > 0)
	{
		game->line_number++;
		valid_map = check_mid_line(*line, game->line_len);
		check_line_len(*line, game);
		ft_strcat(game->map, *line);
		free (*line);
		*line = 0;
		*gnl_status = get_next_line(game->fd, line);
		if (*gnl_status == 0)
		{
			valid_map = check_wall_line((game->map + ft_strlen(game->map) - game->line_len), game->line_len);
			if (valid_map == 0)
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
	load_img(game, &game->empty, "./img/empty.xpm");
	load_img(game, &game->player, "./img/p_start.xpm");
	load_img(game, &game->collectible, "./img/collectible.xpm");
	load_img(game, &game->wall, "./img/wall.xpm");
	load_img(game, &game->closed_exit, "./img/exit_closed.xpm");
	load_img(game, &game->opened_exit, "./img/exit_opened.xpm");
}


void	game_default(t_game *game)
{
	game->moves = 0;
	game->exit_nbr = 0;
	game->player_nbr = 0;
	game->collectible_nbr = 0;
	//include here mlx pointer inits
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map_width, game->map_height, "SO_LONG");
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
		if (game->map[needle] == 'P')
			game->player_nbr++;
		if (game->map[needle] == 'C')
			game->collectible_nbr++;
		if (game->map[needle] == 'E')
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
	check_min_config(game);
	/*VALIDATE QTT OF LINE/COLUMNS AT LEAST 4X4
	if (game->line_len < 4 || game->line_number < 4)
		ft_printf("Valid map must have at least 4 lines/columns.\n");*/
	/*VALIDATE CENTER*/
	//0 IS EMPTY SPACE
	//1 WALL
	//C COLLECTIBLE
	//E MAP EXIT
	//P PLAYER
	/*if (parse_map(game->map) == 1)
		ft_printf("Valid map must be composed by 0, 1, C, E and P.\n");*/

	//AT LEAST 1 C
	//AT LEAST 1 E
	//AT LEAST 1 P
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
	if (element == 'P')
		draw_image(game, game->player, line, col);
	if (element == 'C')
		draw_image(game, game->collectible, line, col);
	if (element == '0')
		draw_image(game, game->empty, line, col);
	if (element == '1')
		draw_image(game, game->wall, line, col);
	if (element == 'E' && game->collectible_nbr)
		draw_image(game, game->closed_exit, line, col);
	if (element == 'E' && !game->collectible_nbr)
		draw_image(game, game->opened_exit, line, col);
}

void	print_map(t_game *game)
{
	size_t	line;
	size_t	full_line;

	game->x = -50;
	game->y = 0;
	while (game->y < (int)game->line_number)
	{
		line = 0;
		full_line = game->line_len * game->y;
		while (line < game->line_len)
		{
			print_img(game, game->map[line + full_line], game->x += 50, game->y * 49);
			line++;
		}
		game->y++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->mlx_img, 0, 0);
}

int	check_key(int key, char *str)
{
	//Printa o argumento passado na mlx_key_hook
	printf("%s\n", str);
	printf("%c\n", key);
	if (key == 'p')
		exit(1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (check_map(argc, argv) != 0)
		return (-1);
	if (get_map(&game, argv[1]) != 0)
		return (-1);
	if (game.valid_map)
		init_game_struct(&game);
	else
		free(game.map);
	print_map(&game);
	mlx_key_hook(game.win, check_key, &game);

	mlx_loop(game.mlx);
}
