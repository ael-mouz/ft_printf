/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mouz <ael-mouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 22:25:51 by ael-mouz          #+#    #+#             */
/*   Updated: 2022/11/13 06:33:50 by ael-mouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <stdio.h>

static	int	ft_check(char str, va_list p)
{
	int		count;
	va_list	s;

	count = 0;
	if (str == 'c')
		count += ft_putchar(va_arg(p, int));
	else if (str == 's')
		count += ft_putstr(va_arg(p, char *));
	else if (str == 'u')
		count += ft_putnbr(va_arg(p, unsigned int));
	else if (str == 'd' || str == 'i')
		count += ft_putnbr(va_arg(p, int));
	else if (str == 'x' || str == 'X')
		count += ft_puthx(va_arg(p, unsigned int), str);
	else if (str == 'p')
	{
		count += ft_putstr("0x");
		count += ft_putadd(va_arg(p, size_t));
	}
	else if (str == '%')
		count += ft_putchar('%');
	else
		count += ft_putchar(str);
	return (count);
}

static	int	check_flag(const char *str, va_list k, va_list s)
{
	int	i;

	i = 0;
	i += check_d(&str[i], k);
	i += check_p_s(&str[i], ' ', k, s);
	i += check_p_s(&str[i], '+', k, s);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	p;
	va_list	s;
	int		i;
	int		l;

	i = 0;
	l = 0;
	if (write(1, 0, 0) == -1)
		return (-1);
	va_start(p, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '\0')
				break ;
			i += check_flag(&str[i +1], p, s);
			l += ft_check(str[++i], p);
		}
		else
			l += write(1, &str[i], 1);
		i++;
	}
	va_end(p);
	return (l);
}
