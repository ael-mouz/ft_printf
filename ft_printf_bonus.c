/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mouz <ael-mouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 22:25:51 by ael-mouz          #+#    #+#             */
/*   Updated: 2022/11/14 20:07:54 by ael-mouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static	int	ft_check(char str, va_list p)
{
	int		count;

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
	return (count);
}

static	int	check_p_s(const char *str, char p, va_list k, int *l)
{
	int		i;
	va_list	s;

	i = 0;
	va_copy(s, k);
	if (str[i] == p)
	{
		while (str[i] == p)
			i++;
		if ((str[i] == 'd' || str[i] == 'i')
			&& va_arg(s, int) >= 0)
			(*l) += ft_putchar(p);
	}
	return (i);
}

static	int	check_d(const char *str, va_list k, int *l)
{
	int		i;
	va_list	s;

	i = 0;
	va_copy(s, k);
	if (str[i] == '#')
	{
		while (str[i] == '#')
			i++;
		if (va_arg(s, unsigned int) != 0)
		{
			if (str[i] == 'x')
				(*l) += ft_putstr("0x");
			else if (str[i] == 'X')
				(*l) += ft_putstr("0X");
		}
	}
	return (i);
}

static	int	check_flag(const char *str, va_list k, int *l)
{
	int	i;

	i = 0;
	if (str[0] == '#')
		i += check_d(&str[i], k, l);
	else if (str[0] == ' ')
		i += check_p_s(&str[i], ' ', k, l);
	else if (str[0] == '+')
		i += check_p_s(&str[i], '+', k, l);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	p;
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
			if (str[i + 1] == ' ' || str[i + 1] == '+' || str[i + 1] == '#')
				i += check_flag(&str[i + 1], p, &l);
			l += ft_check(str[++i], p);
		}
		else
			l += write(1, &str[i], 1);
		i++;
	}
	va_end(p);
	return (l);
}
