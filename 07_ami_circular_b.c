/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_ami_circular_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:12:48 by gyildiz           #+#    #+#             */
/*   Updated: 2025/02/23 14:10:58 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_plate	*find_max(t_plate **lst)
{
	t_plate	*iter;
	t_plate	*max_plate;
	
	iter = (*lst);
	max_plate = (*lst);
	while(iter)
	{
		if(iter->value > max_plate->value)
			max_plate = iter;
		iter = iter->next;
	}
	return (max_plate);
}

int	is_sorted_from_max(t_plate **sb)
{
	t_plate	*iter;
	
	iter = (*sb);
	while(iter->next)
	{
		if(iter->value < iter->next->value)
			return (0); //Sayılar büyükten küçüğe sıralı değil
		iter = iter->next;
	}
	return (1); //Sayılar büyükten küçüğe sıralı
}

int	ami_inorder_b(t_plate **sb)
{
	t_plate	*iter;
	int		index_max;
	
	if(!(*sb) || !((*sb)->next)) //Tek elemanlı veya hiç eleman yoksa listem sıralı
		return (1);
	iter = find_max(sb); //Maximum sayımdan itibaren sıralama kontrolü başlayacak
	index_max = iter->index;
	if (!is_sorted_from_max(&iter)) //maximum değerin tabağının indexini gönderdim
		return (0);
	if (index_max == 0)
		return (1); //Listem hem dairesel hem de düz sıralı
	iter = (*sb);
	if (iter->value > get_end_value(sb)) //Liste sonundan liste başına dairesel sıralı mı
		return (0);
	while((iter->index != index_max))
	{
		if((iter->value < iter->next->value) && (iter->next->index != index_max))
			return (0); //stack b sıralı değil
		iter = iter->next;
	}
	return (1);
}