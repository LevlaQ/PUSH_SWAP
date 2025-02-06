/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:33:21 by gyildiz           #+#    #+#             */
/*   Updated: 2024/11/07 11:36:10 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	str_size;
	size_t	chr_size;
	size_t	i;
	char	*dub;

	str_size = ft_strlen(s1) + 1;
	chr_size = sizeof(char);
	i = 0;
	dub = malloc(str_size * chr_size);
	if (dub == NULL)
		return (NULL);
	while (s1[i])
	{
		dub [i] = s1[i];
		i++;
	}
	dub[i] = '\0';
	return (dub);
}
