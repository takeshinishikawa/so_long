/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakeshi <rtakeshi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:07:51 by rtakeshi          #+#    #+#             */
/*   Updated: 2021/11/14 23:24:05 by rtakeshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	parse_map(char *map)
{
	int	needle;

	needle = 0;
	while (map[needle])
	{
		if (map[needle] != EXIT && map[needle] != WALL && \
		map[needle] != COLLECTIBLE && map[needle] != EMPTY \
		&& map[needle] != PLAYER)
			return (1);
		needle++;
	}
	return (0);
}
