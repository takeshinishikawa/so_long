/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakeshi <rtakeshi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:07:51 by rtakeshi          #+#    #+#             */
/*   Updated: 2021/11/15 11:54:37 by rtakeshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (check_map(argc, argv) != 0)
		return (-1);
	if (get_map(&game, argv[1]) != 0)
		exit (1);
	if (game.valid_map)
		init_game_struct(&game);
	else
	{
		free(game.map);
		exit(1);
	}
	print_map(&game);
	mlx_key_hook(game.win, check_key, &game);
	mlx_hook(game.win, 33, 1L << 5, close_game, &game);
	mlx_hook(game.win, 15, 1L << 16, min_window, &game);
	mlx_loop(game.mlx);
	mlx_destroy_display(game.mlx);
	free(game.mlx);
}
