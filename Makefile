CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
MLXFLAGS = -ldl -lglfw -lm -lpthread -LMLX42/build -lmlx42 -IMLX42/include
CFILES = main.c raycasting/textures.c raycasting/ray_main.c raycasting/player.c raycasting/map.c raycasting/utils.c raycasting/rays.c raycasting/raycaster.c parsing/fill_map.c parsing/parse_map.c parsing/parsing.c parsing/utils.c parsing/utils2.c gnl/get_next_line.c
OFILES = $(CFILES:.c=.o)
LIBFT = libft.a
NAME = cube

all: $(LIBFT) $(NAME)

$(LIBFT):
	cd ./libft && make

$(NAME): $(OFILES)
	$(CC) $(CFLAGS) $(OFILES) ./libft/$(LIBFT) $(MLXFLAGS) -o $(NAME)

%.o: %.c g_header.h 
	$(CC) $(CFLAGS) -IMLX42/include -c $< -o $@ 

clean:
	rm -rf $(OFILES) 
	cd ./libft && make clean

fclean: clean
	rm -rf $(NAME)
	cd ./libft && make fclean

re: fclean all
