/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverthex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakeshi <rtakeshi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 12:06:40 by rtakeshi          #+#    #+#             */
/*   Updated: 2021/09/05 12:06:40 by rtakeshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_reverthex(char *hex)
{
	size_t	len;
	size_t	needle;
	char	*temp;

	len = ft_strlen(hex);
	temp = (char *)malloc((len + 1) * sizeof(char));
	if (temp == NULL)
		return (NULL);
	needle = 0;
	while (len > 0)
	{
		temp[needle] = hex[len - 1];
		needle++;
		len--;
	}
	temp[needle] = '\0';
	free(hex);
	return (temp);
}
