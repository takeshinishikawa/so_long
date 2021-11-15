/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakeshi <rtakeshi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:07:51 by rtakeshi          #+#    #+#             */
/*   Updated: 2021/11/14 23:20:59 by rtakeshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	check_map(int argc, char **argv)
{
	int		argv_len;

	if (argc != 2)
	{
		ft_printf("Error\nPlease inform only one map /folder/name.\n");
		return (-1);
	}
	argv_len = ft_strlen(argv[1]);
	if (ft_strncmp((argv[1] + argv_len - 4), ".ber", 4) != 0)
	{
		ft_printf("Error\nPlease inform only maps with '.ber' extension.\n");
		return (-1);
	}
	if (ft_strlen(argv[1] + 4) < 5)
	{
		ft_printf("Error\nPlease inform a valid map.\n");
		return (-1);
	}
	return (0);
}
