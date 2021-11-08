/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakeshi <rtakeshi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 12:04:24 by rtakeshi          #+#    #+#             */
/*   Updated: 2021/09/05 12:04:24 by rtakeshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_hexlen(unsigned int number)
{
	int	count;

	count = 0;
	if (number == 0)
		count = 1;
	while (number)
	{
		number /= 16;
		count++;
	}
	return (count);
}
