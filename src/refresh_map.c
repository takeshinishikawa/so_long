/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakeshi <rtakeshi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:07:51 by rtakeshi          #+#    #+#             */
/*   Updated: 2021/11/14 23:20:02 by rtakeshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	refresh_map(t_game *game, int x, int y)
{
	game->map[game->p_x + x + (game->p_y + y) * game->line_len] = PLAYER;
	game->map[game->p_x + game->p_y * game->line_len] = EMPTY;
	game->moves++;
	ft_printf("Number of movements: %i\n", game->moves);
}
