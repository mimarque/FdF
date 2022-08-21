CC=gcc

CFLAGS=-Wall -Wextra -Werror

MLX=mlx/libmlx_Linux.a

LIBFT=libft/libft.a

I_LIBFT=-Ilibft -Llibft -lft

I_LIBMLX=-Imlx -Lmlx -lmlx

LIB=$(I_LIBFT) $(I_LIBMLX)

COMPATIBILITY=-lX11 -lXext -lm

FRAMEWORK=-framework OpenGL -framework AppKit

HDR=-Iinclude

LIBHDR=-Ilibft -Imlx

SRC_DIR=src/

SRCS:=$(wildcard $(SRC_DIR)*.c)

OBJ_DIR=obj/

OBJS=$(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))

all: $(LIBFT) app

$(LIBFT):
	make -C libft
	@echo "done libft"

$(OBJ_DIR):
	mkdir $@
 
$(OBJS): $(OBJ_DIR)%.o: $(SRC_DIR)%.c $(OBJ_DIR)
	$(CC) $(CFLAGS) $(HDR) $(LIBHDR) -c $< -o $@ 

app: $(OBJS)
	@echo "making app"
	$(CC) $(CFLAGS) $(OBJS) $(HDR) $(LIBHDR) $(LIB) $(COMPATIBILITY) -o FdF

clean:
	rm -rf obj
	make -C libft $@

fclean: clean
	rm ./FdF
	make -C libft $@

re: fclean all

.PHONY: all clean fclean re so