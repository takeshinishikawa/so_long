/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase_images.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakeshi <rtakeshi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:07:51 by rtakeshi          #+#    #+#             */
/*   Updated: 2021/11/14 23:21:36 by rtakeshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	erase_images(t_game *game)
{
	mlx_destroy_image(game->mlx, game->empty);
	mlx_destroy_image(game->mlx, game->player);
	mlx_destroy_image(game->mlx, game->collectible);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->closed_exit);
	mlx_destroy_image(game->mlx, game->opened_exit);
	mlx_destroy_image(game->mlx, game->mlx_img);
}
