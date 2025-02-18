/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:31:04 by gyildiz           #+#    #+#             */
/*   Updated: 2025/02/18 20:49:48 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_plate	*find_min(t_plate **lst)
{
	t_plate	*iter;
	t_plate	*min_plate;
	
	iter = (*lst);
	min_plate = (*lst);
	while(iter)
	{
		if(iter->value < min_plate->value) //Eğer yeni gösterilen değer küçükse halihazırda min_plate'te olan değerden
			min_plate = iter;				//Yeni min değeri bu
		iter = iter->next;
	}
	return (min_plate); //min değere sahip tabağa işaret eden pointerı döndür
}

int	ami_inorder_a(t_plate **sa)
{
	t_plate	*iter;
	int		index_min;
	
	if(!(*sa) || !((*sa)->next)) //Tek elemanlı veya hiç eleman yoksa listem sıralı
		return (1);
	iter = find_min(&(*sa)); //Bu kısım biraz karıştırdı beni
	index_min = iter->index;
	while(iter->next)
	{
		if(iter->value > iter->next->value)
			return (0); //stack a sıralı değil
		iter = iter->next;
	}
	if (index_min == 0)
		return (1); //Listem hem dairesel hem de düz sıralı
	iter = (*sa);
	while((iter->index != index_min) && iter->next)
	{
		if(iter->value > iter->next->value)
			return (0); //stack a sıralı değil
		iter = iter->next;
	}
	return (1);
}

int haha();