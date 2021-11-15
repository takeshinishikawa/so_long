/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakeshi <rtakeshi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:07:51 by rtakeshi          #+#    #+#             */
/*   Updated: 2021/11/14 23:22:33 by rtakeshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_game_struct(t_game *game)
{
	int	needle;

	needle = 0;
	game_default(game);
	while (game->map[needle++])
	{
		if (game->map[needle] == PLAYER)
			game->player_nbr++;
		if (game->map[needle] == COLLECTIBLE)
			game->collectible_nbr++;
		if (game->map[needle] == EXIT)
			game->exit_nbr++;
	}
}
