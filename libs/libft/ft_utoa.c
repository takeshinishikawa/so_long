/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakeshi <rtakeshi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 12:07:42 by rtakeshi          #+#    #+#             */
/*   Updated: 2021/09/05 12:07:42 by rtakeshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_utoa(unsigned int n)
{
	char	*cvt_int;
	size_t	len;

	len = ft_unlen(n);
	cvt_int = (char *)malloc((len + 1) * sizeof(char));
	if (cvt_int == NULL)
		return (NULL);
	cvt_int[len] = '\0';
	len--;
	while (n != 0)
	{
		cvt_int[len] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	if (len == 0 && cvt_int[1] == '\0')
		cvt_int[len] = '0';
	return (cvt_int);
}
