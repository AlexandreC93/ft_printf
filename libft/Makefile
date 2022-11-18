CC = gcc
NAME = libft.a
AR = ar crs
SRC = \
	ft_strlen.c \
	ft_strtrim.c \
	ft_strjoin.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_strncmp.c \
	ft_strmapi.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_split.c \
	ft_memcmp.c \
	ft_calloc.c \
	ft_strchr.c \
	ft_strnstr.c \
	ft_memcpy.c \
	ft_atoi.c \
	ft_memset.c \
	ft_memmove.c \
	ft_memchr.c \
	ft_strdup.c \
	ft_striteri.c \
	ft_itoa.c \
	ft_substr.c \
	ft_putnbr_fd.c \
	ft_putendl_fd.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_strrchr.c \
	ft_bzero.c \
	ft_isprint.c \
	ft_isalpha.c \
	ft_isalnum.c \
	ft_isdigit.c \
	ft_isascii.c \

BONUS = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
		ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
		ft_lstmap.c ft_lstnew.c ft_lstsize.c

CFLAGS = -Wall -Wextra -Werror
RM = rm -f
OBJ = $(SRC:%.c=%.o)
BONUS_OBJS = $(BONUS:.c=.o)
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
