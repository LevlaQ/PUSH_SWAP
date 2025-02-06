/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 16:51:24 by gyildiz           #+#    #+#             */
/*   Updated: 2024/11/12 14:30:14 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	diff(unsigned char c1, unsigned char c2)
{
	if (c1 > c2)
		return (1);
	else if (c1 < c2)
		return (-1);
	else
		return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*d1;
	unsigned char	*d2;

	d1 = (unsigned char *)(s1);
	d2 = (unsigned char *)(s2);
	i = 0;
	if (n == 0)
		return (0);
	while ((i < n) && (d1[i] && d2[i]))
	{
		if (d1[i] != d2[i])
			return (diff(d1[i], d2[i]));
		i++;
	}
	if (i == n)
		return (diff(d1[i - 1], d2[i - 1]));
	else
		return (diff(d1[i], d2[i]));
}
