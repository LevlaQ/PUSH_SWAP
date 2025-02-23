/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_cost_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 13:00:45 by gyildiz           #+#    #+#             */
/*   Updated: 2025/02/23 13:51:50 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cost(int mvs_a, int mvs_b, int drctn_a, int drctn_b)
{
	if((drctn_a + drctn_b) == 0 || (drctn_a + drctn_b) == 2
		|| (drctn_a + drctn_b) == 3 || (drctn_a + drctn_b) == 4
		|| (drctn_a + drctn_b) == 6) //İkisi de aynı yöndedir
	{
		if(mvs_a >= mvs_b) //Birbirlerine eşit olmaları ihtimali de var
			return (mvs_a); //A daha büyükse maliyet odur
		else
			return (mvs_b); //B daha büyükse maliyet odur
	}
	else //İkisi farklı yönlerdedir
		return (mvs_a + mvs_b);
}

//Performansların tamamı A listesi taşlarına yazılıyor
void	cost_perf_a(t_plate **sa, t_plate **sb, t_plate **a, t_plate **b)
{
	int	mvs_a;
	int	mvs_b;
	int drctn_a;
	int drctn_b;

	mvs_a = how_many_moves(sa, a);
	mvs_b = how_many_moves(sb, b);
	drctn_a = r_or_rr(sa, (*a)->index);
	drctn_b = r_or_rr(sb, (*b)->index);
	if((drctn_a + drctn_b) == 0)
		perform_1(a, mvs_a, mvs_b);
	else if((drctn_a + drctn_b) == 2)
		perform_2(a, mvs_a, mvs_b);
	else if((drctn_a + drctn_b) == 1)
		perform_3(a, mvs_a, mvs_b, drctn_a, drctn_b);
	else if((drctn_a + drctn_b) == 3)
		perform_4(a, mvs_a, mvs_b);
	else if(((drctn_a + drctn_b) == 4) || ((drctn_a + drctn_b) == 6))
		perform_5(a, mvs_a, mvs_b);
	else
		return ;
}

//Performansların tamamı B listesi taşlarına yazılıyor
void	cost_perf_b(t_plate **sa, t_plate **sb, t_plate **a, t_plate **b)
{
	int	mvs_a;
	int	mvs_b;
	int drctn_a;
	int drctn_b;

	mvs_a = how_many_moves(sa, a);
	mvs_b = how_many_moves(sb, b);
	drctn_a = r_or_rr(sa, (*a)->index);
	drctn_b = r_or_rr(sb, (*b)->index);
	if((drctn_a + drctn_b) == 0)
		perform_1(b, mvs_a, mvs_b);
	else if((drctn_a + drctn_b) == 2)
		perform_2(b, mvs_a, mvs_b);
	else if((drctn_a + drctn_b) == 1)
		perform_3(b, mvs_a, mvs_b, drctn_a, drctn_b);
	else if((drctn_a + drctn_b) == 3)
		perform_4(b, mvs_a, mvs_b);
	else if(((drctn_a + drctn_b) == 4) || ((drctn_a + drctn_b) == 6))
		perform_5(b, mvs_a, mvs_b);
	else
		return ;
}
