NAME = libftprintf.a

CC = gcc

CFLAGS = -g -Wall -Werror -Wextra

LIBFT = ./libft/libft.a

HEADER = -I ft_printf.h

SOURCE = ./ft_printf ./ft_saveformat\

SRC = $(addsuffix .c,$(SOURCE))

OBJ = $(addsuffix .o,$(SOURCE))

all : $(NAME)

$(LIBFT):
		make -C libft/

$(NAME): $(LIBFT) $(OBJ) 
		cp $(LIBFT) $(NAME)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

$(OBJ):
	$(CC) $(CFLAGS) -c $(SRC)

clean:
		make -C ./libft clean
		rm -rf $(OBJ)

fclean: clean
		make -C ./libft fclean
		rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re