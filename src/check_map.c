/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakeshi <rtakeshi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:07:51 by rtakeshi          #+#    #+#             */
/*   Updated: 2021/11/15 12:50:52 by rtakeshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	check_map(int argc, char **argv)
{
	int		argv_len;

	if (argc != 2)
	{
		ft_printf("Error\nPlease inform only ./so_long 'map_file'.\n");
		return (-1);
	}
	argv_len = ft_strlen(argv[1]);
	if (ft_strncmp((argv[1] + argv_len - 4), ".ber", 4) != 0)
	{
		ft_printf("Error\nGame accepts only maps with '.ber' extension.\n");
		return (-1);
	}
	return (0);
}
