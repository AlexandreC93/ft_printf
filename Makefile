CC = gcc
NAME = libftprintf.a
AR = ar crs
LIBFT = libft
SRC_DIR = srcs/
INCLUDES = includes

SRC = srcs/ft_printf.c \
	srcs/ft_printchar.c \
	srcs/ft_printptr.c \
	srcs/ft_printnum.c \

CFLAGS = -Wall -Wextra -Werror
RM = rm -f
OBJ = $(SRC:%.c=%.o)
BONUS_OBJS = $(BONUS:.c=.o)
all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT)
	@cp libft/libft.a .
	@mv libft.a $(NAME)
	$(AR) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
