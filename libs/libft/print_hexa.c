/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakeshi <rtakeshi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 11:58:46 by rtakeshi          #+#    #+#             */
/*   Updated: 2021/10/31 13:45:51 by rtakeshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	has_hash(t_option *str, char *aux_str)
{
	if (str->hash && aux_str[0] != '0')
	{
		write (1, "0", 1);
		if (str->type == 'x')
			write (1, "x", 1);
		else
			write (1, "X", 1);
		return (2);
	}
	return (0);
}

int	print_hex(t_option	*str, char *aux_str)
{
	int	size;

	size = ft_strlen(aux_str);
	if (str->dot && !str->precision && aux_str[0] == '0')
	{
		free (aux_str);
		return (0);
	}
	if (has_hash(str, aux_str) && aux_str[0] != '0')
		if (!str->dot)
			size += 2;
	if (size < str->precision)
		ft_putnchar_fd('0', str->precision - size, 1);
	ft_putstr_fd(aux_str, 1);
	free(aux_str);
	return (str->str_len);
}

void	check_hash(unsigned int unbr, t_option *str)
{
	if (str->hash && unbr)
		str->str_len += 2;
}

int	print_hexa(t_option *str, va_list arg)
{
	unsigned int	unbr;
	char			*aux_str;

	unbr = va_arg(arg, unsigned int);
	aux_str = ft_itohex(str->type, unbr);
	str->str_len = ft_strlen(aux_str);
	if ((str->dot && !unbr) || (str->precision > (int)str->str_len))
		str->str_len = str->precision;
	check_hash(unbr, str);
	if (str->width > (int)str->str_len)
	{
		if (str->minus == 1)
		{
			print_hex(str, aux_str);
			ft_putnchar_fd(' ', str->width - str->str_len, 1);
			return (str->width);
		}
		else if (str->zero != 0 && str->dot == 0)
			str->precision = str->width;
		else
			ft_putnchar_fd(' ', str->width - str->str_len, 1);
		str->str_len = str->width;
	}
	print_hex(str, aux_str);
	return (str->str_len);
}
