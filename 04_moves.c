/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:18:25 by gyildiz           #+#    #+#             */
/*   Updated: 2025/02/27 17:14:15 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Moves the top element of stack B to the top of stack A.
 * - If stack B is empty, does nothing.
 * - Updates the previous and next pointers accordingly.
 * - Calls `index_the_stack()` to update indices after the move.
 */
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
	tmp->prev = NULL;
	if (*sa)
		(*sa)->prev = tmp;
	(*sa) = tmp;
	index_the_stack(sa);
	index_the_stack(sb);
	reset_performs(sa);
	reset_performs(sb);
}

/*
 * Shifts all elements of stack A down by one position.
 * - The last element moves to the top.
 * - If stack A has 0 or 1 element, does nothing.
 */
void	r_rotate_a(t_plate **sa)
{
	t_plate	*iter;
	int		tmp;
	
	if(!(*sa) || !((*sa)->next))
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

/*
 * Shifts all elements of stack B down by one position.
 * - The last element moves to the top.
 * - If stack B has 0 or 1 element, does nothing.
 */
void	r_rotate_b(t_plate **sb)
{
	t_plate	*iter;
	int		tmp;
	
	if(!(*sb) || !((*sb)->next))
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

/*
 * Performs `rra` and `rrb` simultaneously.
 * - Both stack A and stack B perform reverse rotate.
 */
void	rr_ab(t_plate **sa, t_plate **sb)
{
	r_rotate_a(sa);
	r_rotate_b(sb);
}

