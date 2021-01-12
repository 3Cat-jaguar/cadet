CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRCS = ft_printf.c\
	   ft_uitoa_base16.c\
	   ft_toupper_str.c\
	   ft_put_unsigned_int_fd.c\
	   ft_ultoa_base16.c\
	   ft_ulltoa_base16.c\
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
	   print_type_percent.c\
	   apply_width.c\
	   apply_precision.c\
	   ft_lltoa.c\
	   ft_ltoa.c\
	   ft_ultoa.c\
	   ft_ulltoa.c\
	   print_type_n.c\
	   print_type_f.c\
	   print_type_g.c\
	   print_type_e.c\
	   modify_str_by_arg_bonus.c\
	   print_type_n.c\
	   print_type_f.c\
	   print_type_g.c\
	   print_type_e.c\
	   modify_str_by_arg_bonus.c\
	   testf.c


OBJECTS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(MAKE) bonus -C ./../libft
	cp ../libft/libft.a $(NAME)
	$(CC) $(CFLAGS) -c $(SRCS)
	ar rcs $(NAME) $(OBJECTS)

bonus : all

clean :
	$(MAKE)	clean -C ./../libft
	rm -f $(OBJECTS) $(B_OBJS)

fclean : clean
	$(MAKE)	fclean -C ./../libft
	rm -f $(NAME)

re : fclean all
