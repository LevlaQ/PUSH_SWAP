/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_free_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 19:12:18 by gyildiz           #+#    #+#             */
/*   Updated: 2025/02/27 16:53:48 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_strings(char **strings)
{
	size_t	i;

	if (!strings)
		return;
	i = 0;
	while (strings[i])
	{
		free(strings[i]);
		i++;
	}
	free(strings);
}

void	free_stack_a(t_plate **sa)
{
	t_plate *temp;

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