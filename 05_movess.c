/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_movess.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:36:19 by gyildiz           #+#    #+#             */
/*   Updated: 2025/02/23 14:10:46 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//a boş ise hiçbir işlem yapmıyor, a'nın ilk elemanını al ve b'ye ata
void	push_to_b(t_plate **sa, t_plate **sb)
{
	t_plate	*tmp;
	
	if(!(*sa))
		return ;
	tmp = (*sa);
	(*sa) = (*sa)->next; //Eğer a'da tek bir eleman varsa bu işlemden sonra *sa NULL'a eşit olur
	if(*sa)
		(*sa)->prev = NULL;
	tmp->next = (*sb);
	tmp->prev = NULL; //Bir de bunsuz kodu denersin
	if (*sb) //b' boş olabilir, eğer b boş değilse, tabak varsa o tabağın prev'ini değiştir
		(*sb)->prev = tmp;
	(*sb) = tmp;
	index_the_stack(sa);
	index_the_stack(sb);
}

//listenin ilk elemanı son eleman oluyor, listedeki her şey bir yukarı kayıyor
void	rotate_a(t_plate **sa)
{
	t_plate	*iter;
	int		tmp;

	if(!(*sa) || !((*sa)->next))
		return;
	iter = (*sa);
	tmp = iter->value;
	while(iter->next)
	{
		iter->value = iter->next->value;
		iter = iter->next;
	}
	iter->value = tmp;
}

//listenin ilk elemanı son eleman oluyor, listedeki her şey bir yukarı kayıyor
void	rotate_b(t_plate **sb)
{
	t_plate	*iter;
	int		tmp;

	if(!(*sb) || !((*sb)->next))
		return;
	iter = (*sb);
	tmp = iter->value;
	while(iter->next)
	{
		iter->value = iter->next->value;
		iter = iter->next;
	}
	iter->value = tmp;
}

void	rotate_ab(t_plate **sa, t_plate **sb)
{
	rotate_a(sa);
	rotate_b(sb);
}