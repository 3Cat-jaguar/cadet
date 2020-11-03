CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRCS = ft_printf.c\
	   ft_itoa_base16.c\
	   ft_toupper_str.c 

OBJECTS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(MAKE) bonus -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(CFLAGS) -c $(SRCS) libft/libft.h
	ar rcs $(NAME) $(OBJECTS)

bonus : $(OBJECTS) $(B_OBJS)
	ar rc $(NAME) $^


$(B_OBJS) : $(B_SRCS)
	$(CC) $(CFLAGS) -c $^

clean :
	$(MAKE)	clean -C ./libft
	rm -f $(OBJECTS)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re : fclean all
