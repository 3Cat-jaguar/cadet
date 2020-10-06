CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRCS = ft_strlen.c\
	   ft_strlcpy.c

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
