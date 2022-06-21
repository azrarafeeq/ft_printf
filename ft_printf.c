/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 12:51:05 by arafeeq           #+#    #+#             */
/*   Updated: 2022/06/05 12:41:24 by arafeeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list args, const char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = ft_print_char(va_arg(args, int));
	else if (c == 's')
		len = ft_print_str(va_arg(args, char *));
	else if (c == 'p')
		len = ft_void_to_hexa(va_arg(args, unsigned long long));
	else if (c == 'i' || c == 'd')
		len = ft_print_int_decimal(va_arg(args, int));
	else if (c == 'u')
		len = ft_print_unsigned_decimal(va_arg(args, unsigned int));
	else if (c == 'x')
		len = ft_hexa_lower(va_arg(args, unsigned long));
	else if (c == 'X')
		len = ft_hexa_upper(va_arg(args, unsigned long));
	else if (c == '%')
		len = ft_print_percent();
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			len = len + ft_format(args, format[i + 1]);
			i++;
		}
		else
		{
			write(1, &format[i], 1);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}
