CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

all : $(NAME)

$(NAME) :
	$(MAKE) -C ./ft_printf_mandatory
	cp ft_printf_mandatory/libftprintf.a $(NAME)

bonus :
	$(MAKE) -C ./ft_printf_bonus
	cp ft_printf_bonus/libftprintf.a $(NAME)

clean :
	$(MAKE)	clean -C ./ft_printf_mandatory
	$(MAKE)	clean -C ./ft_printf_bonus

fclean : clean
	$(MAKE)	fclean -C ./ft_printf_mandatory
	$(MAKE)	fclean -C ./ft_printf_bonus
	rm -f $(NAME)

re : fclean all
