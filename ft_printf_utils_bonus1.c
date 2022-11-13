/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mouz <ael-mouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 23:30:15 by ael-mouz          #+#    #+#             */
/*   Updated: 2022/11/13 06:34:52 by ael-mouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	skip_flag(const char *str, char v)
{
	int	i;

	i = 0;
	while (str[i] == v)
		i++;
	return (i);
}

int	check_p_s(const char *str, char p, va_list k, va_list s)
{
	int		i;
	int		l;

	i = 0;
	if (str[i] == '+')
	{
		va_copy(s, k);
		while (str[i] == '+')
			i++;
		if ((str[i] == 'd' || str[i] == 'i')
			&& va_arg(s, int) > 0)
			ft_putchar('+');
	}
	return (i);
}

int	check_d(const char *str)
{
	int		i;
	int		l;

	i = 0;
	while (str[i] == ' ')
			i++;
	if (str[i] == '#')
	{
		while (str[i] == '#')
			i++;
		while (str[i] == ' ')
			i++;
		if (str[i] == 'x')
			ft_putstr("0x");
		else if (str[i] == 'X')
			ft_putstr("0X");
	}
	return (i);
}
