
CC = gcc
FLAGS = -Wall -Wextra -Werror
SRC = flags.c	\
	  hex_convert.c	\
	  print_cs.c	\
	  print_nbr.c	\
	  width.c		\
	  print_po.c	\
	  printf.c		\
	  spacing.c

INC = ft_printf.h
AR = ar -rc
OBJ = $(SRC:.c=.o)
NAME = libftprintf.a
all : $(NAME)
$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
$(OBJ) : $(SRC)
	$(CC) $(FLAGS) -c $(SRC)
clean :
	rm -rf $(OBJ) $(OBJ_B)
fclean : clean
	rm -rf $(NAME)
re : fclean all
