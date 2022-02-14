# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yjoo <yjoo@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/11 17:51:37 by yjoo              #+#    #+#              #
#    Updated: 2022/02/11 17:51:37 by yjoo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft
AR = ar rcs
NAME = libftprintf.a
SRCS = ft_printf.c\
		ft_print_hex.c\
		ft_print_nbr.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o : %.c
		$(CC) $(CFLAGS) -c $?

$(NAME) : $(OBJS)
		@make -C $(LIBFT)
		@cp libft/libft.a .
		@mv libft.a $(NAME)
		@$(AR) $(NAME) $(OBJS)
		@echo "ft_printf_success"

clean:
		rm -f $(OBJS) $(OBJS_BONUS)
		@make clean -C $(LIBFT)

fclean: clean
		rm -f $(NAME)
		rm -f $(LIBFT)/libft.a

re: fclean all

.PHONY: all clean fclean re
