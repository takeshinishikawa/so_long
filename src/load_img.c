/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakeshi <rtakeshi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:07:51 by rtakeshi          #+#    #+#             */
/*   Updated: 2021/11/15 00:13:19 by rtakeshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	load_img(t_game *game, t_img **img, char *path)
{
	*img = mlx_xpm_file_to_image(game->mlx, path, &game->map_width, \
	&game->map_height);
	if (*img == NULL)
	{
		ft_printf("Error\nElement image could not be loaded.\n");
		game->valid_map = 0;
	}
}
