CC=gcc

CFLAGS=-Wall -Wextra -Werror

OBJ_DIR=obj

MLX=mlx/libmlx_Darwin.a

LIBFT=libft/libft.a

I_LIBFT=-Ilibft -Llibft -lft

I_LIBMLX=-Imlx -Lmlx -lmlx

LIB=$(I_LIBFT) $(I_LIBMLX)

COMPATIBILITY=-lX11 -lXext

FRAMEWORK=-framework OpenGL -framework AppKit

APP=FdF.c

all: $(LIBFT) app

$(LIBFT):
	make -C libft
	@echo "done libft"

$(OBJ_DIR):
	mkdir $@

app:
	@echo "making app"
	$(CC) $(CFLAGS) $(LIB) $(APP) $(FRAMEWORK) -o FdF

clean:
	make -C libft $@

fclean: clean
	rm server
	rm client
	make -C libft $@

re: fclean all

.PHONY: all clean fclean re so