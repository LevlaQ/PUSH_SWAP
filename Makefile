# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyildiz <gyildiz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/06 18:46:08 by gyildiz           #+#    #+#              #
#    Updated: 2025/02/24 19:50:58 by gyildiz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =			00_error_functions.c 01_error_helpers.c 02_free_funcs.c\
				03_take_into_stack.c 04_moves.c 05_movess.c 06_ami_circular_a.c\
				07_ami_circular_b.c 08_my_cost_main.c 09_my_cost.c\
				10_say_perform.c 11_the_target.c 12_do_as_isay.c\
				13_do_as_isay.c 14_ami_sorted.c 15_calculate.c\
				
OBJS =			$(SRCS:.c=.o)

NAME =			libftpushswap.a
LIBFT =			./Libft/libft.a

CC =			cc
CFLAGS =		-Wall -Wextra -Werror

all:			$(LIBFT) $(NAME)

$(NAME):		$(OBJS)
				cp $(LIBFT) $(NAME)
				ar -rcs $(NAME) $(OBJS)

$(LIBFT):
				make -C ./Libft all

fclean: clean
				rm -rf $(NAME)
				make -C ./Libft fclean

clean: 
				rm -rf $(OBJS)
				make -C ./Libft clean

re: fclean all

.PHONY: all fclean clean re