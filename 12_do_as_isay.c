/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12_do_as_isay.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 19:45:25 by gyildiz           #+#    #+#             */
/*   Updated: 2025/02/28 11:53:00 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Executes the appropriate move commands for the given plate.
 * - Calls rotation or reverse rotation functions based on stored values.
 * - Uses `perform_rr`, `perform_rrr`, `perform_ra`, `perform_rra`,
 *   `perform_rb`, and `perform_rrb` values from the plate struct.
 */
void	what_isit(t_p **plate, t_p **sa, t_p **sb)
{
	if ((*plate)->perform_rr != 0)
		do_rr((*plate)->perform_rr, sa, sb);
	if ((*plate)->perform_rrr != 0)
		do_rrr((*plate)->perform_rrr, sa, sb);
	if ((*plate)->perform_ra != 0)
		do_ra((*plate)->perform_ra, sa);
	if ((*plate)->perform_rra != 0)
		do_rra((*plate)->perform_rra, sa);
	if ((*plate)->perform_rb != 0)
		do_rb((*plate)->perform_rb, sb);
	if ((*plate)->perform_rrb != 0)
		do_rrb((*plate)->perform_rrb, sb);
}

/*
 * Performs `ra` (rotate stack A) `count` times.
 * - Moves the top element to the bottom of stack A.
 * - Prints "ra" for each operation performed.
 */
void	do_ra(int count, t_p **sa)
{
	int	i;

	i = 0;
	while (i < count)
	{
		rotate_a(sa);
		ft_printf("ra\n");
		i++;
	}
}

/*
 * Performs `rra` (reverse rotate stack A) `count` times.
 * - Moves the bottom element to the top of stack A.
 * - Prints "rra" for each operation performed.
 */
void	do_rra(int count, t_p **sa)
{
	int	i;

	i = 0;
	while (i < count)
	{
		r_rotate_a(sa);
		ft_printf("rra\n");
		i++;
	}
}

/*
 * Performs `rb` (rotate stack B) `count` times.
 * - Moves the top element to the bottom of stack B.
 * - Prints "rb" for each operation performed.
 */
void	do_rb(int count, t_p **sb)
{
	int	i;

	i = 0;
	while (i < count)
	{
		rotate_b(sb);
		ft_printf("rb\n");
		i++;
	}
}
