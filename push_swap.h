/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:20:52 by gyildiz           #+#    #+#             */
/*   Updated: 2025/02/09 19:23:28 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include "./Libft/libft.h"
# include <unistd.h> //*read()* = ssize_t read(int fildes, void *buf, size_t nbyte); *write()* = ssize_t write(int fildes, const void *buf, size_t nbyte);
# include <stdlib.h> //malloc(); free (); exit() = void exit(int status); 
# include <stdio.h> // m1 çipte ft_printf çalışmıyor

typedef struct s_plate
{
	int				index;
	int				value;
	struct s_plate	*next;
} t_plate;

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


#endif 
