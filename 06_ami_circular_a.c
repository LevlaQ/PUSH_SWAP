/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_ami_circular_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:31:04 by gyildiz           #+#    #+#             */
/*   Updated: 2025/02/24 16:25:01 by gyildiz          ###   ########.fr       */
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
			min_plate = iter;			   //Yeni min değeri bu
		iter = iter->next;
	}
	return (min_plate); //min değere sahip tabağa işaret eden pointerı döndür
}

int	is_sorted_from_min(t_plate **sa)
{
	t_plate	*iter;
	
	iter = (*sa);
	while(iter->next)
	{
		if(iter->value > iter->next->value)
			return (0); //Sayılar küçükten büyüğe sıralı değil
		iter = iter->next;
	}
	return (1); //Sayılar küçükten büyüğe sıralı
}

int	get_end_value(t_plate **lst)
{
	t_plate	*iter;

	iter = (*lst);
	while(iter->next)
		iter = iter->next;
	return(iter->value);
}

int	ami_inorder_a(t_plate **sa)
{
	t_plate	*iter;
	int		index_min;
	
	if(!(*sa) || !((*sa)->next)) //Tek elemanlı veya hiç eleman yoksa listem sıralı
		return (1);
	iter = find_min(sa); //Minimum sayımdan itibaren sıralama kontrolü başlayacak
	index_min = iter->index;
	if (!is_sorted_from_min(&iter)) //minimum değerin tabağının indexini gönderdim
		return (0);
	if (index_min == 0)
		return (1); //Listem hem dairesel hem de düz sıralı
	iter = (*sa);
	if (iter->value < get_end_value(sa)) //Liste sonundan liste başına dairesel sıralı mı
		return (0);
	while((iter->index != index_min))
	{
		if((iter->value > iter->next->value) && (iter->next->index != index_min))
			return (0); //stack a sıralı değil
		iter = iter->next;
	}
	return (1); //Listem dairesel sıralı
}

