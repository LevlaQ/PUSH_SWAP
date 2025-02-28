/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:20:52 by gyildiz           #+#    #+#             */
/*   Updated: 2025/02/28 11:55:03 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# include "./Libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_plate
{
	int				index;
	int				value;
	int				cost;
	int				perform_rr;
	int				perform_rrr;
	int				perform_ra;
	int				perform_rra;
	int				perform_rb;
	int				perform_rrb;
	struct s_plate	*next;
	struct s_plate	*prev;
}					t_p;

int		error_main(int argc, char **argv);
int		error_two_args(char **argv);
int		error_multi_args(char **argv);
int		chk_if_string(char *str);
int		chk_spaces(char *str);
int		chk_chrctrs(char **el);
int		chk_integers_general(char **el);
int		chk_minmax(char **el);
int		modified_atoi_limits(char *str);
int		chk_if_repeats(char **el);
void	free_strings(char **strings);
int		to_the_stack_a_main(int argc, char **argv, t_p **lst);
int		into_stack(int argc, char **el, t_p **lst);
int		add_plate_front(t_p **lst, int number);
void	index_the_stack(t_p **lst);
void	push_to_a(t_p **sa, t_p **sb);
void	r_rotate_a(t_p **sa);
void	r_rotate_b(t_p **sb);
void	rr_ab(t_p **sa, t_p **sb);
void	push_to_b(t_p **sa, t_p **sb);
void	rotate_a(t_p **sa);
void	rotate_b(t_p **sb);
void	rotate_ab(t_p **sa, t_p **sb);
t_p		*find_min(t_p **lst);
int		is_sorted_from_min(t_p **sa);
int		get_end_value(t_p **lst);
int		ami_inorder_a(t_p **sa);
t_p		*find_max(t_p **lst);
int		m_last_index(t_p **lst);
int		r_or_rr(t_p **lst, int my_index);
int		how_many_moves(t_p **lst, t_p **plate);
void	cost_perf_a(t_p **sa, t_p **sb, t_p **a, t_p **b);
void	cost_perf_b(t_p **sa, t_p **sb, t_p **a, t_p **b);
void	perform_1(t_p **p, int mvs_a, int mvs_b);
void	perform_2(t_p **p, int mvs_a, int mvs_b);
void	perform_3(t_p **p, int mvs_a, int mvs_b, int drctn_a);
void	perform_4(t_p **p, int mvs_a, int mvs_b);
void	perform_5(t_p **p, int mvs_a, int mvs_b);
t_p		*my_target_in_b(int value, t_p **sb);
t_p		*my_target_in_a(int value, t_p **sa);
void	what_isit(t_p **plate, t_p **sa, t_p **sb);
void	do_ra(int count, t_p **sa);
void	do_rra(int count, t_p **sa);
void	do_rb(int count, t_p **sb);
void	do_rrb(int count, t_p **sb);
void	do_rr(int count, t_p **sa, t_p **sb);
void	do_rrr(int count, t_p **sa, t_p **sb);
t_p		*find_min_cost(t_p **lst);
void	sort_me_if_im_not(t_p **sa);
void	calc_acost_and_ptb(t_p **sa, t_p **sb);
void	calc_bcost_and_pta(t_p **sa, t_p **sb);
void	reset_performs(t_p **lst);
void	free_stack_a(t_p **sa);

#endif
