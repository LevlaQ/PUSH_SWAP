/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:18:25 by gyildiz           #+#    #+#             */
/*   Updated: 2025/02/13 20:21:33 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//b boş ise hiçbir işlem yapmıyor, b'nin ilk elemanını al ve a'ya ata (algoritma başlangıcı için ayrı fonksiyon yazmam gerekecek)
void	push_to_a(t_plate **sa, t_plate **sb)
{
	t_plate	*tmp;
	
	if(!(*sb))
		return ;
	tmp = (*sb);
	(*sb) = (*sb)->next;
	if (*sb)
		(*sb)->prev = NULL;
	tmp->next = (*sa);
	tmp->prev = NULL; //Bir de bunsuz kodu denersin
	if (*sa)
		(*sa)->prev = tmp;
	(*sa) = tmp;
	index_the_stack(sa);
	index_the_stack(sb);
}

//Liste son elemanı listenin ilk elemanı olacak
void	r_rotate_a(t_plate **sa)
{
	t_plate	*iter;
	int		tmp;
	
	if(!(*sa) || !((*sa)->next)) //Stack boş veya tek elemanlı ise işlem yapma
		return ;
	iter = (*sa);
	while (iter->next)
		iter = iter->next;
	tmp = iter->value;
	while (iter->prev)
	{
		iter->value = iter->prev->value;
		iter = iter->prev;
	}
	iter->value = tmp;
}

void	r_rotate_b(t_plate **sb)
{
	t_plate	*iter;
	int		tmp;
	
	if(!(*sb) || !((*sb)->next)) //Stack boş veya tek elemanlı ise işlem yapma
		return ;
	iter = (*sb);
	while (iter->next)
		iter = iter->next;
	tmp = iter->value;
	while (iter->prev)
	{
		iter->value = iter->prev->value;
		iter = iter->prev;
	}
	iter->value = tmp;
}

void	rr_ab(t_plate **sa, t_plate **sb)
{
	r_rotate_a(sa);
	r_rotate_b(sb);
}

