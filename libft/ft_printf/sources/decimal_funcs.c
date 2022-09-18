/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:41:17 by muganiev          #+#    #+#             */
/*   Updated: 2022/09/18 15:41:19 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_putnbr(int n)
{
	int	n_count;

	n_count = 1;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		n_count++;
		n = -n;
	}
	if (n > 9)
		n_count += ft_putnbr(n / 10);
	ft_putchar_fd(n % 10 + '0', 1);
	return (n_count);
}

static int	ft_putunbr(unsigned int n)
{
	int	n_count;

	n_count = 1;
	if (n > 9)
		n_count += ft_putunbr(n / 10);
	ft_putchar_fd(n % 10 + '0', 1);
	return (n_count);
}

int	print_int(va_list args)
{
	int	n;
	int	n_count;

	n = va_arg(args, int);
	n_count = ft_putnbr(n);
	return (n_count);
}

int	print_uint(va_list args)
{
	unsigned int	n;
	int				n_count;

	n = va_arg(args, unsigned int);
	n_count = ft_putunbr(n);
	return (n_count);
}
