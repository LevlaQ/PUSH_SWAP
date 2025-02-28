/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_free_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 19:12:18 by gyildiz           #+#    #+#             */
/*   Updated: 2025/02/28 15:49:20 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_strings(char **strings)
{
	size_t	i;

	if (!strings)
		return ;
	i = 0;
	while (strings[i])
	{
		free(strings[i]);
		i++;
	}
	free(strings);
}

void	free_stack_a(t_p **sa)
{
	t_p	*temp;

	if (!sa || !(*sa))
		return ;
	while (*sa)
	{
		temp = (*sa)->next;
		free(*sa);
		*sa = temp;
	}
	*sa = NULL;
}

/*
 * Moves elements from stack B back to stack A after stack A is sorted.
 * - Ensures that elements are placed in their correct position in A.
 * - Continues until stack B is empty.
 */
void	reset_performs(t_p **lst)
{
	t_p	*iter;

	iter = (*lst);
	while (iter)
	{
		iter->perform_rr = 0;
		iter->perform_rrr = 0;
		iter->perform_ra = 0;
		iter->perform_rra = 0;
		iter->perform_rb = 0;
		iter->perform_rrb = 0;
		iter->cost = 0;
		iter = iter->next;
	}
}
