/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itohex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakeshi <rtakeshi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 12:04:54 by rtakeshi          #+#    #+#             */
/*   Updated: 2021/09/05 12:04:55 by rtakeshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nhexlen(unsigned int number)
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

char	*ft_itohex(char c, unsigned int n)
{
	char	*cvt_int;
	char	*base;
	size_t	len;

	len = ft_nhexlen(n);
	cvt_int = (char *)malloc((len + 1) * sizeof(char));
	if (cvt_int == NULL)
		return (NULL);
	if (c == 'x')
		base = ft_strdup("0123456789abcdef");
	else
		base = ft_strdup("0123456789ABCDEF");
	cvt_int[len] = '\0';
	len--;
	while (len)
	{
		cvt_int[len] = base[n % 16];
		n /= 16;
		len--;
	}
	cvt_int[len] = base[n % 16];
	free(base);
	return (cvt_int);
}
