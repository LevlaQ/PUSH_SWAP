/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_movess.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:36:19 by gyildiz           #+#    #+#             */
/*   Updated: 2025/02/28 15:05:37 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Moves the top element of stack A to the top of stack B.
 * - If stack A is empty, does nothing.
 * - Updates `next` and `prev` pointers accordingly.
 * - Calls `index_the_stack()` to update indices after the move.
 */
void	push_to_b(t_p **sa, t_p **sb)
{
	t_p	*tmp;

	if (!(*sa))
		return ;
	tmp = (*sa);
	(*sa) = (*sa)->next;
	if (*sa)
		(*sa)->prev = NULL;
	tmp->next = (*sb);
	tmp->prev = NULL;
	if (*sb)
		(*sb)->prev = tmp;
	(*sb) = tmp;
	index_the_stack(sa);
	index_the_stack(sb);
	reset_performs(sa);
	reset_performs(sb);
}

/*
 * Rotates stack A upwards.
 * - The first element moves to the last position.
 * - If stack A has 0 or 1 element, does nothing.
 */
void	rotate_a(t_p **sa)
{
	t_p		*iter;
	int		tmp;

	if (!(*sa) || !((*sa)->next))
		return ;
	iter = (*sa);
	tmp = iter->value;
	while (iter->next)
	{
		iter->value = iter->next->value;
		iter = iter->next;
	}
	iter->value = tmp;
}

/*
 * Rotates stack B upwards.
 * - The first element moves to the last position.
 * - If stack B has 0 or 1 element, does nothing.
 */
void	rotate_b(t_p **sb)
{
	t_p		*iter;
	int		tmp;

	if (!(*sb) || !((*sb)->next))
		return ;
	iter = (*sb);
	tmp = iter->value;
	while (iter->next)
	{
		iter->value = iter->next->value;
		iter = iter->next;
	}
	iter->value = tmp;
}

/*
 * Performs `ra` and `rb` simultaneously.
 * - Both stack A and stack B perform rotate.
 */
void	rotate_ab(t_p **sa, t_p **sb)
{
	rotate_a(sa);
	rotate_b(sb);
}
