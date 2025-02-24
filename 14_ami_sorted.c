/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   14_ami_sorted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:54:49 by gyildiz           #+#    #+#             */
/*   Updated: 2025/02/24 15:26:25 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//a listesi küçükten büyüğe sıralı mı kontrolü, ami circular'dan geçmiş yani dairesel olduğunu biliyorum
//Bu fonksiyon ancak programın sonunda B listesi tamamen boşaltıldığında çalıştırılmalı
void	sort_me_if_im_not(t_plate **sa)
{
	t_plate *min_value;
	int		way;
	int		mv_count;
	
	min_value = find_min(sa);
	if(min_value->index != 0)
	{
		way = r_or_rr(sa, min_value->index);
		mv_count = how_many_moves(sa, &min_value);
		if(way == 1 || way == 3)
			do_ra(mv_count, sa);
		else
			do_rra(mv_count, sa);
	}
	return ;
}
