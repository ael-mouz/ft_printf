NAME 	= libftprintf.a
CC 		= cc
CFLAGS 	= -Wall -Wextra -Werror
AR 		= ar rc
RM 		= rm -f

FILES 	=	mandatory/ft_printf.c \
			mandatory/ft_printf_utils.c

FILESB 	=	bonus/ft_printf_bonus.c \
			bonus/ft_printf_utils_bonus.c\
			bonus/ft_printf_utils_bonus1.c

HEADERS	=	mandatory/ft_printf.h

HEADERSB	=	bonus/ft_printf_bonus.h

OBJS = ${FILES:.c=.o}
OBJSB = ${FILESB:.c=.o}

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	$(AR) $@ $<
	
%.o: %.c $(HEADERS) $(HEADERSB)
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OBJSB) fclean
	$(AR) $@ $<

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re