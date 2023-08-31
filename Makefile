CC=gcc
CFLAGS=-Wall -Wextra -Werror -O3 -Imlx -Lmlx -lmlx -framework OpenGL -framework AppKit

NAME = fractol
DEPS = fractol.h
LIBFT = libft/libft.a
MLX = mlx/libmlx.a
SRCS = draw_utils.c draws.c handlers.c main.c

all: ${NAME}

${NAME}: ${SRCS} ${DEPS} ${LIBFT} ${MLX}
	@$(CC) ${CFLAGS} ${LIBFT} ${SRCS} -o ${NAME}
	@printf '\033[1;32mFractol compile success!\n\033[0m'

${LIBFT}:
	@make -C libft

${MLX}:
	@make -C mlx

clean:
	@make clean -C libft
	@make clean -C mlx

fclean: clean
	@rm -rf ${NAME}
	@printf '\033[1;35mDelete fractol\n\033[0m'

re: fclean all

.PHONY:	all clean fclean re
