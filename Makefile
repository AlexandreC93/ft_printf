CC = gcc
NAME = libftprintf.a
AR = ar crs
SRC = ft_printf.c \
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
OBJ = $(SRC:%.c=%.o)
BONUS_OBJS = $(BONUS:.c=.o)
.c.o: $(SRC)
	$(CC) -o $@ -c $< $(CFLAGS)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $@ $^

clean:
	$(RM) $(OBJ) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

bonus:	$(OBJS) $(BONUS_OBJS)
	ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

re: fclean all

.PHONY: all clean fclean re bonus
