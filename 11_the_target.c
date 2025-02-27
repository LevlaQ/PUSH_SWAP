/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_the_target.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:09:36 by gyildiz           #+#    #+#             */
/*   Updated: 2025/02/27 17:50:11 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Finds the best target position for a given value in stack B.
 * - The target is the **largest number in B that is smaller than `value`**.
 * - If no such number exists, the function returns the maximum value in B.
 *
 * Returns:
 * - A pointer to the best target node in stack B.
 */
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
	if (target == NULL)
		target = find_max(sb);
	return (target);
}

/*
 * Finds the best target position for a given value in stack A.
 * - The target is the **smallest number in A that is larger than `value`**.
 * - If no such number exists, the function returns the minimum value in A.
 *
 * Returns:
 * - A pointer to the best target node in stack A.
 */
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
	if (target == NULL)
		target = find_min(sa);
	return (target);
}

/*
 * Finds the node in the stack with the smallest move cost.
 * - Iterates through the stack and returns the node with the minimum `cost` value.
 *
 * Returns:
 * - A pointer to the node with the minimum move cost.
 */
t_plate	*find_min_cost(t_plate **lst)
{
	t_plate	*iter;
	t_plate	*min_cost;
	
	iter = (*lst);
	min_cost = (*lst);
	while(iter)
	{
		if(iter->cost < min_cost->cost)
			min_cost = iter;
		iter = iter->next;
	}
	return (min_cost);
}