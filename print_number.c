/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 11:57:02 by arafeeq           #+#    #+#             */
/*   Updated: 2022/06/05 12:07:35 by arafeeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	return (write (1, &c, 1));
}

int	num_len(int num)
{
	int	count;

	count = 0;
	if (num < 0)
	{
		count++;
		num *= -1;
	}
	if (num == 0)
		count = 1;
	while (num != 0)
	{
		num = num / 10;
		count++;
	}
	return (count);
}

int	ft_print_int_decimal(int num)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (num == 0)
		return (write (1, "0", 1));
	if (num == -2147483648)
		return (write (1, "-2147483648", 11));
	if (num < 0)
	{
		write(1, "-", 1);
		num = num * -1;
		len = 1;
	}
	len += num_len(num);
	if (num != 0)
	{
		i = num % 10 + '0';
		num = num / 10;
		if (num != 0)
			ft_print_int_decimal(num);
	}
	write(1, &i, 1);
	return (len);
}

int	ft_print_unsigned_decimal(unsigned int num)
{
	int	len;

	len = 0;
	if (num >= 10)
		len += ft_print_int_decimal(num / 10);
	len += ft_putchar(num % 10 + 48);
	return (len);
}
