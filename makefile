###################################### COLORS
.SILENT:

GREEN = \033[32m
YELLOW = \033[33m
RESET = \033[0m

###################################### PROJECT FILES

NAME	:= so_long
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast -g3
HEADERS	:= -I ./include -I./lib/libft -I./lib/MLX42/include/MLX42

LIBMLX	:= ./lib/MLX42/
LIBFT	:= ./lib/libft
LIBS	= $(LIBMLX)/build/libmlx42.a ${LIBFT}/libft.a -ldl -lglfw -pthread -lm

SRCS_PATH	:= ./src/
SRCS	= $(addprefix $(SRCS_PATH),\
			so_long.c \
			map_format.c \
			map_validate.c \
			map_render.c \
			map_path_validate.c \
			motion.c \
			animation.c)

OBJS	= ${SRCS:%.c=%.o}

###################################### BONUS FILES

NAME_BONUS	:= so_long_bonus
SRCS_PATH_BONUS	:= ./bonus/
# SRCS_BONUS	:= $(addprefix $(SRCS_PATH_BONUS),\
# 			collectibles_bonus.c \
# 			exit_bonus.c \
# 			flood_bonus.c \
# 			images_bonus.c \
# 			main_bonus.c \
# 			map_bonus.c \
# 			movement_bonus.c \
# 			movement2_bonus.c \
# 			textures_bonus.c \
# 			utils_bonus.c \
# 			validation_bonus.c)

OBJS_BONUS	= ${SRCS_BONUS:%.c=%.o}

ifdef WITH_BONUS
	NAME	= $(NAME_BONUS)
	SRCS	= $(SRCS_BONUS)
	OBJS	= $(OBJS_BONUS)
endif

###################################### COMPILATION

all: libmlx libft $(NAME)

libft:
	$(MAKE) -C ${LIBFT} all clean

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	$(CC) $(HEADERS) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	printf "$(YELLOW)Compiling...$(RESET)\n"
	$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)
	printf "$(GREEN)Done!\n $(RESET)"

bonus:
	$(MAKE) WITH_BONUS=TRUE

###################################### CLEAN

clean:
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -rf $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all, clean, fclean, re, libmlx, libft, bonus