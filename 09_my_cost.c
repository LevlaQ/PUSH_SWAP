/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_my_cost.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:18:37 by gyildiz           #+#    #+#             */
/*   Updated: 2025/02/23 14:11:09 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	m_last_index(t_plate **lst)
{
	t_plate	*iter;

	iter = (*lst);
	while(iter->next)
		iter = iter->next;
	return (iter->index); //Maliyet hesaplamaları için son elemanın indeksini alıyorum
}

/* Bu fonksiyona tek elemanlı liste gelmemeli
median üstü (yukarı kayacaklar) 1 altı 0 olsun (aşağı kayacaklar)
r ve rr maliyeti eşit durumlar 3 döndürsün */
int r_or_rr(t_plate **lst, int my_index)
{
	int	median_i;
	int	last_index;
	
	last_index = m_last_index(lst);
	if(last_index == 0)
		return (3);
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
			return (3);
		else
			return (1);
	}
}

//Kaç tane hamle yapmalıyım index üzerinden hesap
int	how_many_moves(t_plate **lst, t_plate **plate)
{
	int median_i;
	int last_index;
	
	last_index = m_last_index(lst);
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
