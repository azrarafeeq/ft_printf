/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 10:31:54 by arafeeq           #+#    #+#             */
/*   Updated: 2022/06/05 12:07:28 by arafeeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_print_char(int c);
int		ft_print_str(char *str);
int		ft_print_percent(void);

int		ft_hexa_lower(unsigned int num);
int		ft_hexa_upper(unsigned int num);
int		hexa_len(unsigned long long num);
void	ft_print_hexa(unsigned long long num);
int		ft_void_to_hexa(unsigned long long num);

int		ft_print_int_decimal(int n);
int		ft_print_unsigned_decimal(unsigned int num);

#endif