/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedemir <sedemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:23:20 by sedemir           #+#    #+#             */
/*   Updated: 2024/11/25 16:40:24 by sedemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	while (str[i])
	{
		if (write(1, &str[i], 1) == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_putunsigned(unsigned int n)
{
	int	ret;

	ret = 0;
	if (n >= 10)
		ret += ft_putunsigned(n / 10);
	if (write(1, &"0123456789"[n % 10], 1) == -1)
		return (-1);
	return (ret + 1);
}

int	ft_puthex(unsigned int n, char c)
{
	int	ret;

	ret = 0;
	if (n >= 16)
		ret += ft_puthex(n / 16, c);
	if (c == 'x')
	{
		if (write(1, &"0123456789abcdef"[n % 16], 1) == -1)
			return (-1);
	}
	else if (c == 'X')
	{
		if (write(1, &"0123456789ABCDEF"[n % 16], 1) == -1)
			return (-1);
	}
	return (ret + 1);
}

int	ft_addrs(unsigned long ptr)
{
	int	ret ;

	ret = 0;
	if (ptr >= 16)
		ret += ft_addrs(ptr / 16);
	if (write(1, &"0123456789abcdef"[ptr % 16], 1) == -1)
		return (-1);
	return (ret + 1);
}

int	ft_putptr(void *ptr)
{
	int	len;
	int	aux;

	len = 0;
	aux = 0;
	if (ptr == NULL)
		return (write(1, "(nil)", 5));
	if (ft_putstr("0x") == -1)
		return (-1);
	len += 2;
	aux = ft_addrs((unsigned long)ptr);
	if (aux == -1)
		return (-1);
	len += aux;
	return (len);
}
