CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
MLXFLAGS = -ldl -lglfw -lm -lpthread -LMLX42/build -lmlx42 -IMLX42/include
CFILES = raycasting/main.c raycasting/player.c raycasting/map.c raycasting/utils.c raycasting/rays.c raycasting/raycaster.c 
OFILES = $(CFILES:.c=.o)
NAME = cube

all: $(NAME)

$(NAME): $(OFILES)
	$(CC) $(CFLAGS) $(OFILES) $(MLXFLAGS) -o $(NAME)

%.o: %.c cube.h
	$(CC) $(CFLAGS) -IMLX42/include -c $< -o $@ 

clean:
	rm -rf $(OFILES) 

fclean: clean
	rm -rf $(NAME)

re: fclean all
