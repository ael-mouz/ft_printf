/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mouz <ael-mouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 23:30:15 by ael-mouz          #+#    #+#             */
/*   Updated: 2022/11/14 19:49:22 by ael-mouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	check_p_s(const char *str, char p, va_list k, int *l)
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

int	check_d(const char *str, va_list k, int *l)
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
