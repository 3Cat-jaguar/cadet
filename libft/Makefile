CC = gcc
CFLAG = -Wall -Wextra -Werror


libft.a : ft_strlen.o
	ar rc libft.a ft_strlen.o

ft_strlen.o : ft_strlen.c
	gcc -c ft_strlen.c

clean : 
	rm *.o libft.a	
