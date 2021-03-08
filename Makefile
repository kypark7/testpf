# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kypark <kypark@studen.ft>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/08 17:57:01 by kypark            #+#    #+#              #
#    Updated: 2021/03/08 18:13:39 by kypark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_printf.c\
			ft_get.c\
			ft_type_c.c\
			ft_type_s.c\
			ft_type_p.c\
			ft_type_u.c\
			ft_type_d_i.c\
			ft_type_x.c\
			ft_printf_utils.c\
			ft_print.c\
			ft_size.c

OBJS	=	$(SRCS:.c=.o)

NAME	=	libftprintf.a

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra

RM		=	rm -f

$(NAME):	$(OBJS)
			@ar -rcs $(NAME) $(OBJS)

.c.o:
			@$(CC) $(CFLAGS) -c -I./ $< -o $(<:.c=.o)

all:		$(NAME)

allup:		$(NAME) clean

clean:
			@$(RM) $(OBJS)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
