NAME = libftprintf.a

CC = cc

FLAGS = -Wall -Werror -Wextra

HEADER = ft_printf.h

HEADER_BONUS = ./bonus/ft_printf_bonus.h

SRC = ./src/ft_printf.c \
	./src/ft_printf_utils.c \
	./src/print_hex.c \
	./src/print_char.c \
	./src/print_num.c

BONUS = ./bonus/ft_printf_bonus.c \
	./bonus/utils_str_bonus.c \
	./bonus/utils_num_bonus.c \
	./bonus/print_char_bonus.c \
	./bonus/print_hex_bonus.c \
	./bonus/print_num_bonus.c

OBJ = $(SRC:%.c=%.o)

OBJ_BONUS = $(BONUS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@
	ar -rcs $(NAME) $@

bonus: $(OBJ_BONUS)

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all
