/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakeshi <rtakeshi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 11:58:23 by rtakeshi          #+#    #+#             */
/*   Updated: 2021/10/31 13:45:26 by rtakeshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	init_struct(t_option *options)
{
	options->minus = 0;
	options->zero = 0;
	options->width = 0;
	options->dot = 0;
	options->precision = 0;
	options->hash = 0;
	options->space = 0;
	options->plus = 0;
	options->type = 0;
	options->str_len = 0;
	options->negative = 0;
	options->option_offset = 0;
}

int	ft_printtype(char type, t_option *str, va_list *arg)
{
	if (type == 'c' || type == '%')
		str->str_len = print_char(str, *arg);
	else if (type == 'd' || type == 'i')
		str->str_len = print_int(str, *arg);
	else if (type == 'x' || type == 'X')
		str->str_len = print_hexa(str, *arg);
	else if (type == 'p')
		str->str_len = print_ptr(str, *arg);
	else if (type == 'u')
		str->str_len = print_unsigned(str, *arg);
	else
		str->str_len = print_str(str, *arg);
	return (str->str_len);
}

int	ft_printf(const char *format, ...)
{
	int			n_chars;
	va_list		arg;
	t_option	options;

	n_chars = 0;
	va_start(arg, format);
	while (*format != '\0')
	{
		while (*format != '%' && *format)
		{
			ft_putchar_fd(*format, 1);
			format++;
			n_chars++;
		}
		if (*format == '\0')
			break ;
		format++;
		ft_get_option(format, &arg, &options);
		format += options.option_offset;
		n_chars += options.str_len;
		format++;
	}
	return (n_chars);
}
