NAME 	 = libftprintf.a
CC 		 = cc
CFLAGS 	 = -Wall -Wextra -Werror
AR 		 = ar rc
RM 		 = rm -f

FILES 	 =	ft_printf.c \
			ft_printf_utils.c

FILESB 	 =	ft_printf_bonus.c \
			ft_printf_utils_bonus.c\
			ft_printf_utils_bonus1.c

HEADERS	 =	ft_printf.h

HEADERSB =	ft_printf_bonus.h

OBJS     = ${FILES:.c=.o}
OBJSB    = ${FILESB:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^
	
%.o: %.c $(HEADERS) $(HEADERSB)
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OBJSB)
	$(AR) $(NAME) $^

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJSB)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re