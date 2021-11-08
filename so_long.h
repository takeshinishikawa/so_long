/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakeshi <rtakeshi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 12:08:20 by rtakeshi          #+#    #+#             */
/*   Updated: 2021/11/08 13:18:47 by rtakeshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libs/mlx/mlx.h"
# include "libs/libft/libft.h"

# define MAP_SIZE 10000

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_img	img;
	int		fd;
	char	*map;
	size_t	line_len;
	size_t	x;
	size_t	y;





}	t_game;

//img structs
typedef struct s_img
{
	void *ptr;
	int *data;
	int width;
	int height;

	int size_l;
	int bpp;
	int endian;
} t_img;

//so_long functions
int	check_map(int argc, char **argv);
int get_map(char *argv);
#endif
