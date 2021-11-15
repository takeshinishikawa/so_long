/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakeshi <rtakeshi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 12:08:20 by rtakeshi          #+#    #+#             */
/*   Updated: 2021/11/14 23:25:39 by rtakeshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/mlx/mlx.h"
# include "../libs/mlx/mlx_int.h"
# include "../libs/libft/libft.h"

# define MAP_SIZE 10000
# define WINDOW_NAME "SO_LONG"
# define PATH_C "./img/collectible.xpm"
# define PATH_0 "./img/empty.xpm"
# define PATH_1 "./img/wall.xpm"
# define PATH_E_CLOSED "./img/exit_closed.xpm"
# define PATH_E_OPENED "./img/exit_opened.xpm"
# define PATH_P_START "./img/p_start.xpm"
# define PATH_P_W1 "./img/p_up1.xpm"
# define PATH_P_W2 "./img/p_up.xpm"
# define PATH_P_A1 "./img/p_left1.xpm"
# define PATH_P_A2 "./img/p_left.xpm"
# define PATH_P_S1 "./img/p_down1.xpm"
# define PATH_P_S2 "./img/p_down.xpm"
# define PATH_P_D1 "./img/p_right1.xpm"
# define PATH_P_D2 "./img/p_right.xpm"
# define EMPTY '0'
# define WALL '1'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define PLAYER 'P'
# define LEFT 'a'
# define RIGHT 'd'
# define UP 'w'
# define DOWN 's'
# define ESC 65307

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_img	*mlx_img;
	int		map_width;
	int		map_height;
	int		moves;

	int		fd;
	char	*map;
	int		valid_map;
	size_t	line_len;
	size_t	line_number;
	int		p_x;
	int		p_y;

	t_img	*empty;
	t_img	*player;
	t_img	*collectible;
	t_img	*wall;
	t_img	*closed_exit;
	t_img	*opened_exit;

	int		exit_nbr;
	int		player_nbr;
	int		collectible_nbr;





}	t_game;

//so_long functions
int	check_map(int argc, char **argv);
int get_map(t_game *game, char *argv);
int	create_map(t_game *game);
int	get_fd(t_game *game, char *argv);
int	get_first_line(char **line, int *gnl_status, t_game *game);
int	check_wall_line(char *line, size_t len);
void	get_other_lines(char **line, int *gnl_status, t_game *game);
int	check_mid_line(char *line, size_t len);
void	check_line_len(char *line, t_game *game);
void	check_last_line(char **line, t_game *game);
void	check_min_config(t_game *game);
int	parse_map(char *map);
void	init_game_struct(t_game *game);
void	game_default(t_game *game);
void	init_img(t_game *game);
void	load_img(t_game *game, t_img **img, char *path);
void	print_map(t_game *game);
void	print_img(t_game *game, char element, size_t line, size_t col);
void	draw_image(t_game *game, t_img *img, size_t line, size_t col);
void	mlx_draw_pixel(t_img *img, int x, int y, int color);
unsigned int	mlx_get_pixel(t_img *img, int x, int y);
unsigned int	mlx_rgb_to_int(int o, int r, int g, int b);

int	check_key(int key, t_game *game);
void	move(t_game *game, int x, int y, char *path1, char *path2);
int		validate_move(char c, t_game *game);
void	find_p_position(t_game *game);
int	min_window(t_game *game);
int	close_game(t_game *game);
void	erase_images(t_game *game);
void	refresh_p_img(t_game *game, char *address);
void	refresh_map(t_game *game, int x, int y);




#endif
