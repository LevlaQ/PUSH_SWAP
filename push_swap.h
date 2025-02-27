/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:20:52 by gyildiz           #+#    #+#             */
/*   Updated: 2025/02/27 19:37:18 by gyildiz          ###   ########.fr       */
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
}					t_plate;

int					error_main(int argc, char **argv);
int					error_two_args(char **argv);
int					error_multi_args(char **argv);
int					chk_if_string(char *str);
int					chk_spaces(char *str);
int					chk_chrctrs(char **el);
int					chk_integers_general(char **el);
int					chk_minmax(char **el);
int					modified_atoi_limits(char *str);
int					chk_if_repeats(char **el);
void				free_strings(char **strings);
int					to_the_stack_a_main(int argc, char **argv, t_plate **lst);
int					into_stack(int argc, char **el, t_plate **lst);
int					add_plate_front(t_plate **lst, int number);
void				index_the_stack(t_plate **lst);
void				push_to_a(t_plate **sa, t_plate **sb);
void				r_rotate_a(t_plate **sa);
void				r_rotate_b(t_plate **sb);
void				rr_ab(t_plate **sa, t_plate **sb);
void				push_to_b(t_plate **sa, t_plate **sb);
void				rotate_a(t_plate **sa);
void				rotate_b(t_plate **sb);
void				rotate_ab(t_plate **sa, t_plate **sb);
t_plate				*find_min(t_plate **lst);
int					is_sorted_from_min(t_plate **sa);
int					get_end_value(t_plate **lst);
int					ami_inorder_a(t_plate **sa);
t_plate				*find_max(t_plate **lst);
int					m_last_index(t_plate **lst);
int					r_or_rr(t_plate **lst, int my_index);
int					how_many_moves(t_plate **lst, t_plate **plate);
void				cost_perf_a(t_plate **sa, t_plate **sb, t_plate **a,
						t_plate **b);
void				cost_perf_b(t_plate **sa, t_plate **sb, t_plate **a,
						t_plate **b);
void				perform_1(t_plate **p, int mvs_a, int mvs_b);
void				perform_2(t_plate **p, int mvs_a, int mvs_b);
void				perform_3(t_plate **p, int mvs_a, int mvs_b, int drctn_a,
						int drctn_b);
void				perform_4(t_plate **p, int mvs_a, int mvs_b);
void				perform_5(t_plate **p, int mvs_a, int mvs_b);
t_plate				*my_target_in_b(int value, t_plate **sb);
t_plate				*my_target_in_a(int value, t_plate **sa);
void				what_isit(t_plate **plate, t_plate **sa, t_plate **sb);
void				do_ra(int count, t_plate **sa);
void				do_rra(int count, t_plate **sa);
void				do_rb(int count, t_plate **sb);
void				do_rrb(int count, t_plate **sb);
void				do_rr(int count, t_plate **sa, t_plate **sb);
void				do_rrr(int count, t_plate **sa, t_plate **sb);
t_plate				*find_min_cost(t_plate **lst);
void				sort_me_if_im_not(t_plate **sa);
void				calc_acost_and_ptb(t_plate **sa, t_plate **sb);
void				calc_bcost_and_pta(t_plate **sa, t_plate **sb);
void				reset_performs(t_plate **lst);
void				free_stack_a(t_plate **sa);

#endif
