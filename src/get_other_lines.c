/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_other_lines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakeshi <rtakeshi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:07:51 by rtakeshi          #+#    #+#             */
/*   Updated: 2021/11/15 00:10:02 by rtakeshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	get_other_lines(char **line, int *gnl_status, t_game *game)
{
	while (*gnl_status > 0)
	{
		game->line_number++;
		game->valid_map = check_mid_line(*line, game->line_len);
		check_line_len(*line, game);
		ft_strcat(game->map, *line);
		free (*line);
		*line = 0;
		*gnl_status = get_next_line(game->fd, line);
		if (*gnl_status == 0)
		{
			game->valid_map = check_wall_line((game->map + \
			ft_strlen(game->map) - game->line_len), game->line_len);
			if (game->valid_map == 0)
				check_last_line(line, game);
			free (*line);
		}
	}
}
