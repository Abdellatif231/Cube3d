CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -ldl -lglfw -lm -lpthread -LMLX42/build -lmlx42 -IMLX42/include
CFILES = main.c player.c map.c utils.c dda.c 
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
