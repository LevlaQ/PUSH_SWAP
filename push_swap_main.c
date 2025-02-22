/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:53:02 by gyildiz           #+#    #+#             */
/*   Updated: 2025/02/22 14:22:56 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_plate	*stack_a;
	t_plate *stack_b;
	
	if (!error_main(argc, argv)) //Error kontrollerinden geçti
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	if (!to_the_stack_a_main(argc, argv, &stack_a)) //stack'a ya sayılar alındı
		return (0);
	
	//Hamle hesaplamaları kontrolü
	// t_plate *plate;
	// plate = stack_a;
	// while(plate)
	// {
	// 	tactics_into_plates(&plate, &stack_a);
	// 	plate = plate->next;
	// }
	// plate = stack_a;
	// while(plate)
	// {
	// 	printf("%d = my index\n", plate->index);
	// 	printf("%d = r_moves\n", plate->moves_r);
	// 	printf("%d = rr_moves\n", plate->moves_rr);
	// 	printf("\n");
	// 	plate = plate->next;
	// }

}
