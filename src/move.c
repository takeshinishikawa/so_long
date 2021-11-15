/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakeshi <rtakeshi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:07:51 by rtakeshi          #+#    #+#             */
/*   Updated: 2021/11/15 12:59:36 by rtakeshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	move(t_game *game, t_coord *coord, char *path1, char *path2)
{
	char	target;

	refresh_p_img(game, path1);
	print_map(game);
	find_p_position(game);
	target = game->map[game->p_x + coord->x + \
		(game->p_y + coord->y) * game->line_len];
	if (validate_move(target, game) == 1)
		return ;
	else if (target == EXIT && !game->collectible_nbr)
	{
		ft_printf("You won! Exit was found.\n");
		refresh_map(game, coord->x, coord->y);
		close_game(game);
	}
	else if (target == COLLECTIBLE)
	{
		ft_printf("Got a collectable.\n");
		game->collectible_nbr--;
	}
	refresh_map(game, coord->x, coord->y);
	refresh_p_img(game, path2);
}
