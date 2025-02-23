/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_error_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:49:04 by gyildiz           #+#    #+#             */
/*   Updated: 2025/02/23 14:10:08 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_main(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("Error(No input provided)\n");
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

int error_two_args(char **argv)
{
	char **el;

	if (!chk_if_string(argv[1])) // Eğer argüman bir string değilse, tek bir sayı olarak kabul edilecek
		return (printf("Error(There is only one integer)\n"), 0);
	if (argv[1][0] == '\0' || !argv[1])
		return (printf("Error(No input provided)\n"), 0);
	if (!chk_spaces(argv[1])) // Bir string var, şimdi boşluk kuralını kontrol ediyoruz
		return (printf("Error(There are multiple spaces)\n"), 0);
	el = ft_split(argv[1], ' ');// Stringi boşluklara göre ayırıyoruz
	if (!el || !el[0])  // ft_split'in başarısız veya boş bir dizi döndürme ihtimali kontrol ediliyor
		return ( printf("Error(ft_split failed)\n"), 0);
	if (!chk_chrctrs(el))  // Karakter kontrolü
		return (printf("Error(Forbidden chars!)\n"), free_strings(el), 0);
	if (!chk_integers_general(el))  // Sayıların geçerliliğini kontrol ediyoruz
		return (free_strings(el), 0);
	return (free_strings(el), 1);
}


int error_multi_args(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])// Tüm argümanları tek tek kontrol et
	{
		if (chk_if_string(argv[i]))// Argüman bir string formatında mı? (Bu durumda karışık syntax kullanımı hatalı olur)
		{
			printf("Error(Can't use mixed syntax)\n");
			return (0);
		}
		i++;
	}
	argv = argv + 1; //a.out gönderilmesin diye
	if (!chk_chrctrs(argv))// Argümandaki karakterler doğru mu? İlk hatada çıkış yap
	{
		printf("Error(There are forbidden chars)\n");
		return (0);
	}
	if (!chk_integers_general(argv))// Tüm argümanlar karakter kontrolünden geçti, şimdi sayı kontrolü yap
	{
		return (0);
	}
	return (1);// Tüm kontroller başarılı, 1 döndür
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
	if(i == 1) // Eğer ft_split sonucunda tek bir eleman elde edilmişse argüman string değildir
	{
		free_strings(el);
		return (0);
	}
	free_strings(el);
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