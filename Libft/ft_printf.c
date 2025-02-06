/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:40:38 by gyildiz           #+#    #+#             */
/*   Updated: 2025/02/06 19:42:24 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

static int	function_call(char a, va_list args)
{
	int		printed;
	char	c;

	printed = 0;
	if (a == 'c')
	{
		c = (char)va_arg(args, unsigned int);
		printed += write(1, &c, 1);
	}
	else if (a == 's')
		printed += ft_string(va_arg(args, char *));
	else if (a == 'p')
		printed += ft_pointercast((va_arg(args, void *)));
	else if (a == 'd' || a == 'i')
		printed += ft_decint(va_arg(args, int));
	else if (a == 'u')
		printed += ft_unsignedint(va_arg(args, unsigned int));
	else if (a == 'x')
		printed += ft_lowhex(va_arg(args, unsigned int));
	else if (a == 'X')
		printed += ft_uphex(va_arg(args, unsigned int));
	return (printed);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		printed;

	va_start (args, s);
	i = 0;
	printed = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			if (s[i + 1] == '%')
				printed += write(1, "%", 1);
			printed += function_call(s[i + 1], args);
			i++;
		}
		else
			printed += write(1, &s[i], 1);
		i++;
	}
	va_end (args);
	return (printed);
}
