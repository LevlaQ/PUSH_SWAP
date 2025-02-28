/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_ami_circular_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:31:04 by gyildiz           #+#    #+#             */
/*   Updated: 2025/02/28 11:56:11 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Finds the node with the smallest value in the stack.
 * - Iterates through the stack and returns the node with the minimum value.
 */
t_p	*find_min(t_p **lst)
{
	t_p	*iter;
	t_p	*min_plate;

	iter = (*lst);
	min_plate = (*lst);
	while (iter)
	{
		if (iter->value < min_plate->value)
			min_plate = iter;
		iter = iter->next;
	}
	return (min_plate);
}

/*
 * Checks if the stack is sorted in ascending order from the minimum value.
 * - Starts checking from the given node (minimum value).
 * - Returns 1 if the stack is sorted, otherwise returns 0.
 */
int	is_sorted_from_min(t_p **sa)
{
	t_p	*iter;

	iter = (*sa);
	while (iter->next)
	{
		if (iter->value > iter->next->value)
			return (0);
		iter = iter->next;
	}
	return (1);
}

/*
 * Retrieves the value of the last node in the stack.
 * - Traverses to the last node and returns its value.
 */
int	get_end_value(t_p **lst)
{
	t_p	*iter;

	iter = (*lst);
	while (iter->next)
		iter = iter->next;
	return (iter->value);
}

/*
 * Checks if stack A is circularly sorted.
 * - First, checks if the stack is already sorted from the minimum value.
 * - If sorted, verifies circular ordering by ensuring the last value is
 *   smaller than the first.
 * - Returns 1 if the stack is circularly sorted, otherwise returns 0.
 */
int	ami_inorder_a(t_p **sa)
{
	t_p		*iter;
	int		index_min;

	if (!(*sa) || !((*sa)->next))
		return (1);
	iter = find_min(sa);
	index_min = iter->index;
	if (!is_sorted_from_min(&iter))
		return (0);
	if (index_min == 0)
		return (1);
	iter = (*sa);
	if (iter->value < get_end_value(sa))
		return (0);
	while ((iter->index != index_min))
	{
		if ((iter->value > iter->next->value)
			&& (iter->next->index != index_min))
			return (0);
		iter = iter->next;
	}
	return (1);
}

/*
 * Finds the node with the largest value in stack B.
 * - Iterates through the stack and returns the node with the maximum value.
 */
t_p	*find_max(t_p **lst)
{
	t_p	*iter;
	t_p	*max_plate;

	iter = (*lst);
	max_plate = (*lst);
	while (iter)
	{
		if (iter->value > max_plate->value)
			max_plate = iter;
		iter = iter->next;
	}
	return (max_plate);
}
