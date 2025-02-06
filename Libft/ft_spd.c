/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:27:41 by gyildiz           #+#    #+#             */
/*   Updated: 2025/02/06 18:37:01 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

int	ft_string(char *s)
{
	int	printed;
	int	i;

	printed = 0;
	if (!s)
	{
		printed += write(1, NUL, WRITTEN);
		return (printed);
	}
	i = 0;
	while (s[i])
	{
		printed += write(1, (s + i), 1);
		i++;
	}
	return (printed);
}

int	ft_pointer(unsigned long long n, int first_call)
{
	int		printed;
	char	*hexadec;

	printed = 0;
	hexadec = "0123456789abcdef";
	if (first_call && n == 0)
	{
		printed += write(1, NL, WRT);
		return (printed);
	}
	if (first_call)
	{
		printed += write(1, "0x", 2);
	}
	if (n > 15)
	{
		printed += ft_pointer(n / 16, 0);
		printed += ft_pointer(n % 16, 0);
	}
	else
	{
		printed += write(1, (hexadec + n), 1);
	}
	return (printed);
}

int	ft_pointercast(void *ptr)
{
	unsigned long long	n;
	int					printed;

	printed = 0;
	n = (unsigned long long)ptr;
	printed += ft_pointer(n, 1);
	return (printed);
}

int	ft_decint(int di)
{
	int		printed;
	int		i;
	char	*decint;

	printed = 0;
	i = 0;
	decint = ft_itoa(di);
	while (decint[i])
	{
		printed += write(1, (decint + i), 1);
		i++;
	}
	free(decint);
	return (printed);
}
