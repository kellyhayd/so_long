###################################### COLORS
.SILENT:

CYAN	= \033[0;36m
PURPLE	= \033[0;35m
GREEN	= \033[0;32m
RESET	= \033[0m

###################################### PROJECT FILES

NAME		= so_long
CFLAGS		= -Wextra -Wall -Werror -Wunreachable-code -Ofast -g3
HEADERS		= -I ./include -I./lib/libft -I./lib/MLX42/include/MLX42

LIBMLX		= ./lib/MLX42/
LIBFT		= ./lib/libft
LIBS		= $(LIBMLX)/build/libmlx42.a ${LIBFT}/libft.a -ldl -lglfw -pthread -lm

SRCS_PATH	= ./src/
SRCS		= $(addprefix $(SRCS_PATH),\
			so_long.c \
			map_format.c \
			map_validate.c \
			map_render.c \
			map_path_validate.c \
			motion.c \
			animation.c)

OBJS		= ${SRCS:%.c=%.o}

###################################### BONUS FILES

NAME_BONUS		= so_long_bonus
SRCS_PATH_BONUS	= ./bonus/
SRCS_BONUS	= $(addprefix $(SRCS_PATH_BONUS),\
			/animation/animation_bonus.c \
			/animation/utils_bonus.c \
			/images/display1_bonus.c \
			/images/display2_bonus.c \
			/images/load1_bonus.c \
			/images/load2_bonus.c \
			/images/load_hero_bonus.c \
			/init/init_bonus.c \
			/init/main_bonus.c \
			/map/flood_fill_bonus.c \
			/map/format_bonus.c \
			/map/validation1_bonus.c \
			/map/validation2_bonus.c \
			/movement/motion1_bonus.c \
			/movement/motion2_bonus.c)

OBJS_BONUS		= ${SRCS_BONUS:%.c=%.o}

ifdef WITH_BONUS
	NAME		= $(NAME_BONUS)
	SRCS		= $(SRCS_BONUS)
	OBJS		= $(OBJS_BONUS)
endif

###################################### COMPILATION

all: libmlx libft $(NAME)

libft:
	$(MAKE) -C ./lib/libft
	@echo "$(GREEN)This beautiful LIBFT is also ready!$(RESET)"

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4
	@echo "$(GREEN)The MLX is ready to be use!$(RESET)"

%.o: %.c
	$(CC) $(HEADERS) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	@echo "$(PURPLE)Compiling...$(RESET)"
	$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)
	@echo "$(GREEN)Done! Let's play! $(RESET)"

bonus:
	@echo "$(CYAN)Let's do it!\n $(RESET)"
	$(MAKE) WITH_BONUS=TRUE

###################################### CLEAN

clean:
	rm -rf $(OBJS) $(OBJS_BONUS)
	@echo "$(CYAN)Yeap! The mess was clean up!$(RESET)"

fclean: clean
	rm -rf $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all, clean, fclean, re, libmlx, libft, bonus

###################################### NORM

norm:
	@echo "$(PURPLE)Norminette:$(RESET)"
	@norminette $(SRCS) ./include/so_long.h
	@echo "$(CYAN)Norminette done$(RESET)"
