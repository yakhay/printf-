# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/23 13:59:19 by yakhay            #+#    #+#              #
#    Updated: 2022/11/02 12:35:40 by yakhay           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c		\
		ft_putadd.c		\
		ft_putchar.c		\
		ft_putnbr.c		\
		ft_putstr.c 	\
		ft_putUint.c		\
		ft_putxh.c		\

OBJS = $(SRCS:.c=.o)

RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= libftprintf.a

all:			$(NAME)

$(NAME):$(OBJS)	
	ar -rc $(NAME) $?

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)


.PHONY:			all clean fclean re bonus
