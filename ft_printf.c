/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjoo <yjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:30:21 by yjoo              #+#    #+#             */
/*   Updated: 2022/01/21 16:30:21 by yjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_print_char(const char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_str(const char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		i += write(1, "(null)", 6);
		return (i);
	}
	while (str[i])
		write(1, &str[i++], 1);
	return (i);
}

int	check_format(const char format, va_list ap)
{
	int	length;

	length = 0;
	if (format == 'c')
		length = ft_print_char(va_arg(ap, int));
	else if (format == 's')
		length = ft_print_str(va_arg(ap, char *));
	else if (format == 'p')
		length = ft_print_ptr(va_arg(ap, unsigned long long));
	else if (format == 'i' || format == 'd')
		length = ft_print_nbr(va_arg(ap, int));
	else if (format == 'u')
		length = ft_print_unbr(va_arg(ap, unsigned int));
	else if (format == 'x' || format == 'X')
		length = ft_print_hex(va_arg(ap, unsigned int), format);
	else if (format == '%')
		length = ft_print_char('%');
	return (length);
}

int	ft_printf(const char *format, ...)
{
	int		length;
	int		i;
	va_list	ap;

	i = 0;
	length = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			length += check_format(format[i + 1], ap);
			i++;
		}
		else
			length += ft_print_char(format[i]);
		i++;
	}
	va_end(ap);
	return (length);
}
