/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakeshi <rtakeshi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:07:51 by rtakeshi          #+#    #+#             */
/*   Updated: 2021/11/14 23:21:58 by rtakeshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	get_fd(t_game *game, char *argv)
{
	game->fd = open(argv, O_RDONLY);
	if (game->fd == -1)
	{
		ft_printf("Error\nFailed to open the file.\n");
		free(game->map);
		return (0);
	}
	game->line_number = 0;
	return (1);
}
