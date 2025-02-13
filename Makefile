# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyildiz <gyildiz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/06 18:46:08 by gyildiz           #+#    #+#              #
#    Updated: 2025/02/13 20:16:03 by gyildiz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =			error_functions.c error_helpers.c free_funcs.c\
				take_into_stack.c moves.c movess.c 
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