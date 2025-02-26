/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   15_calculate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:31:44 by gyildiz           #+#    #+#             */
/*   Updated: 2025/02/26 18:13:53 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//A dolu mu boş mu kontrolü yapmıyorum çünkü error'lar onu kontrol ediyoru
//A daiesel sıralı olana kadar bu fonksiyonum çalışmaya devam etti
//A'nın dairesel sıralı olduğu senaryoda bu fonksiyonun çalışmaması lazım
void	calc_acost_and_ptb(t_plate **sa, t_plate **sb)
{
	t_plate	*iter_a;
	t_plate *target;
	t_plate	*min_cost;
	
	while(!ami_inorder_a(sa)) //A dairesel sıralı olmadığı sürece
	{
		if(!(*sb)) //Eğer be listesi boş ise
		{
			push_to_b(sa, sb); //İçerisine hemen bir eleman at
			printf("pb\n");
		}
		iter_a = (*sa);
		while(iter_a) //Liste sonuna varmadığım sürece
		{
			target = my_target_in_b(iter_a->value, sb); //A'daki mevcut taşım için B'deki hedef taşını bul
			cost_perf_a(sa, sb, &iter_a, &target); //Mavcut ve hedef taş bilgilerinden maliyet ve performans hesabı yap
			iter_a = iter_a->next;
		}
		min_cost = find_min_cost(sa); //Yukarıda girilen bilgilere göre minimum maliyeti içeren taşı bul
		what_isit(&min_cost, sa, sb); //Taşta yazan hamleleri gerçekleştir, o hamleler o fonksiyonların içinde ekrana yazılacak
		push_to_b(sa, sb); //İlgili rotate'ler ile ilgili taşlar tepeye taşındı, şimdi pushlama vakti
		printf("pb\n");
		iter_a = (*sa);
	}
}


//B'den A'ya pushlama senaryosunda A'da eleman olmama ihtimali olmayacak
//B'de eleman olmaması durumunda bu fonksiyonun çalışmaması lazım
void	calc_bcost_and_pta(t_plate **sa, t_plate **sb)
{
	t_plate	*iter_b;
	t_plate *target;
	t_plate	*min_cost;
	
	while(*sb) //B'de eleman kalmayana kadar, çünkü B'de ve A'da her şey dairesel sıralı olmalı bu noktada
	{
		iter_b = (*sb);
		while(iter_b) //Liste sonuna varmadığım sürece
		{
			printf("Find target for: %d\n", iter_b->value);
			target = my_target_in_a(iter_b->value, sa); //B'deki mevcut taşım için A'daki hedef taşını bul
			printf("My target is : %d\n", target->value);
			cost_perf_b(sa, sb,  &target, &iter_b); //Mavcut ve hedef taş bilgilerinden maliyet ve performans hesabı yap ve B'ye yaz
			printf("My cost is: %d\n\n", iter_b->cost);
			iter_b = iter_b->next;
		}
		min_cost = find_min_cost(sb); //Yukarıda girilen bilgilere göre minimum maliyeti içeren taşı bul
		printf("Min_cost value is: %d\n", min_cost->value);
		printf("Perform rr: %d\n", min_cost->perform_rr);
		printf("Perfrom rrr: %d\n", min_cost->perform_rrr);
		printf("Perform ra: %d\n", min_cost->perform_ra);
		printf("Perfrom rra : %d\n", min_cost->perform_rra);
		printf("Perform rb : %d\n", min_cost->perform_rb);
		printf("Perform rrb : %d\n", min_cost->perform_rrb);
		what_isit(&min_cost, sa, sb); //Taşta yazan hamleleri gerçekleştir, o hamleler o fonksiyonların içinde ekrana yazılacak
		push_to_a(sa, sb); //İlgili rotate'ler ile ilgili taşlar tepeye taşındı, şimdi pushlama vakti
		printf("pa\n");
		iter_b = (*sb);
		reset_performs(&iter_b);
	}
}

void	reset_performs(t_plate **lst)
{
	t_plate	*iter;
	
	iter = (*lst);
	while(iter)
	{
		iter->perform_rr = 0;
		iter->perform_rrr = 0;
		iter->perform_ra = 0;
		iter->perform_rra = 0;
		iter->perform_rb = 0;
		iter->perform_rrb = 0;
		iter->cost = 0;
		iter = iter->next;
	}
}