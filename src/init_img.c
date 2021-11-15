/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakeshi <rtakeshi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:07:51 by rtakeshi          #+#    #+#             */
/*   Updated: 2021/11/14 23:22:38 by rtakeshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_img(t_game *game)
{
	load_img(game, &game->empty, PATH_0);
	load_img(game, &game->player, PATH_P_START);
	load_img(game, &game->collectible, PATH_C);
	load_img(game, &game->wall, PATH_1);
	load_img(game, &game->closed_exit, PATH_E_CLOSED);
	load_img(game, &game->opened_exit, PATH_E_OPENED);
}
