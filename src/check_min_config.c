/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_min_config.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakeshi <rtakeshi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:07:51 by rtakeshi          #+#    #+#             */
/*   Updated: 2021/11/14 23:21:09 by rtakeshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_min_config(t_game *game)
{
	if (game->line_len < 4 || game->line_number < 4)
	{
		ft_printf("Error\nValid map must have at least 4 lines/columns.\n");
		game->valid_map = 0;
		return ;
	}
	if (parse_map(game->map) == 1)
	{
		ft_printf("Error\nValid map must be composed by 0, 1, C, E and P.\n");
		game->valid_map = 0;
	}
	game->map_width = game->line_len * 50;
	game->map_height = game->line_number * 50;
	game->valid_map = 1;
}
