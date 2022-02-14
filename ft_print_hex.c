/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjoo <yjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:21:37 by yjoo              #+#    #+#             */
/*   Updated: 2022/02/11 17:21:37 by yjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_hexlen(unsigned long long num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

char	*ft_convert_hex(unsigned long long num, const char format)
{
	int		num_len;
	char	*hex_str;

	num_len = 0;
	if (format == 'p')
		num_len = ft_hexlen(num);
	else if (format == 'x' || format == 'X')
		num_len = ft_hexlen((unsigned int)num);
	hex_str = (char *)ft_calloc(num_len + 1, sizeof(char));
	if (!hex_str)
		return (NULL);
	while (num_len--)
	{
		if (num % 16 > 9)
			hex_str[num_len] = (num % 16) - 10 + 'a';
		else
			hex_str[num_len] = (num % 16) + '0';
		num = num / 16;
	}
	return (hex_str);
}

int	ft_print_ptr(unsigned long long ptr)
{
	int		length;
	char	*ptr_str;

	ptr_str = NULL;
	length = write(1, "0x", 2);
	if (!ptr)
		length += ft_print_char('0');
	else
	{
		ptr_str = ft_convert_hex(ptr, 'p');
		length += ft_print_str(ptr_str);
	}
	free(ptr_str);
	return (length);
}

int	ft_print_hex(unsigned int num, const char format)
{
	int		length;
	int		i;
	char	*hex_str;

	hex_str = NULL;
	if (!num)
		length = ft_print_char('0');
	else
	{
		hex_str = ft_convert_hex(num, format);
		if (format == 'X')
		{
			i = 0;
			while (hex_str[i])
			{
				hex_str[i] = ft_toupper(hex_str[i]);
				i++;
			}
		}
		length = ft_print_str(hex_str);
	}
	free(hex_str);
	return (length);
}
