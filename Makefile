NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rc
RM = rm -f

FILES = ft_printf.c \
		ft_printf_utils.c \

OBJS = ft_printf.o \
	ft_printf_utils.o \


all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^
	
%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re