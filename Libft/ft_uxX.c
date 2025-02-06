/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uxX.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:28:19 by gyildiz           #+#    #+#             */
/*   Updated: 2025/02/06 18:35:45 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

static int	unum_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static char	*uft_itoa(unsigned int n)
{
	char	*intstr;
	int		len;
	long	num;

	len = unum_len(n);
	intstr = (char *)malloc(sizeof(char) * (len + 1));
	if (!intstr)
		return (NULL);
	intstr[len] = '\0';
	num = n;
	if (num == 0)
		intstr[0] = '0';
	while (num > 0)
	{
		len--;
		intstr[len] = (num % 10) + 48;
		num = num / 10;
	}
	return (intstr);
}

int	ft_unsignedint(unsigned int u)
{
	int		printed;
	int		i;
	char	*unsig;

	printed = 0;
	i = 0;
	unsig = uft_itoa(u);
	while (unsig[i])
	{
		printed += write(1, (unsig + i), 1);
		i++;
	}
	free(unsig);
	return (printed);
}

int	ft_lowhex(unsigned int x)
{
	int		printed;
	char	*hexadec;

	hexadec = "0123456789abcdef";
	printed = 0;
	if (x > 15)
	{
		printed += ft_lowhex(x / 16);
		printed += ft_lowhex(x % 16);
	}
	else
	{
		printed += write(1, (hexadec + x), 1);
	}
	return (printed);
}

int	ft_uphex(unsigned int ux)
{
	int		printed;
	char	*hexadec;

	hexadec = "0123456789ABCDEF";
	printed = 0;
	if (ux > 15)
	{
		printed += ft_uphex(ux / 16);
		printed += ft_uphex(ux % 16);
	}
	else
	{
		printed += write(1, (hexadec + ux), 1);
	}
	return (printed);
}
