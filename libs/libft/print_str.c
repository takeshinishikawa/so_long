/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakeshi <rtakeshi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 11:59:01 by rtakeshi          #+#    #+#             */
/*   Updated: 2021/10/31 13:46:03 by rtakeshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*str_data(char *c_str, t_option *str, va_list arg)
{
	c_str = va_arg(arg, char *);
	if (c_str == NULL)
		c_str = "(null)";
	str->str_len = ft_strlen(c_str);
	return (c_str);
}

char	*check_str(char *str)
{
	if (str == NULL)
		str = "(null)";
	return (str);
}

int	print_str(t_option *str, va_list arg)
{
	char	*str_aux;

	str_aux = va_arg(arg, char *);
	str_aux = check_str(str_aux);
	str->str_len = ft_strlen(str_aux);
	if (str->precision == -1)
		str->precision = (int)str->str_len;
	if (str->dot && str->precision < (int)str->str_len)
		str->str_len = str->precision;
	if (str->width > (int) str->str_len)
	{
		if (str->minus == 1)
		{
			ft_putnstr_fd(str_aux, str->str_len, 1);
			ft_putnchar_fd(' ', str->width - str->str_len, 1);
			return (str->width);
		}
		else if (str->zero == 1)
			ft_putnchar_fd('0', str->width - str->str_len, 1);
		else
			ft_putnchar_fd(' ', str->width - str->str_len, 1);
		str->str_len = str->width;
	}
	ft_putnstr_fd(str_aux, str->str_len, 1);
	return (str->str_len);
}
