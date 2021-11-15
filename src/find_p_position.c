/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_p_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakeshi <rtakeshi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:07:51 by rtakeshi          #+#    #+#             */
/*   Updated: 2021/11/14 23:21:45 by rtakeshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	find_p_position(t_game *game)
{
	unsigned int	line;
	unsigned int	full_line;

	full_line = 0;
	while (full_line < game->line_number)
	{
		line = 0;
		while (line < game->line_len)
		{
			if (game->map[line + full_line * game->line_len] == PLAYER)
				break;
			line++;
		}
		if (game->map[line + full_line * game->line_len] == PLAYER)
			break;
		full_line++;
	}
	game->p_x = line;
	game->p_y = full_line;
}
