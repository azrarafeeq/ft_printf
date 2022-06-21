/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 11:53:15 by arafeeq           #+#    #+#             */
/*   Updated: 2022/06/05 12:07:31 by arafeeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hexa_len(unsigned long long num)
{
	int	count;

	count = 0;
	while (num != 0)
	{
		num = num / 16;
		count++;
	}
	return (count);
}

void	ft_print_hexa(unsigned long long num)
{
	int	i;

	if (num != 0)
	{
		i = num % 16;
		num = num / 16;
		if (i >= 10)
			i = 97 + (i - 10);
		else
			i = i + '0';
		if (num != 0)
			ft_print_hexa(num);
	}
	write(1, &i, 1);
}

int	ft_hexa_lower(unsigned int num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (write(1, "0", 1));
	len = hexa_len(num);
	ft_print_hexa(num);
	return (len);
}

int	ft_hexa_upper(unsigned int num)
{
	int	len;
	int	i;

	len = 0;
	if (num == 0)
		return (write(1, "0", 1));
	len = hexa_len(num);
	if (num != 0)
	{
		i = num % 16;
		num = num / 16;
		if (i >= 10)
			i = 65 + (i - 10);
		else
			i = i + '0';
		if (num != 0)
			ft_hexa_upper(num);
	}
	write(1, &i, 1);
	return (len);
}

int	ft_void_to_hexa(unsigned long long num)
{
	int	len;

	len = hexa_len(num);
	write(1, "0x", 2);
	if (num == 0)
	{
		write(1, "0", 1);
		return (3);
	}
	ft_print_hexa(num);
	return (len + 2);
}
