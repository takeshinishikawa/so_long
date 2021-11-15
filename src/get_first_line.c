/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_first_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakeshi <rtakeshi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:07:51 by rtakeshi          #+#    #+#             */
/*   Updated: 2021/11/15 00:08:57 by rtakeshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	get_first_line(char **line, int *gnl_status, t_game *game)
{
	int	valid_map;

	valid_map = 0;
	*gnl_status = get_next_line(game->fd, line);
	if (*gnl_status > 0)
	{
		game->line_len = ft_strlen(*line);
		valid_map = check_wall_line(*line, game->line_len);
		if (valid_map == 0)
		{
			ft_printf("Error\nA wall is missing in the first line.\n");
			return (valid_map);
		}
	}
	return (0);
}
