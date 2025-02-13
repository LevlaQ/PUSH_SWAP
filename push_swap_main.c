/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:53:02 by gyildiz           #+#    #+#             */
/*   Updated: 2025/02/13 20:22:25 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_plate	*stack_a;
	t_plate *stack_b;
	
	if (!error_main(argc, argv))
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	if (!to_the_stack_a_main(argc, argv, &stack_a))
		return (0);
	// t_plate *iter = stack_a;
	// while (iter != NULL)
	// {
	// 	printf("%d\n", iter -> value);
	// 	iter = iter -> next;	
	// }
	// printf("\n");
	// iter = stack_a;
	// r_rotate_a(&stack_a);
	// while (iter != NULL)
	// {
	// 	printf("%d\n", iter -> value);
	// 	iter = iter -> next;	
	// }
	// printf("\n");
	// iter = stack_a;
	// while (iter != NULL)
	// {
	// 	printf("%d\n", iter -> index);
	// 	iter = iter -> next;	
}
