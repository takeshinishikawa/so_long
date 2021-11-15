/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakeshi <rtakeshi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:07:51 by rtakeshi          #+#    #+#             */
/*   Updated: 2021/11/14 23:21:31 by rtakeshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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
