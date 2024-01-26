NAME		= so_long
INCLUDES	= -I./include -I./lib/libft -I./lib/MLX42/include/MLX42
CFLAGS		= -Wextra -Wall -Werror -Wunreachable-code \
				-Ofast $(INCLUDES)
LDLIBS		= -ldl -lglfw -pthread -lm

SRCS		=	src/map_format.c \
				src/map_validate.c \
				src/so_long.c
OBJS		= ${SRCS:.c=.o}
LIBFT		= lib/libft/libft.a
LIBMLX42	= lib/MLX42/build/libmlx42.a

$(LIBFT) :
	$(MAKE) -C ./lib/libft

$(LIBMLX42) :
	cmake lib/MLX42 -B lib/MLX42/build && \
		cmake --build lib/MLX42/build -j4

$(NAME) : $(OBJS) $(LIBFT) $(LIBMLX42)

all : $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
