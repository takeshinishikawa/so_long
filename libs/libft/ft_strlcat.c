/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakeshi <rtakeshi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 12:06:56 by rtakeshi          #+#    #+#             */
/*   Updated: 2021/09/05 12:06:57 by rtakeshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	counter;
	size_t	src_size;
	size_t	dst_size;

	counter = 0;
	src_size = ft_strlen(src);
	dst_size = ft_strlen(dst);
	if (dstsize <= dst_size)
		return (dstsize + src_size);
	while (dst[counter])
		counter++;
	while (*src && (counter + 1 < dstsize))
	{
		dst[counter++] = *(src++);
	}
	dst[counter] = '\0';
	return (dst_size + src_size);
}
