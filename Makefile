# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyildiz <gyildiz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/06 18:46:08 by gyildiz           #+#    #+#              #
#    Updated: 2025/02/27 19:00:40 by gyildiz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =			00_error_functions.c 01_error_helpers.c 02_free_funcs.c\
				03_take_into_stack.c 04_moves.c 05_movess.c 06_ami_circular_a.c\
				08_my_cost_main.c 09_my_cost.c\
				10_say_perform.c 11_the_target.c 12_do_as_isay.c\
				13_do_as_isay.c 14_ami_sorted.c 15_calculate.c\
				push_swap_main.c
				
OBJS =			$(SRCS:.c=.o)

EXE_NAME =		push_swap

LIBFT =			./Libft/libft.a

CC =			cc
CFLAGS =		-Wall -Wextra -Werror

all:			$(LIBFT) $(EXE_NAME)

$(EXE_NAME):	$(OBJS) $(LIBFT)
				$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(EXE_NAME)

$(LIBFT):
				make -C ./Libft all

fclean: clean
				rm -rf $(EXE_NAME)
				make -C ./Libft fclean

clean: 
				rm -rf $(OBJS)
				make -C ./Libft clean

re: fclean all

.PHONY: all fclean clean re