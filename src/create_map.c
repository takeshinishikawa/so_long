/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakeshi <rtakeshi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:07:51 by rtakeshi          #+#    #+#             */
/*   Updated: 2021/11/14 23:21:27 by rtakeshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	create_map(t_game *game)
{
	game->map = malloc(sizeof(char) * MAP_SIZE);
	if (game->map == NULL)
	{
		ft_printf("Error\nFailed to store the map. Please, try again.\n");
		free(game->map);
		return (0);
	}
	*(game->map) = 0;
	return (1);
}
