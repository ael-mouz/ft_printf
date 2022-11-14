/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 23:30:15 by ael-mouz          #+#    #+#             */
/*   Updated: 2022/11/14 12:45:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/*int	skip_flag(const char *str, char v)
{
	int	i;

	i = 0;
	while (str[i] == v)
		i++;
	return (i);
}*/

int	check_p_s(const char *str, char p, va_list k)
{
	int		i;
	int		l;
	va_list	s;

	i = 0;
	l = 0;
	if (str[i] == p)
	{
		va_copy(s, k);
		if ((str[i + 1] == 'd' || str[i + 1] == 'i')
			&& va_arg(s, int) > 0)
			l += ft_putchar(p);
	}
	return (l);
}

int	check_d(const char *str)
{
	int		i;
	int		l;

	i = 0;
	l = 0;
	if (str[i] == '#')
	{
		if (str[i + 1] == 'x')
			l += ft_putstr("0x");
		else if (str[i + 1] == 'X')
			l += ft_putstr("0X");
	}
	return (l);
}
