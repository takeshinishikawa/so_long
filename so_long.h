/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakeshi <rtakeshi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 12:08:20 by rtakeshi          #+#    #+#             */
/*   Updated: 2021/11/13 12:16:49 by rtakeshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libs/mlx/mlx.h"
# include "libs/mlx/mlx_int.h"
# include "libs/libft/libft.h"

# define MAP_SIZE 10000

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
	int		x;
	int		y;

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
#endif
