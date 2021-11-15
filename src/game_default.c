/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_default.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakeshi <rtakeshi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:07:51 by rtakeshi          #+#    #+#             */
/*   Updated: 2021/11/15 11:51:59 by rtakeshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	start_coord(t_coord *coord, int x, int y)
{
	coord->x = x;
	coord->y = y;
}

void	game_default(t_game *game)
{
	game->moves = 0;
	game->exit_nbr = 0;
	game->player_nbr = 0;
	game->collectible_nbr = 0;
	start_coord(&game->p_left, -1, 0);
	start_coord(&game->p_down, 0, 1);
	start_coord(&game->p_right, 1, 0);
	start_coord(&game->p_up, 0, -1);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map_width, \
	game->map_height, WINDOW_NAME);
	game->mlx_img = mlx_new_image(game->mlx, game->map_width, \
		game->map_height);
	init_img(game);
}
