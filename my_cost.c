/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_cost.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:18:37 by gyildiz           #+#    #+#             */
/*   Updated: 2025/02/22 14:09:33 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	last_index(t_plate **lst)
{
	t_plate	*iter;

	iter = (*lst);
	while(iter->next)
		iter = iter->next;
	return (iter->index); //Maliyet hesaplamaları için son elemanın indeksini alıyorum
}

int r_or_rr(int last_index, int my_index)
{
	//Bu fonksiyona tek elemanlı liste gelmemeli
	//median üstü (yukarı kayacaklar) 1 altı 0 olsun (aşağı kayacaklar)
	//r ve rr maliyeti eşit durumlar 2 döndürsün
	int	median_i;
	
	if(last_index == 0)
		return (2);
	if(last_index % 2 == 0)
	{
		median_i = (last_index / 2);
		if(my_index > median_i)
			return (0);
		else
			return (1);
	}
	else
	{
		median_i = ((last_index + 1) / 2);
		if(my_index > median_i)
			return (0);
		else if(my_index == median_i)
			return (2);
		else
			return (1);
	}
}

int	how_many_moves(int last_index, t_plate **plate)
{
	//Kaç tane hamle yapmalıyım index üzerinden hesap

	int median_i;
	
	if(last_index == 0) //Listem tek elemanlı ise
		return (0); //Hamle sayısı 0'dır
	if(last_index % 2 == 0)
	{
		median_i = (last_index / 2); //medyanımın indeksini buldum
		if((*plate)->index <= median_i) //Eğer mevcut indeksim medyan indeksimden küçük eşitse
			return((*plate)->index); //indeksim benim hamle sayımdır
		else
			return((median_i - ((*plate)->index - median_i) + 1));
	}
	else
	{
		median_i = ((last_index + 1) / 2);
		if((*plate)->index <= median_i)
			return((*plate)->index);
		else
			return((median_i - ((*plate)->index - median_i)));
	}
}

void	tactics_into_plates(t_plate **plate, t_plate **lst)
{
	int	ls_lenght;
	int	moves;
	
	ls_lenght = last_index(lst);
	moves = how_many_moves(ls_lenght, plate);
	if(r_or_rr(ls_lenght, (*plate)->index) == 2)
	{
		(*plate)->moves_r = moves;
		(*plate)->moves_rr = moves;
	}
	if(r_or_rr(ls_lenght, (*plate)->index) == 1)
		(*plate)->moves_r = moves;
	if(r_or_rr(ls_lenght, (*plate)->index) == 0)
		(*plate)->moves_rr = moves;
}
