/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjoo <yjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:09:40 by yjoo              #+#    #+#             */
/*   Updated: 2022/01/21 14:09:40 by yjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_print_ptr(unsigned long long ptr);
int	ft_print_char(const char c);
int	ft_print_str(const char *str);
int	ft_print_unbr(unsigned int nbr);
int	ft_print_hex(unsigned int num, const char format);
int	ft_print_nbr(int nbr);

#endif
