NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

FILES = ft_printf.c \
		ft_printf_func.c

OBJ = $(FILES:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJ)
		ar rcs $(NAME) $(OBJ)

%.o : %.cc
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ) : ft_printf.h

clean:
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
