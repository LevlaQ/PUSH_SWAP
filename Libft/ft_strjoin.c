/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:03:29 by gyildiz           #+#    #+#             */
/*   Updated: 2024/11/07 19:18:20 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	st1;
	size_t	st2;
	size_t	i;
	char	*joined;

	st1 = ft_strlen(s1);
	st2 = ft_strlen(s2);
	if (!s1 || !s2)
		return (NULL);
	joined = (char *)malloc(sizeof(char) * (st1 + st2 + 1));
	if (!joined)
		return (NULL);
	i = -1;
	while (s1[++i])
	{
		joined[i] = s1[i];
	}
	i = 0;
	while (s2[i])
	{
		joined[st1 + i] = s2[i];
		i++;
	}
	joined[st1 + i] = '\0';
	return (joined);
}
