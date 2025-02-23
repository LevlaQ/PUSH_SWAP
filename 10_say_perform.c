/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   say_perform.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 12:49:46 by gyildiz           #+#    #+#             */
/*   Updated: 2025/02/23 13:50:28 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//0 0 (rrr) durumunda yapılacak hamleleri struct'a yazmak için fonksiyon
void	perform_1(t_plate **p, int mvs_a, int mvs_b)
{
	if(mvs_a <= mvs_b)
	{
		(*p)->perform_rrr = mvs_a;
		(*p)->perform_rrb = (mvs_b - mvs_a);
	}		
	else
	{
		(*p)->perform_rrr = mvs_b;
		(*p)->perform_rra = (mvs_a - mvs_b);
	}
}

// 1 1 (rr) durumunda yapılacak hamleleri struct'a yazacak fonksiyon
void	perform_2(t_plate **p, int mvs_a, int mvs_b)
{
	if (mvs_a <= mvs_b)
	{
		(*p)->perform_rr = mvs_a;
		(*p)->perform_rb = (mvs_b - mvs_a);
	}		
	else
	{
		(*p)->perform_rr = mvs_b;
		(*p)->perform_ra = (mvs_a - mvs_b);
	}
}

//1 0 farklı yönlere gitmeleri kesin durumunda yapılacak hamleleri struct'a yazacak fonksiyon
void	perform_3(t_plate **p, int mvs_a, int mvs_b, int drctn_a, int drctn_b)
{
	if (drctn_a == 1)
		(*p)->perform_ra = mvs_a;
	else if (drctn_a == 0)
		(*p)->perform_rra = mvs_a;
	else if (drctn_b == 1)
		(*p)->perform_rb = mvs_b;
	else if (drctn_b == 0)
		(*p)->perform_rrb = mvs_b;
	else
		return ;
}

//3 0/0 3 durumları için rrr gibi çalışacak bir fonksiyon
void	perform_4(t_plate **p, int mvs_a, int mvs_b)
{

	if(mvs_a <= mvs_b)
	{
		(*p)->perform_rrr = mvs_a;
		(*p)->perform_rrb = (mvs_b - mvs_a);
	}
	else
	{
		(*p)->perform_rrr = mvs_b;
		(*p)->perform_rra = (mvs_a - mvs_b);
	}
}

//3 3/3 1 durumlaru için rr gibi çalışacak bir fonksiyon
void	perform_5(t_plate **p, int mvs_a, int mvs_b)
{
	if (mvs_a <= mvs_b)
	{
		(*p)->perform_rr = mvs_a;
		(*p)->perform_rb = (mvs_b - mvs_a);
	}		
	else
	{
		(*p)->perform_rr = mvs_b;
		(*p)->perform_ra = (mvs_a - mvs_b);
	}
}