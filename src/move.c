/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakeshi <rtakeshi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:07:51 by rtakeshi          #+#    #+#             */
/*   Updated: 2021/11/14 23:24:00 by rtakeshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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
