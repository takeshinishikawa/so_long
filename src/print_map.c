/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakeshi <rtakeshi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:07:51 by rtakeshi          #+#    #+#             */
/*   Updated: 2021/11/15 00:11:10 by rtakeshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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
			print_img(game, game->map[line + full_line], \
			game->p_x += 50, game->p_y * 49);
			line++;
		}
		game->p_y++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->mlx_img, 0, 0);
}
