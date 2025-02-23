/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:20:52 by gyildiz           #+#    #+#             */
/*   Updated: 2025/02/23 18:44:10 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H


# include "./Libft/libft.h"
# include <unistd.h> //*read()* = ssize_t read(int fildes, void *buf, size_t nbyte); *write()* = ssize_t write(int fildes, const void *buf, size_t nbyte);
# include <stdlib.h> //malloc(); free (); exit() = void exit(int status); 
# include <stdio.h> // m1 çipte ft_printf çalışmıyor

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
} 	t_plate;

int		error_main(int argc, char **argv);
int		error_two_args(char **argv);
int 	error_multi_args(char **argv);
int		chk_if_string(char *str);
int		chk_spaces(char *str);
int		chk_chrctrs(char **el);
int		chk_integers_general(char **el);
int		chk_minmax(char **el);
int		modified_atoi_limits(char *str);
int		chk_if_repeats(char **el);
void	free_strings(char **strings);
int		to_the_stack_a_main(int argc, char **argv, t_plate **lst);
int		into_stack(int argc, char **el, t_plate **lst);
int		add_plate_front(t_plate **lst, int number);
void	index_the_stack(t_plate **lst);
void	push_to_a(t_plate **sa, t_plate **sb);
void	r_rotate_a(t_plate **sa);
void	r_rotate_b(t_plate **sb);
void	rr_ab(t_plate **sa, t_plate **sb);
void	push_to_b(t_plate **sa, t_plate **sb);
void	rotate_a(t_plate **sa);
void	rotate_b(t_plate **sb);
void	rotate_ab(t_plate **sa, t_plate **sb);
t_plate	*find_min(t_plate **lst);
int		is_sorted_from_min(t_plate **sa);
int		get_end_value(t_plate **lst);
int		ami_inorder_a(t_plate **sa);
t_plate	*find_max(t_plate **lst);
int		is_sorted_from_max(t_plate **sb);
int		ami_inorder_b(t_plate **sb);
int		m_last_index(t_plate **lst);
int 	r_or_rr(t_plate **lst, int my_index);
int		how_many_moves(t_plate **lst, t_plate **plate);
void	cost_perf_a(t_plate **sa, t_plate **sb, t_plate **a, t_plate **b);
void	cost_perf_b(t_plate **sa, t_plate **sb, t_plate **a, t_plate **b);
void	perform_1(t_plate **p, int mvs_a, int mvs_b);
void	perform_2(t_plate **p, int mvs_a, int mvs_b);
void	perform_3(t_plate **p, int mvs_a, int mvs_b, int drctn_a, int drctn_b);
void	perform_4(t_plate **p, int mvs_a, int mvs_b);
void	perform_5(t_plate **p, int mvs_a, int mvs_b);
t_plate	*my_target_in_b(int value, t_plate **sb);
t_plate *my_target_in_a(int value, t_plate **sa);

#endif 
