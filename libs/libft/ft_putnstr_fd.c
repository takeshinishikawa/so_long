/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakeshi <rtakeshi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 12:06:33 by rtakeshi          #+#    #+#             */
/*   Updated: 2021/09/05 12:06:33 by rtakeshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnstr_fd(char *s, int size, int fd)
{
	int	counter;

	counter = 0;
	if (s == NULL)
		return ;
	while (*s && counter < size)
	{
		ft_putchar_fd(*s, fd);
		s++;
		counter++;
	}
}
