/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_my_cost.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:18:37 by gyildiz           #+#    #+#             */
/*   Updated: 2025/02/27 17:32:47 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Finds the last index of the stack.
 * - Iterates through the stack until it reaches the last node.
 * - Returns the index of the last node.
 */
int	m_last_index(t_plate **lst)
{
	t_plate	*iter;

	iter = (*lst);
	while(iter->next)
		iter = iter->next;
	return (iter->index);
}

/* 
 * Determines whether to rotate (`ra`/`rb`) or reverse rotate (`rra`/`rrb`).
 * - If `last_index` is 0, returns 3 (both moves are valid).
 * - If index is greater than the median, returns 0 (reverse rotate).
 * - If index is smaller than the median, returns 1 (rotate).
 * - If the index is exactly the median, returns 3 (either move is valid).
 *
 * Returns:
 *  - `0` → Perform reverse rotate (`rra` or `rrb`).
 *  - `1` → Perform rotate (`ra` or `rb`).
 *  - `3` → Either direction is acceptable.
 */
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

/*
 * Determines the number of moves needed to position a plate at the top.
 * - If there is only one element, returns `0` (no moves needed).
 * - Uses the median index to decide how many rotations are required.
 * - If index is within the lower half, returns index as move count.
 * - If index is in the upper half, calculates the shortest path to the top.
 *
 * Returns:
 *  - The number of moves required to bring `plate` to the top of the stack.
 */
int	how_many_moves(t_plate **lst, t_plate **plate)
{
	int median_i;
	int last_index;
	
	last_index = m_last_index(lst);
	if(last_index == 0)
		return (0);
	if(last_index % 2 == 0)
	{
		median_i = (last_index / 2);
		if((*plate)->index <= median_i)
			return((*plate)->index);
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

