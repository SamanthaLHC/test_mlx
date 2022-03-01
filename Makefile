NAME = test
SRCS = test2.c
OBJ = $(SRCS:%.c=%.o)
CC = cc 
$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME)
%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx -O3 -c $< -o $@
clean: 
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

all: $(NAME) 
	
re: fclean all
	
.PHONY: clean fclean all re 
