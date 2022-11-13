/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mouz <ael-mouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:28:15 by ael-mouz          #+#    #+#             */
/*   Updated: 2022/11/12 20:41:04 by ael-mouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int		ft_putchar(int p);
int		ft_putstr(char *p);
int		ft_putnbr(long n);
int		ft_puthx(unsigned int i, char v);
int		ft_putadd(size_t i);
int		ft_printf(const char *str, ...);

#endif