all:
	gcc -o cube cube.c dda.c -fsanitize=address -g -ldl -lglfw -lm -lpthread -LMLX42/build -lmlx42 -IMLX42/include
