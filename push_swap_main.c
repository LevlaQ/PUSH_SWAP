/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:53:02 by gyildiz           #+#    #+#             */
/*   Updated: 2025/02/26 19:17:36 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_plate	**stack_a;
	t_plate	**stack_b;
	
	if (!error_main(argc, argv)) //Error kontrollerinden geçti
		return (0);
	stack_a = ft_calloc(1, sizeof(t_list **));
	stack_b = ft_calloc(1, sizeof(t_list **));
	if (!to_the_stack_a_main(argc, argv, stack_a)) //stack'a ya sayılar alındı
		return (0);
	calc_acost_and_ptb(stack_a, stack_b);
	calc_bcost_and_pta(stack_a, stack_b);
	sort_me_if_im_not(stack_a);
}
