/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:53:02 by gyildiz           #+#    #+#             */
/*   Updated: 2025/02/08 20:44:33 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	chk_spaces(char *str)
{
	int	i;
	
	i = 0;
	while(str[i])
	{
		if ((str[i] == ' ') && (str[i + 1] == ' ')) //Birden fazla space olması durumu kontrolü
			return (0);
		i++;
	}
	return (1);	
}
int	chk_if_string(char *str)
{
	char	**el;
	int		i;
	
	el = ft_split(str, ' ');
	if (!el)
		return (0);
	while (el[i])
		i++;
	if(i == 1)
		return (0);
	return (1);
}
int	chk_if_repeats(char **el) // gerek kaldı, atoi ile kullan
{

	
}

int	chk_minmax(char **el) //MAX 2147483647 MIN –2147483648 NASIL YAPILACAĞI DEFTERDE YAZIYOR
{
	int	i;
	int	j;

	while(el[i])
	{
		while(el[i][j])
			j++;
		if (j > 11)
			return (0);
		if(el[i][0] == '-' && j == 11)
		{
			if(el[i][9] > '4')
				return (0);
			else if (el[i][9] == 4)
			{
				if(el[i][10] > 8)
					return (0);
			}
		}
		i++;
	}
	return (1);
}

int	chk_string_chrctrs(char *str)
{
	char	**el;
	int		i;
	int		j;
	
	if (!str || !chk_spaces(str) || !chk_if_string(str))
		return (0);
	el = ft_split(str, ' ');
	if (!el)
		return (0);
	i = 0;
	j = 0;
	while (el[i])
	{
		while(el[i][j])
		{
			if(el[i][j] != '-' && !ft_isdigit(el[i][j])) // - ve rakam dışında bir şey var mı kontrolü
				return (0);
			else if((j != 0 && el[i][j] == '-') || j == 0 && el[i][j + 1] != 0) // 32- ve 003 gibi sayıların kontrolü
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (!chk_string_chrctrs(argv[1]))
		{
			ft_printf("Error1\n");
			return (0);
		}
	}
	ft_printf("All is well\n");
}

// int	main(void)
// {
// 	char *s = "2";
// 	char **ss = ft_split(s, ' ');
// 	int i = 0;
// 	while (ss[i])
// 	{
// 		ft_printf("%s\n", ss[i]);
// 		i++;
// 	}	
// }

int	main(void)
{
	int a = ft_atoi("922337203685477580");
	ft_printf("%d\n", a);
}