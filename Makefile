NAME = fractol

LIBFT = libft
LFLAGS = -L libft -lft

MLX = mlx_linux
MFLAGS = -L mlx_linux -l mlx_Linux -lXext -lX11

SRC = src/main.c src/color.c src/hooks.c src/fractal.c src/ft_atof.c src/parsing.c

SRC_BONUS = src/main_bonus.c src/color_bonus.c src/hooks_bonus.c src/fractal_bonus.c src/ft_atof_bonus.c src/parsing_bonus.c

ifdef BONUS
	SRC = $(SRC_BONUS)
	NAME = fractol_bonus
endif

OBJ = $(SRC:.c=.o)

OBJBONUS = $(SRC_BONUS:.c=.o)

FLAGS = -Ofast -Wall -Werror -Wextra

CC = clang
all : $(NAME)

$(NAME) : $(OBJ)
	make -C $(MLX)
	make -C $(LIBFT)
	$(CC) $(FLAGS) $(OBJ) $(MFLAGS) $(LFLAGS) -o $(NAME)

bonus :
	@make BONUS=1

%.o : %.c
	$(CC) $(FLAGS) -I/src/ -c $< -o $@

clean :
	make -C $(MLX) clean
	make -C $(LIBFT) clean
	rm -rf $(OBJ) $(OBJBONUS)

fclean : clean
	make -C $(LIBFT) fclean
	rm -rf $(NAME) fractol_bonus

re : fclean all

reb : fclean bonus
