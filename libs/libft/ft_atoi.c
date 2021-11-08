/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakeshi <rtakeshi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 12:04:11 by rtakeshi          #+#    #+#             */
/*   Updated: 2021/09/05 12:04:14 by rtakeshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\r'
		|| c == '\f' || c == '\v')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	long int	num;
	int			signal;

	num = 0;
	signal = 1;
	while ((ft_isspace(*str)))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			signal *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (num * signal >= LONG_MAX / 10 && (*str - '0') > LONG_MAX % 10)
			return ((int)LONG_MAX);
		else if (num * signal <= LONG_MIN / 10
			 && (*str - '0') > -(LONG_MIN % 10))
			return ((int)LONG_MIN);
		num = (num * 10) + (*str - '0');
		str++;
	}
	return ((int)num * signal);
}
