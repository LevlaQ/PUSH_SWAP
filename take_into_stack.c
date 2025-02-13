/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_into_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:12:05 by gyildiz           #+#    #+#             */
/*   Updated: 2025/02/13 13:15:29 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//into stack içinde olacak, stack A pointera ihtiyacım var
int	to_the_stack_a_main(int argc, char **argv, t_plate **lst)
{
	char	**a_values; //Bütün değerler stack'e aktarıldıktan sonra yok edilmesi lazım
	int		stcnt; //String gelmesi durumunda kaç tane argümanım var
	
	if(argc == 2)
	{
		a_values = ft_split(argv[1], ' ');
		if (!a_values)
			return (printf("Error(Problem creating the stack)\n"), 0);
		stcnt = 0;
		while(a_values[stcnt])
			stcnt++;
		if(!into_stack(stcnt, a_values, lst))
			return(printf("Error(Problem creating the stack)\n"), 0);
		index_the_stack(lst);
		free_strings(a_values);
	}
	else if(argc > 2)
	{
		if(!into_stack(argc - 1, argv + 1, lst )) //a.out dahil edilmeden veri gönderimi yapıldı
			return(printf("Error(Problem creating the stack)\n"), 0);
		index_the_stack(lst);
	}
	return(1);
}

//Argümanları tek tek tabakların içine koyuyor (node)
int into_stack(int argc, char **el, t_plate **lst)
{
	int	i;
	int	value;
	
	i = argc - 1;
	while(i >= 0) //Kontrolünü yaparsın ilk eleman ekleniyor mu eklenmiyor mu
	{
		value = ft_atoi(el[i]);
		if(!add_plate_front(lst, value))
			return (0);
		i--;
	}
	return (1);
}

//Elemanları tek tek listenin başından ekliyor
int add_plate_front(t_plate **lst, int number)
{
	t_plate	*new_plate;

	new_plate = (t_plate *)malloc(sizeof(t_plate));
	if(!new_plate)
		return (0);
	new_plate->value = number;
	new_plate->next = *lst;
	*lst = new_plate;
	return (1);
}

void index_the_stack(t_plate **lst)
{
	t_plate	*iter;
	int		i;
	
	i = 0;
	iter = *lst;
	while(iter)
	{
		iter->index = i;
		iter = iter->next;
		i++;
	}
}