/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrtohex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakeshi <rtakeshi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 12:06:13 by rtakeshi          #+#    #+#             */
/*   Updated: 2021/09/05 12:06:14 by rtakeshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ptrtohex(uintptr_t n)
{
	char	*cvt_hex;
	char	*base;
	size_t	len;

	len = ft_ptrlen(n) + 2;
	cvt_hex = (char *)malloc((len + 1) * sizeof(char));
	if (cvt_hex == NULL)
		return (NULL);
	base = ft_strdup("0123456789abcdef");
	cvt_hex[len] = '\0';
	len--;
	while ((n / 16) != 0)
	{
		cvt_hex[len] = base[n % 16];
		n /= 16;
		len--;
	}
	cvt_hex[len] = base[n % 16];
	cvt_hex[1] = 'x';
	cvt_hex[0] = '0';
	free(base);
	return (cvt_hex);
}
