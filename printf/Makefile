CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRCS = ft_printf.c\
	   ft_itoa_base16.c\
	   ft_toupper_str.c\
	   ft_put_unsigned_int_fd.c\
	   ft_lltoa_base16.c\
	   ft_uitoa.c\
	   find_percent.c\
	   ft_init_arg_list.c\
	   check_flags.c\
	   check_specifier.c\
	   width_or_precision.c\
	   check_length.c\
	   modify_str_by_arg.c\
	   print_type_d.c\
	   print_type_c.c\
	   print_type_s.c\
	   print_type_u.c\
	   print_type_x.c\
	   print_type_x_upper.c\
	   print_type_p.c\

OBJECTS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(MAKE) bonus -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(CFLAGS) -c $(SRCS)
	ar rcs $(NAME) $(OBJECTS)

bonus : $(OBJECTS) $(B_OBJS)
	ar rc $(NAME) $^


$(B_OBJS) : $(B_SRCS)
	$(CC) $(CFLAGS) -c $^

clean :
	$(MAKE)	clean -C ./libft
	rm -f $(OBJECTS)

fclean : clean
	rm -f $(NAME)

re : fclean all
