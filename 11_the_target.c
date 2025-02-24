/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_the_target.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:09:36 by gyildiz           #+#    #+#             */
/*   Updated: 2025/02/24 13:53:45 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Kendisinden küçük en büyüy sayıyı bulmalı (dairesel sıralama)
//Eğer B'de eleman varsa bu fonksiyonu çağır, kontrolünü çağırdığın yerde yap!!!
t_plate *my_target_in_b(int value, t_plate **sb)
{
	t_plate	*iter;
	t_plate *target;

	iter = (*sb);
	target = NULL;
	while(iter)
	{
		if((value > iter->value) && (!target || iter->value > target->value))
			target = iter;
		iter = iter->next;
	}
	if (target == NULL) //Yani value'dan küçük bir sayı bulunamamış
		target = find_max(sb);
	return (target);
}

//Eğer sadece A'da eleman varsa bu fonksiyonu çağır
//Kendisinden büyük en küçük sayıyı bulmalı
t_plate *my_target_in_a(int value, t_plate **sa)
{
	t_plate	*iter;
	t_plate *target;

	iter = (*sa);
	target = NULL;
	while(iter)
	{
		if((value < iter->value) && (!target || iter->value < target->value))
			target = iter;
		iter = iter->next;
	}
	if (target == NULL) //Yani value'dan büyük bir sayı bulunamamış
		target = find_min(sa);
	return (target);
}

t_plate	*find_min_cost(t_plate **lst)
{
	t_plate	*iter;
	t_plate	*min_cost;
	
	iter = (*lst);
	min_cost = (*lst);
	while(iter)
	{
		if(iter->cost < min_cost->cost)	//Eğer yeni gösterilen değer küçükse halihazırda min_plate'te olan değerden
			min_cost = iter;			//Yeni min değeri bu
		iter = iter->next;
	}
	return (min_cost); //min değere sahip tabağa işaret eden pointerı döndür
}