/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:53:02 by gyildiz           #+#    #+#             */
/*   Updated: 2025/02/28 15:47:47 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_p	**stack_a;
	t_p	**stack_b;

	if (!error_main(argc, argv))
		return (0);
	stack_a = ft_calloc(1, sizeof(t_p **));
	stack_b = ft_calloc(1, sizeof(t_p **));
	if (!to_the_stack_a_main(argc, argv, stack_a))
		return (0);
	if (m_last_index(stack_a) == 2)
	{
		the_three(stack_a);
		return (0);
	}
	calc_acost_and_ptb(stack_a, stack_b);
	calc_bcost_and_pta(stack_a, stack_b);
	sort_me_if_im_not(stack_a);
	free_stack_a(stack_a);
	free(stack_a);
	free(stack_b);
}
