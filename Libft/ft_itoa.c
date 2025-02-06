/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 20:38:24 by gyildiz           #+#    #+#             */
/*   Updated: 2024/11/07 20:39:15 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(int n)
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

char	*ft_itoa(int n)
{
	char	*intstr;
	int		len;
	long	num;

	len = num_len(n);
	intstr = (char *)malloc(sizeof(char) * (len + 1));
	if (!intstr)
		return (NULL);
	intstr[len] = '\0';
	num = n;
	if (num == 0)
		intstr[0] = '0';
	if (num < 0)
	{
		intstr[0] = '-';
		num = -num;
	}
	while (num > 0)
	{
		len--;
		intstr[len] = (num % 10) + 48;
		num = num / 10;
	}
	return (intstr);
}
