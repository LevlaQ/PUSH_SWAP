/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:30:09 by gyildiz           #+#    #+#             */
/*   Updated: 2024/11/12 14:49:11 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	ndl_len;
	size_t	hay_len;

	i = 0;
	ndl_len = ft_strlen(needle);
	hay_len = ft_strlen(haystack);
	if (hay_len < ndl_len)
		return (NULL);
	if (ndl_len == 0)
		return ((char *)(haystack));
	while ((i <= (len - ndl_len)) && haystack[i] && !(ndl_len > len))
	{
		j = 0;
		while (haystack[i + j] == needle[j] && haystack[i + j])
			j++;
		if (j == ndl_len)
			return ((char *)(&haystack[i]));
		i++;
	}
	return (NULL);
}
