/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakeshi <rtakeshi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:07:51 by rtakeshi          #+#    #+#             */
/*   Updated: 2021/11/14 23:22:12 by rtakeshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int get_map(t_game *game, char *argv)
{
	char	*line;
	int		gnl_status;

	if (create_map(game) == 0)
		return (0);
	if (get_fd(game, argv) == 0)
		return (0);
	line = 0;
	gnl_status = 0;
	game->valid_map = get_first_line(&line, &gnl_status, game);
	get_other_lines(&line, &gnl_status, game);
	if (game->valid_map)
		check_min_config(game);
	else
		ft_printf("Error\nInvalid map, please check it.\n");
	close(game->fd);
	return (0);
}
