/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:20:52 by gyildiz           #+#    #+#             */
/*   Updated: 2025/02/08 17:53:01 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include "./Libft/libft.h"
# include <unistd.h> //*read()* = ssize_t read(int fildes, void *buf, size_t nbyte); *write()* = ssize_t write(int fildes, const void *buf, size_t nbyte);
# include <stdlib.h> //malloc(); free (); exit() = void exit(int status); 

typedef struct s_plate
{
	int				index;
	int				value;
	struct s_plate	*next;
} t_plate;

int	chk_string(char *str);
int	chk_spaces(char *str);



#endif 
