/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakeshi <rtakeshi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:07:51 by rtakeshi          #+#    #+#             */
/*   Updated: 2021/11/14 23:24:29 by rtakeshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int		validate_move(char c, t_game *game)
{
	if (c == WALL)
	{
		ft_printf("Cannot move into a wall.\n");
		return (1);
	}
	else if (c == EXIT && game->collectible_nbr)
	{
		ft_printf("Exit is closed, you must get all collectables.\n");
		return (1);
	}
	return (0);
}
