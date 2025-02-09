/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:49:23 by gyildiz           #+#    #+#             */
/*   Updated: 2025/02/09 19:26:21 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	chk_chrctrs(char **el)
{
	int		i;
	int		j;
	
	if (!el)
		return (0); //el oluşmuş oluşmamış kontrolü
	i = 0;
	j = 0;
	while (el[i])
	{
		while(el[i][j])
		{
			if((el[i][j] != '-') && !ft_isdigit(el[i][j])) // - ve rakam dışında bir şey var mı kontrolü
				return (0);
			else if((j != 0 && el[i][j] == '-') || (j == 0 && el[i][j + 1] != 0)) // 32- ve 003 gibi sayıların kontrolü
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	chk_integers_general(char **el)
{
	if (!el)
		return (0);
	if (chk_minmax(el))
	{
		if(chk_if_repeats(el))
			return (1);
		printf("Error(Integer repeats)\n");
		return (0);
	}
	printf("Error(Integer overflow)\n");
	return (0);
}

int	chk_minmax(char **el)
{
	int	i;

	i = 0;
	while(el[i])
	{
		if(!modified_atoi_limits(el[i])) //MAX 2147483647 MIN –2147483648
			return (0);
	}
	return (1);
}

int	modified_atoi_limits(char *str)
{
	int				i;
	int				sign;
	unsigned long	inte;

	i = 0;
	sign = 1;
	inte = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if ((str[i] == '-' || str[i] == '+'))
		if (str[i++] == '-')
			sign = sign * -1;
	while (str[i] >= 48 && str[i] <= 57 && str[i])
	{
		inte = (inte * 10) + (str[i] - 48);
		i++;
		if (inte > 2147483647)
		{
			if (sign == 1)
				return (0);
			else if (inte > 2147483648)
				return (0);
		}
	}
	return (1); //Sayı limitler içerisinde ise 1 döndürecek
}

int	chk_if_repeats(char **el)
{
	int i;
	int j;
	
	i = 0;
	while(el[i])
	{
		j = 0; //Bütün sayılar tek tek baştan sona diğer sayılar ile karşılaştırılacak
		while(el[j])
		{
			if(ft_atoi(el[i]) == ft_atoi(el[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

