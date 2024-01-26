NAME		= so_long
CFLAGS		= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LDLIBS		= -ldl -lglfw -pthread -lm

SRCS		=	src/map_format.c \
				src/map_validate.c \
				src/so_long.c
OBJS		= ${SRCS:.c=.o}
LIBFT		= libft/libft.a
LIBMLX42	= lib/MLX42/build/libmlx42.a

$(LIBFT) :
	$(MAKE) -C ./libft

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
