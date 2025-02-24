/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   13_do_as_isay.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:44:09 by gyildiz           #+#    #+#             */
/*   Updated: 2025/02/24 13:45:17 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rrb(int count, t_plate **sb)
{
	int	i;

	i = 0;
	while(i < count)
	{
		r_rotate_b(sb);
		printf("rrb\n");
		i++;
	}
}

void	do_rr(int count, t_plate **sa,t_plate **sb)
{
	int	i;

	i = 0;
	while(i < count)
	{
		rotate_ab(sa, sb);
		printf("rr\n");
		i++;
	}
}

void	do_rrr(int count, t_plate **sa,t_plate **sb)
{
	int	i;

	i = 0;
	while(i < count)
	{
		rr_ab(sa, sb);
		printf("rrr\n");
		i++;
	}
}