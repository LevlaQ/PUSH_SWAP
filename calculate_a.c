/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:31:44 by gyildiz           #+#    #+#             */
/*   Updated: 2025/02/20 13:51:59 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int calc_acost_and_ptb(t_plate **sa, t_plate **sb)
{
	if (!ami_inorder_a(sa) && !(*sb)) //Eğer a sıralı değilse ve b boş ise (ki ilk çağırışım boş olması lazım)
	{
		push_to_b(sa, sb);//B'ye bir eleman at
		printf("pb\n");
	}
	while(!ami_inorder_a(sa))
	{
		
	}
}

int find_my_target_in_b(t_plate **sa, t_plate **sb)
{
	
}