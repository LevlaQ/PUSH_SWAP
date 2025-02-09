/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:49:04 by gyildiz           #+#    #+#             */
/*   Updated: 2025/02/09 19:36:17 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_main(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("Error(Less than two arguments)\n");
		return (0);
	}
	if (argc == 2) //string durumu burada geçerli
	{
		if(!error_two_args(argv))
			return (0);
	}
	if (argc > 2)
	{
		if(!error_multi_args(argv))
			return (0);
	}
	return (1);
}

int	error_two_args(char **argv) //Bir yerlerde sonsuz döngüye giriyor gibi
{
	char	**el;
	
	if(chk_if_string(argv[1])) // İkinci argüman bir string ise
	{
		if(chk_spaces(argv[1])) //Bu stringde boşluk kuralına uyulmuşsa
		{
			el = ft_split(argv[1], ' ');
			if(chk_chrctrs(el)) //Stringde yasaklı karakterler kullanılmamışsa
			{
				if(!chk_integers_general(el)) //integer testleri *? ayrıca return 1 eklemem gerekir mi*?
					return (free_strings(el), 0);
				return (free_strings(el), 1);
			}
			printf("Error(There are forbidden chars)");
			return (free_strings(el), 0);
		}
		printf("Error(There are multiple spaces)\n");
		return (0);
	}
	if(!chk_if_string(argv[1])) //İKinci argüman bir string değil ise, bu verilmiş tek bir sayıdır
	{
		printf("Error(There is only one integer)\n");
		return (0);
	}
	return (1);
}

int error_multi_args(char **argv) //chk_if_string birçok kez çalıştırılırken diğer fonksiyonlar bir kere çağırılsa yeter, düzeltme yapılmalı
{
	int	i;

	i = 0;
	while(argv[i])
	{
		if(chk_if_string(argv[i]))
		{
			printf("Error(Can't use mixed syntax)\n");
			return (0);
		}
		if(chk_chrctrs(argv)) //Bütün argümanlarda yasaklı karakterlerin kontrolü
		{
			if(!chk_integers_general(argv)) //integer testleri *? ayrıca return 1 eklemem gerekir mi*?
				return (0);
			return (1);
		}
		else if(!chk_chrctrs(argv))
		{
			printf("Error(There are forbidden chars)");
			return (0);
		}
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
	i = 0;
	while (el[i])
		i++;
	if(i == 1) // Eğer ft_split sonucunda tek bir eleman elde edilmişse argüman strinf değildir
	{
		free (el);
		return (0);
	}
	free (el);
	return (1); //String ise bir döndürür
}

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
	return (1); //Spaceler düzgün sırada ise 1 döndür
}