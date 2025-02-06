/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:40:40 by gyildiz           #+#    #+#             */
/*   Updated: 2024/11/10 15:40:47 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ss_count(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static char	*onestring(char const *s, char c)
{
	size_t	slen;
	size_t	i;
	char	*sstr;

	slen = 0;
	while (s[slen] && s[slen] != c)
	{
		slen++;
	}
	sstr = (char *)malloc(sizeof(char) * (slen + 1));
	if (!sstr)
		return (NULL);
	i = 0;
	while (i < slen)
	{
		sstr[i] = s[i];
		i++;
	}
	sstr[i] = '\0';
	return (sstr);
}

static void	free_memory(char **strings, size_t i)
{
	while (i > 0)
	{
		free(strings[i - 1]);
		i--;
	}
	free(strings);
}

static int	afstr(char const *s, char c, char **strings, size_t sstr_count)
{
	size_t	i;

	i = 0;
	while (*s && (i < sstr_count))
	{
		if (*s != c)
		{
			strings[i] = onestring(s, c);
			if (!strings[i])
			{
				free_memory(strings, i);
				return (0);
			}
			i++;
			while (*s && (*s != c))
				s++;
		}
		else
			s++;
	}
	strings[i] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**strings;
	size_t	sstr_count;

	if (!s)
		return (NULL);
	sstr_count = ss_count(s, c);
	strings = (char **)malloc(sizeof(char *) * (sstr_count + 1));
	if (!strings)
		return (NULL);
	if (!afstr(s, c, strings, sstr_count))
		return (NULL);
	return (strings);
}
