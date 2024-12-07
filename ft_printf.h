/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedemir <sedemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:47:31 by sedemir           #+#    #+#             */
/*   Updated: 2024/11/26 11:29:54 by sedemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_printf(const char *format, ...);
int	ft_putstr(char *str);
int	ft_putchar(int c);
int	ft_putptr(void *ptr);
int	ft_putnbr(int a);
int	ft_putunsigned(unsigned int n);
int	ft_puthex(unsigned int n, char c);
int	ft_addrs(unsigned long ptr);

#endif
