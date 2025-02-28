/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_say_perform.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 12:49:46 by gyildiz           #+#    #+#             */
/*   Updated: 2025/02/28 11:53:00 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Handles the case where both A and B move in the reverse 
 * rotate (`rrr`) direction.
 * - Chooses the smaller move count as the shared `rrr` operation.
 * - Any extra moves in B are handled separately using `rrb`.
 * - Updates `perform_rrr`, `perform_rrb`, and `cost` accordingly.
 */
void	perform_1(t_p **p, int mvs_a, int mvs_b)
{
	if (mvs_a <= mvs_b)
	{
		(*p)->perform_rrr = mvs_a;
		(*p)->perform_rrb = (mvs_b - mvs_a);
		(*p)->cost = mvs_b;
	}
	else
	{
		(*p)->perform_rrr = mvs_b;
		(*p)->perform_rra = (mvs_a - mvs_b);
		(*p)->cost = mvs_a;
	}
}

/*
 * Handles the case where both A and B move in the rotate (`rr`) direction.
 * - Chooses the smaller move count as the shared `rr` operation.
 * - Any extra moves in B are handled separately using `rb`.
 * - Updates `perform_rr`, `perform_rb`, and `cost` accordingly.
 */
void	perform_2(t_p **p, int mvs_a, int mvs_b)
{
	if (mvs_a <= mvs_b)
	{
		(*p)->perform_rr = mvs_a;
		(*p)->perform_rb = (mvs_b - mvs_a);
		(*p)->cost = mvs_b;
	}
	else
	{
		(*p)->perform_rr = mvs_b;
		(*p)->perform_ra = (mvs_a - mvs_b);
		(*p)->cost = mvs_a;
	}
}

/*
 * Handles the case where A and B move in opposite directions.
 * - Determines the specific move direction for A (`ra` or `rra`).
 * - Determines the specific move direction for B (`rb` or `rrb`).
 * - Updates the corresponding perform values and the total cost.
 */
void	perform_3(t_p **p, int mvs_a, int mvs_b, int drctn_a)
{
	if (drctn_a == 1)
	{
		(*p)->perform_ra = mvs_a;
		(*p)->perform_rrb = mvs_b;
	}
	else
	{
		(*p)->perform_rra = mvs_a;
		(*p)->perform_rb = mvs_b;
	}		
	(*p)->cost = mvs_a + mvs_b;
}

/*
 * Handles the case where a move marked as `3` (either direction) 
 * needs to act as `rrr`.
 *
 * - Effectively behaves like `perform_1` but is applied 
 * when direction is uncertain.
 */
void	perform_4(t_p **p, int mvs_a, int mvs_b)
{
	if (mvs_a <= mvs_b)
	{
		(*p)->perform_rrr = mvs_a;
		(*p)->perform_rrb = (mvs_b - mvs_a);
		(*p)->cost = mvs_b;
	}
	else
	{
		(*p)->perform_rrr = mvs_b;
		(*p)->perform_rra = (mvs_a - mvs_b);
		(*p)->cost = mvs_a;
	}
}

/*

 * Handles the case where a move marked as `3` (either direction) 
 * needs to act as `rr`.
 *	- Effectively behaves like `perform_2` but is applied when 
 * direction is uncertain.
 */
void	perform_5(t_p **p, int mvs_a, int mvs_b)
{
	if (mvs_a <= mvs_b)
	{
		(*p)->perform_rr = mvs_a;
		(*p)->perform_rb = (mvs_b - mvs_a);
		(*p)->cost = mvs_b;
	}
	else
	{
		(*p)->perform_rr = mvs_b;
		(*p)->perform_ra = (mvs_a - mvs_b);
		(*p)->cost = mvs_a;
	}
}
