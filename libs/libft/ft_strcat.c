/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakeshi <rtakeshi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 12:06:56 by rtakeshi          #+#    #+#             */
/*   Updated: 2021/11/06 17:25:55 by rtakeshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcat(char *dst, const char *src)
{
	size_t	counter;
	size_t	src_size;
	size_t	dst_size;

	counter = 0;
	src_size = ft_strlen(src);
	dst_size = ft_strlen(dst);
	while (dst[counter])
		counter++;
	while (*src && (counter < dst_size + src_size))
	{
		dst[counter++] = *(src++);
	}
	dst[counter] = '\0';
	return (dst_size + src_size);
}
