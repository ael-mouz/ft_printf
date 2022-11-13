/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mouz <ael-mouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 22:26:42 by ael-mouz          #+#    #+#             */
/*   Updated: 2022/11/13 06:34:16 by ael-mouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int		ft_putchar(int p);
int		ft_putstr(char *p);
int		ft_putnbr(long n);
int		ft_puthx(unsigned int i, char v);
int		ft_putadd(size_t i);
int		skip_flag(const char *str, char v);
int		check_p_s(const char *str, char p, va_list k, va_list s);
int		check_d(const char *str, va_list k);
int		ft_printf(const char *str, ...);

#endif