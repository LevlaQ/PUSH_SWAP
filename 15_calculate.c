/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   15_calculate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:31:44 by gyildiz           #+#    #+#             */
/*   Updated: 2025/02/28 15:48:14 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Moves elements from stack A to stack B until stack A is circularly sorted.
 * - If stack B is empty, pushes the first element from A to B.
 * - For each element in A, finds the best target position in B.
 * - Calculates movement costs and performs the necessary operations.
 */
void	calc_acost_and_ptb(t_p **sa, t_p **sb)
{
	t_p	*iter_a;
	t_p	*target;
	t_p	*min_cost;

	if (!(*sb))
		b_is_empty(sa, sb);
	while (!ami_inorder_a(sa))
	{
		iter_a = (*sa);
		while (iter_a)
		{
			target = my_target_in_b(iter_a->value, sb);
			cost_perf_a(sa, sb, &iter_a, &target);
			iter_a = iter_a->next;
		}
		min_cost = find_min_cost(sa);
		what_isit(&min_cost, sa, sb);
		push_to_b(sa, sb);
		ft_printf("pb\n");
		iter_a = (*sa);
	}
}

/*
 * Moves elements from stack B back to stack A after stack A is sorted.
 * - Ensures that elements are placed in their correct position in A.
 * - Continues until stack B is empty.
 */
void	calc_bcost_and_pta(t_p **sa, t_p **sb)
{
	t_p	*iter_b;
	t_p	*target;
	t_p	*min_cost;

	while (*sb)
	{
		iter_b = (*sb);
		while (iter_b)
		{
			target = my_target_in_a(iter_b->value, sa);
			cost_perf_b(sa, sb, &target, &iter_b);
			iter_b = iter_b->next;
		}
		min_cost = find_min_cost(sb);
		what_isit(&min_cost, sa, sb);
		push_to_a(sa, sb);
		ft_printf("pa\n");
		iter_b = (*sb);
		reset_performs(&iter_b);
	}
}

void	b_is_empty(t_p **sa, t_p **sb)
{
	if (!ami_inorder_a(sa))
	{
		push_to_b(sa, sb);
		ft_printf("pb\n");
	}
	else
		return ;
}

void	the_three(t_p **sa)
{
	three_biggest_to_last(sa);
	swap_if_nsorted(sa);
}
