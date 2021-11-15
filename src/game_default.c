/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_default.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakeshi <rtakeshi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:07:51 by rtakeshi          #+#    #+#             */
/*   Updated: 2021/11/14 23:21:52 by rtakeshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	game_default(t_game *game)
{
	game->moves = 0;
	game->exit_nbr = 0;
	game->player_nbr = 0;
	game->collectible_nbr = 0;
	//include here mlx pointer inits
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map_width, game->map_height, WINDOW_NAME);
	game->mlx_img = mlx_new_image(game->mlx, game->map_width, game->map_height);
	init_img(game);
}
