/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakeshi <rtakeshi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:07:51 by rtakeshi          #+#    #+#             */
/*   Updated: 2021/11/14 23:20:40 by rtakeshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	check_key(int key, t_game *game)
{
	if (key == LEFT)
		move(game, -1, 0, PATH_P_A1, PATH_P_A2);
	if (key == DOWN)
		move(game, 0, +1, PATH_P_S1, PATH_P_S2);
	if (key == RIGHT)
		move(game, +1, 0, PATH_P_D1, PATH_P_D2);
	if (key == UP)
		move(game, 0, -1, PATH_P_W1, PATH_P_W2);
	if (key == ESC)
		close_game(game);
	print_map(game);
	return (1);
}
