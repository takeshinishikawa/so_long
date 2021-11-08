/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakeshi <rtakeshi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 12:06:24 by rtakeshi          #+#    #+#             */
/*   Updated: 2021/09/05 12:06:24 by rtakeshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	nbr;

	if (n < 0)
	{
		if (n == -2147483648)
		{
			ft_putchar_fd('2', fd);
			n = -147483648;
		}
		nbr = n * (-1);
	}
	else
		nbr = n;
	while ((nbr >= 10))
	{
		ft_putnbr_fd((nbr / 10), fd);
		nbr = nbr - (nbr / 10) * 10;
	}
	ft_putchar_fd(((nbr % 10) + '0'), fd);
}
