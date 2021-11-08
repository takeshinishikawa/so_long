/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakeshi <rtakeshi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:07:51 by rtakeshi          #+#    #+#             */
/*   Updated: 2021/11/03 16:08:45 by rtakeshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(int argc, char **argv)
{
	int		argv_len;

	//argc must not be !=2
	if (argc != 2)
	{
		ft_printf("Please inform only one map /folder/name.\n");
		return (-1);
	}
	//argv[1] must end with ".ber"
	argv_len = ft_strlen(argv[1]);
	ft_printf("%s\n", (argv[1] + 4)); //remove
	if (ft_strncmp((argv[1] + argv_len - 4), ".ber", 4) != 0)
	{
		ft_printf("Please inform only maps with '.ber' extension.\n");
		return (-1);
	}
	//argv[1] must have at least 5 characters "x.ber"
	if (ft_strlen(argv[1] + 4) < 5)
	{
		ft_printf("Please inform a valid map.\n");
		return (-1);
	}
	return (0);
}
