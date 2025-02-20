/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:53:02 by gyildiz           #+#    #+#             */
/*   Updated: 2025/02/20 13:25:49 by gyildiz          ###   ########.fr       */
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

}
