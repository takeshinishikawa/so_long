/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakeshi <rtakeshi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 12:06:10 by rtakeshi          #+#    #+#             */
/*   Updated: 2021/09/05 12:06:10 by rtakeshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_ptrlen(uintptr_t number)
{
	int	len;

	len = 0;
	if (number == 0)
		len = 1;
	while (number)
	{
		number /= 16;
		len++;
	}
	return (len);
}
