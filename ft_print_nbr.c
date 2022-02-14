/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjoo <yjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:00:06 by yjoo              #+#    #+#             */
/*   Updated: 2022/02/14 14:00:06 by yjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_ulen(unsigned int nbr)
{
	int	len;

	len = 0;
	while (nbr != 0)
	{
		len++;
		nbr = nbr / 10;
	}
	return (len);
}

char	*ft_convert_uint(unsigned int nbr)
{
	int		nbr_len;
	char	*nbr_str;

	nbr_len = ft_ulen(nbr);
	nbr_str = (char *)ft_calloc(nbr_len + 1, sizeof(char));
	if (!nbr_str)
		return (NULL);
	while (nbr_len--)
	{
		nbr_str[nbr_len] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	return (nbr_str);
}

int	ft_print_unbr(unsigned int nbr)
{
	int		length;
	char	*unbr_str;

	if (nbr == 0)
	{
		length = ft_print_char('0');
		return (length);
	}
	unbr_str = ft_convert_uint(nbr);
	length = ft_print_str(unbr_str);
	free(unbr_str);
	return (length);
}

int	ft_print_nbr(int nbr)
{
	int		length;
	char	*nbr_str;

	nbr_str = ft_itoa(nbr);
	length = ft_print_str(nbr_str);
	free(nbr_str);
	return (length);
}
