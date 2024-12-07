/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedemir <sedemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:31:59 by sedemir           #+#    #+#             */
/*   Updated: 2024/11/26 11:30:20 by sedemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdarg.h>

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putnbr(int a)
{
	int	ret;

	ret = 0;
	if (a == 0)
		return (write(1, "0", 1));
	if (a == -2147483648)
		return (write(1, "-2147483648", 11));
	if (a < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		ret += 1;
		a *= -1;
	}
	if (a >= 10)
		ret += ft_putnbr(a / 10);
	if (write(1, &"0123456789"[a % 10], 1) == -1)
		return (-1);
	return (ret + 1);
}

static int	ft_formats(va_list arg, const char frm)
{
	int	p_len;

	p_len = 0;
	if (frm == 'c')
		return (p_len += ft_putchar(va_arg(arg, int)));
	else if (frm == 's')
		return (p_len += ft_putstr(va_arg(arg, char *)));
	else if (frm == 'p')
		return (p_len += ft_putptr((va_arg(arg, void *))));
	else if (frm == 'd' || frm == 'i')
		return (p_len += ft_putnbr(va_arg(arg, int)));
	else if (frm == 'u')
		return (p_len += ft_putunsigned(va_arg(arg, unsigned int)));
	else if (frm == 'x' || frm == 'X')
		return (p_len += ft_puthex(va_arg(arg, unsigned int), frm));
	else if (frm == '%')
		return (p_len += ft_putchar('%'));
	else
		return (-1);
}

int	ft_printf(const char *format, ...)
{
	int		p_len;
	va_list	arg;

	if (!format)
		return (-1);
	p_len = 0;
	va_start(arg, format);
	while (*format)
	{
		if (*format == '%')
		{
			p_len += ft_formats(arg, *(++format));
			if (p_len == -1)
				return (-1);
		}
		else
		{
			if (write(1, format, 1) == -1)
				return (-1);
			p_len++;
		}
		format++;
	}
	return (va_end(arg), p_len);
}
