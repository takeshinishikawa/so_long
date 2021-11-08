/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakeshi <rtakeshi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 12:07:22 by rtakeshi          #+#    #+#             */
/*   Updated: 2021/09/05 12:07:23 by rtakeshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	counter;
	size_t	needle;
	size_t	s_size;

	counter = 0;
	needle = 0;
	if (s == NULL)
		return (NULL);
	s_size = ft_strlen(s);
	while (start < s_size && counter < len && s[start + counter] != '\0')
		counter++;
	substr = malloc(sizeof(char) * (counter + 1));
	if (substr == NULL)
		return (NULL);
	while (needle < counter)
	{
		substr[needle] = s[start + needle];
		needle++;
	}
	substr[needle] = '\0';
	return (substr);
}
