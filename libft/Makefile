CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRCS = ft_strlen.c\
	   ft_strlcpy.c\
	   ft_strlcat.c\
	   ft_isalpha.c\
	   ft_isdigit.c\
	   ft_isalnum.c\
	   ft_isascii.c\
	   ft_isprint.c\
	   ft_toupper.c\
	   ft_tolower.c\
	   ft_atoi.c\
	   ft_strchr.c\
	   ft_memset.c\
	   ft_bzero.c\
	   ft_memcpy.c

OBJECTS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECTS)
	ar rc $@ $^

$(OBJECTS): $(SRCS)
	$(CC) $(CFLAGS) -c $^

clean : 
	rm -f $(OBJECTS)

fclean : clean
	rm -f $(NAME)

re : fclean clean all
