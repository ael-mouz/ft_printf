/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:38:19 by ael-mouz          #+#    #+#             */
/*   Updated: 2022/11/14 12:45:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int p)
{
	write(1, &p, 1);
	return (1);
}

int	ft_putstr(char *p)
{
	int	i;

	i = 0;
	if (!p)
		return (ft_putstr("(null)"));
	while (p[i])
	{
		write(1, &p[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(long n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		count += ft_putstr("-2147483648");
	else if (n < 0)
	{
		count += ft_putchar('-');
		count += ft_putnbr(-n);
	}
	else if (n <= 9)
		count += ft_putchar((n + 48));
	else
	{
		count += ft_putnbr((n / 10));
		count += ft_putchar((n % 10));
	}
	return (count);
}

int	ft_puthx(unsigned int i, char v)
{
	char	*base;
	char	*base1;
	int		count;

	base = "0123456789abcdef";
	base1 = "0123456789ABCDEF";
	count = 0;
	if (i < 16)
	{
		if (v == 'x')
			count += ft_putchar(base[i]);
		else
			count += ft_putchar(base1[i]);
	}
	else
	{
		count += ft_puthx(i / 16, v);
		count += ft_puthx(i % 16, v);
	}
	return (count);
}

int	ft_putadd(size_t i)
{
	char	*base;
	int		count;

	base = "0123456789abcdef";
	count = 0;
	if (i < 16)
		count += ft_putchar(base[i]);
	else
	{
		count += ft_putadd(i / 16);
		count += ft_putadd(i % 16);
	}
	return (count);
}
