# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvico-ga <jvico-ga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/10 19:13:50 by agallipo          #+#    #+#              #
#    Updated: 2021/11/05 21:46:52 by jvico-ga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
SRCS	= ft_printf.c ft_tohexadecimal.c ft_strlen.c ft_putstr_fd.c ft_putchar_fd.c ft_topositive.c ft_itoa.c
OBJS	= $(SRCS:.c=.o)
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

all: $(NAME)

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS) 
clean:
			$(RM) $(OBJS)
			
fclean:		clean
	$(RM) $(NAME)
re:			fclean all
.PHONY:     bonus all clean fclean re
