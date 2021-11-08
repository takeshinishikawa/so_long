/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nlen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakeshi <rtakeshi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 12:06:07 by rtakeshi          #+#    #+#             */
/*   Updated: 2021/09/05 12:06:07 by rtakeshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nlen(long long number)
{
	int					len;
	unsigned long long	aux;

	len = 0;
	aux = number;
	if (number == 0)
		len = 1;
	if (number < 0)
		aux = number * -1;
	while (aux)
	{
		aux /= 10;
		len++;
	}
	return (len);
}
