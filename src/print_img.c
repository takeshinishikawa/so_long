/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakeshi <rtakeshi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:07:51 by rtakeshi          #+#    #+#             */
/*   Updated: 2021/11/14 23:24:09 by rtakeshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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
