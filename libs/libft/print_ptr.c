/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakeshi <rtakeshi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 11:58:56 by rtakeshi          #+#    #+#             */
/*   Updated: 2021/10/31 13:45:59 by rtakeshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_ptr(t_option *str, va_list arg)
{
	uintptr_t	ptr;
	char		*aux_str;

	ptr = va_arg(arg, uintptr_t);
	aux_str = ft_ptrtohex(ptr);
	str->str_len = ft_strlen(aux_str);
	if (str->width > (int)str->str_len)
	{
		if (str->minus == 1)
		{
			ft_putstr_fd(aux_str, 1);
			ft_putnchar_fd(' ', (str->width - str->str_len), 1);
			free(aux_str);
			return (str->width);
		}
		else if (str->zero == 1)
			ft_putnchar_fd('0', (str->width - str->str_len), 1);
		else
			ft_putnchar_fd(' ', (str->width - str->str_len), 1);
		str->str_len = str->width;
	}
	ft_putstr_fd(aux_str, 1);
	free(aux_str);
	return (str->str_len);
}
