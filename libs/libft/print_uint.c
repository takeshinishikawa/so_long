/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakeshi <rtakeshi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 11:59:05 by rtakeshi          #+#    #+#             */
/*   Updated: 2021/10/31 13:46:07 by rtakeshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_uint(t_option *str, char *aux_str)
{
	int	size;

	size = ft_strlen(aux_str);
	if (str->dot && str->precision == 0 && aux_str[0] == '0')
		return (0);
	if (size < str->precision)
		ft_putnchar_fd('0', str->precision - size, 1);
	ft_putstr_fd(aux_str, 1);
	return (str->str_len);
}

void	check_uformat(unsigned int unbr, t_option *str)
{
	if (str->precision > (int)str->str_len || (str->dot && !unbr))
		str->str_len = str->precision;
}

int	print_unsigned(t_option *str, va_list arg)
{
	unsigned int	unbr;
	char			*aux_str;

	unbr = va_arg(arg, unsigned int);
	aux_str = ft_utoa(unbr);
	str->str_len = ft_unlen(unbr);
	check_uformat(unbr, str);
	if (str->width > (int)str->str_len)
	{
		if (str->minus == 1)
		{
			print_uint(str, aux_str);
			ft_putnchar_fd(' ', str->width - str->str_len, 1);
			free(aux_str);
			return (str->width);
		}
		else if (str->zero && !str->dot)
			ft_putnchar_fd('0', str->width - str->str_len, 1);
		else
			ft_putnchar_fd(' ', str->width - str->str_len, 1);
		str->str_len = str->width;
	}
	print_uint(str, aux_str);
	free(aux_str);
	return (str->str_len);
}
