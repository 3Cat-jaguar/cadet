NAME		=	cub3D 
CC		=	gcc
CFLAGS		=	-Wall -Wextra -Werror
FRAMEWORK	=	-framework OpenGL -framework Appkit
INCLUDE		=	-I ./includes 	
LIB			=	-L./my_libft -lft -lmlx
SRC			=	./srcs/buffer.c \
				./srcs/draw.c \
				./srcs/utils.c \
				./srcs/init.c \
				./srcs/key_event.c \
				./srcs/main.c \
				./srcs/parsing_utils.c \
				./srcs/parsing.c \
				./srcs/ray_casting.c \
				./srcs/read_file.c \
				./srcs/save.c \
				./srcs/sprite_utils.c \
				./srcs/sprite.c \
				./srcs/ray_casting_utils.c \
				./srcs/get_next_line.c \
				./srcs/get_next_line_utils.c \
				./srcs/array.c \
				./srcs/free.c
SRC_B		=	./bonus/buffer_bonus.c \
				./bonus/draw_bonus.c \
				./bonus/utils_bonus.c \
				./bonus/init_bonus.c \
				./bonus/bonus_bonus.c \
				./bonus/bonus_2_bonus.c \
				./bonus/key_event_bonus.c \
				./bonus/main_bonus.c \
				./bonus/parsing_utils_bonus.c \
				./bonus/parsing_bonus.c \
				./bonus/ray_casting_bonus.c \
				./bonus/read_file_bonus.c \
				./bonus/save_bonus.c \
				./bonus/sprite_utils_bonus.c \
				./bonus/sprite_bonus.c \
				./bonus/ray_casting_utils_bonus.c \
				./bonus/get_next_line_bonus.c \
				./bonus/get_next_line_utils_bonus.c \
				./bonus/array_bonus.c \
				./bonus/add_img_bonus.c \
				./bonus/free_bonus.c
OBJ			=	$(SRC:.c=.o)
OBJ_B		=	$(SRC_B:.c=.o)

all	: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(FRAMEWORK) $(INCLUDE) $(LIB)

bonus : $(OBJ_B)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ_B) $(FRAMEWORK) $(INCLUDE) $(LIB)
.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) $(INCLUDE)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
