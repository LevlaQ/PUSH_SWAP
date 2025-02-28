/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_my_cost_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 13:00:45 by gyildiz           #+#    #+#             */
/*   Updated: 2025/02/28 11:53:00 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Calculates the cost and optimal moves for transferring 
 * elements from stack A to B.
 * - For each element in stack A, finds its target position in stack B.
 * - Computes the number of moves required to reach the target position.
 * - Updates the `perform_rr`, `perform_rrr`, `perform_ra`, `perform_rra`,
 *   `perform_rb`, and `perform_rrb` values for each element.
 */
void	cost_perf_a(t_p **sa, t_p **sb, t_p **a, t_p **b)
{
	int	mvs_a;
	int	mvs_b;
	int	drctn_a;
	int	drctn_b;

	mvs_a = how_many_moves(sa, a);
	mvs_b = how_many_moves(sb, b);
	drctn_a = r_or_rr(sa, (*a)->index);
	drctn_b = r_or_rr(sb, (*b)->index);
	if ((drctn_a + drctn_b) == 0)
		perform_1(a, mvs_a, mvs_b);
	else if ((drctn_a + drctn_b) == 2)
		perform_2(a, mvs_a, mvs_b);
	else if ((drctn_a + drctn_b) == 1)
		perform_3(a, mvs_a, mvs_b, drctn_a);
	else if ((drctn_a + drctn_b) == 3)
		perform_4(a, mvs_a, mvs_b);
	else if (((drctn_a + drctn_b) == 4) || ((drctn_a + drctn_b) == 6))
		perform_5(a, mvs_a, mvs_b);
	else
		return ;
}

/*
 * Calculates the cost and optimal moves for transferring elements 
 * from stack B to A.
 * - Similar to `cost_perf_a`, but for elements in stack B.
 * - Finds the target position of each element in stack A.
 * - Computes and updates the necessary moves for optimal positioning.
 */
void	cost_perf_b(t_p **sa, t_p **sb, t_p **a, t_p **b)
{
	int	mvs_a;
	int	mvs_b;
	int	drctn_a;
	int	drctn_b;

	mvs_a = how_many_moves(sa, a);
	mvs_b = how_many_moves(sb, b);
	drctn_a = r_or_rr(sa, (*a)->index);
	drctn_b = r_or_rr(sb, (*b)->index);
	if ((drctn_a + drctn_b) == 0)
		perform_1(b, mvs_a, mvs_b);
	else if ((drctn_a + drctn_b) == 2)
		perform_2(b, mvs_a, mvs_b);
	else if ((drctn_a + drctn_b) == 1)
		perform_3(b, mvs_a, mvs_b, drctn_a);
	else if ((drctn_a + drctn_b) == 3)
		perform_4(b, mvs_a, mvs_b);
	else if (((drctn_a + drctn_b) == 4) || ((drctn_a + drctn_b) == 6))
		perform_5(b, mvs_a, mvs_b);
	else
		return ;
}
