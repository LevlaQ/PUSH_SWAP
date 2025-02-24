/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_ami_circular_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:12:48 by gyildiz           #+#    #+#             */
/*   Updated: 2025/02/24 19:38:17 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_plate	*find_max(t_plate **lst)
{
	t_plate	*iter;
	t_plate	*max_plate;
	
	iter = (*lst);
	max_plate = (*lst);
	while(iter)
	{
		if(iter->value > max_plate->value)
			max_plate = iter;
		iter = iter->next;
	}
	return (max_plate);
}
