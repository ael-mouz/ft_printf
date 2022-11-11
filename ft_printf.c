/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mouz <ael-mouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:28:10 by ael-mouz          #+#    #+#             */
/*   Updated: 2022/11/11 01:44:08 by ael-mouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_check(char str, va_list p)
{
	int	count;

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
			l += ft_check(str[++i], p);
		}
		else
			l += write(1, &str[i], 1);
		i++;
	}
	va_end(p);
	return (l);
}
