/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   13_do_as_isay.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:44:09 by gyildiz           #+#    #+#             */
/*   Updated: 2025/02/28 11:53:00 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Performs `rrb` (reverse rotate stack B) `count` times.
 * - Moves the bottom element of stack B to the top.
 * - Prints "rrb" for each operation performed.
 */
void	do_rrb(int count, t_p **sb)
{
	int	i;

	i = 0;
	while (i < count)
	{
		r_rotate_b(sb);
		ft_printf("rrb\n");
		i++;
	}
}

/*
 * Performs `rr` (rotate both stack A and B simultaneously)
 * `count` times.
 * - Moves the top element of stack A and B to the bottom.
 * - Prints "rr" for each operation performed.
 */
void	do_rr(int count, t_p **sa, t_p **sb)
{
	int	i;

	i = 0;
	while (i < count)
	{
		rotate_ab(sa, sb);
		ft_printf("rr\n");
		i++;
	}
}

/*
 * Performs `rrr` (reverse rotate both 
 *stack A and B simultaneously) `count` times.
 * - Moves the bottom element of stack A and B to the top.
 * - Prints "rrr" for each operation performed.
 */
void	do_rrr(int count, t_p **sa, t_p **sb)
{
	int	i;

	i = 0;
	while (i < count)
	{
		rr_ab(sa, sb);
		ft_printf("rrr\n");
		i++;
	}
}
