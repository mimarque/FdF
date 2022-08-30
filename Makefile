vpath %.c /src

CC=gcc

CFLAGS=-Wall -Wextra -Werror -g

MLX=mlx/libmlx_Linux.a

LIBFT=libft/libft.a

HDR=-Iinclude

I_LIBFT=-Ilibft -Llibft -lft

I_LIBMLX=-Imlx -Lmlx -lmlx

LIB=$(I_LIBFT) $(I_LIBMLX) -lm

NAME=FdF

COMPATIBILITY=-lX11 -lXext -lm

FRAMEWORK=-framework OpenGL -framework AppKit

SRC_DIR:=src

OBJ_DIR:=obj

SRCS:=$(wildcard $(SRC_DIR)/*.c)

OBJS:=$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	@echo "making app"
	$(CC) $(CFLAGS) $(OBJS) $(HDR) $(LIB) $(COMPATIBILITY) -o $@ 

$(LIBFT):
	make -C libft
	@echo "done libft"

$(OBJ_DIR):
	mkdir $@
 
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR) $(LIBFT)
	@echo "making objects"
	$(CC) $(CFLAGS) $(HDR) $(LIB) $(COMPATIBILITY) -c $< -o $@ 

clean:
	rm -rf obj
	make -C libft $@

fclean: clean
	make -C libft $@
	rm ./FdF

re: fclean all

.PHONY: all clean fclean re so