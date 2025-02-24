/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12_do_as_isay.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 19:45:25 by gyildiz           #+#    #+#             */
/*   Updated: 2025/02/24 13:45:24 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	what_isit(t_plate **plate, t_plate **sa, t_plate **sb)
{
	if((*plate)->perform_rr != 0)
		do_rr((*plate)->perform_rr, sa, sb);
	if((*plate)->perform_rrr != 0)
		do_rrr((*plate)->perform_rrr, sa, sb);
	if((*plate)->perform_ra != 0)
		do_ra((*plate)->perform_ra, sa);
	if((*plate)->perform_rra != 0)
		do_rra((*plate)->perform_rra, sa);
	if((*plate)->perform_rb != 0)
		do_rb((*plate)->perform_rb, sb);
	if((*plate)->perform_rrb != 0)
		do_rrb((*plate)->perform_rrb, sb);
}

void	do_ra(int count, t_plate **sa)
{
	int	i;

	i = 0;
	while(i < count)
	{
		rotate_a(sa);
		printf("ra\n");
		i++;
	}
}

void	do_rra(int count, t_plate **sa)
{
	int	i;

	i = 0;
	while(i < count)
	{
		r_rotate_a(sa);
		printf("rra\n");
		i++;
	}
}

void	do_rb(int count, t_plate **sb)
{
	int	i;

	i = 0;
	while(i < count)
	{
		rotate_b(sb);
		printf("rb\n");
		i++;
	}
}
