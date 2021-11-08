/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakeshi <rtakeshi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 11:58:50 by rtakeshi          #+#    #+#             */
/*   Updated: 2021/10/31 13:45:55 by rtakeshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putunbr_fd(unsigned int n, int fd)
{
	if (n == 2147483648)
	{
		ft_putchar_fd('2', fd);
		n = 147483648;
	}
	while ((n >= 10))
	{
		ft_putnbr_fd((n / 10), fd);
		n = n - (n / 10) * 10;
	}
	ft_putchar_fd(((n % 10) + '0'), fd);
}

int	print_nbr(t_option	*str, int nbr)
{
	int	size;

	size = ft_nlen((long long)nbr);
	if (nbr < 0)
	{
		ft_putchar_fd('-', 1);
		if (str->dot == 0)
			size++;
	}
	else
	{
		if (str->plus)
			ft_putchar_fd('+', 1);
		if (str->space)
			ft_putchar_fd(' ', 1);
		if (str->dot && (str->plus || str->space))
			size++;
	}
	if (str->dot && str->precision == 0 && nbr == 0)
		return (0);
	if (size < str->precision)
		ft_putnchar_fd('0', str->precision - size, 1);
	ft_putnbr_fd(nbr, 1);
	return (size);
}

int	print_int(t_option *str, va_list arg)
{
	int		nbr;

	nbr = va_arg(arg, int);
	str->str_len = (size_t)ft_nlen((long long)nbr);
	if (str->precision > (int)str->str_len || (str->dot && !nbr))
		str->str_len = str->precision;
	if (str->space || str-> plus || nbr < 0)
		str->str_len++;
	if (str->width > (int)str->str_len)
	{
		if (str->minus)
		{
			print_nbr(str, nbr);
			ft_putnchar_fd(' ', str->width - str->str_len, 1);
			return (str->width);
		}
		else if (str->zero != 0 && str->dot == 0)
			str->precision += str->width;
		else
			ft_putnchar_fd(' ', str->width - str->str_len, 1);
		str->str_len = str->width;
	}
	print_nbr(str, nbr);
	return (str->str_len);
}
