#include "so_long_bonus.h"

void	collect_star(t_game *game, int32_t i, int32_t j)
{
	int32_t	spot;
	int32_t	id;

	spot = 0;
	while (spot < game->star_total)
	{
		if (game->star[spot].i == i && game->star[spot].j == j)
		{
			id = 0;
			while (id < 4)
			{
				if (game->sprites.star[id]->instances[spot].enabled == 1)
				{
					game->sprites.star[id]->instances[spot].enabled = 0;
					game->star_collected++;
					break ;
				}
				id++;
			}
		}
		spot++;
	}
	open_box(game);
}

void	enemy_collision(t_game *game)
{
	static int32_t	i;
	int32_t			x;
	int32_t			y;

	x = (game->mlx->width - game->sprites.game_over->width) / 2;
	y = (game->mlx->height - game->sprites.game_over->height) / 2;
	mlx_delete_image(game->mlx, game->sprites.heart[i]);
	game->life_count--;
	if (game->life_count == 0)
	{
		mlx_image_to_window(game->mlx, game->sprites.end_bg, 0, 0);
		mlx_image_to_window(game->mlx, game->sprites.game_over, x, y);
	}
	i++;
}

void	steps_to_window(t_game *game)
{
	char	*steps;
	char	*print;

	mlx_delete_image(game->mlx, game->print_steps);
	steps = ft_itoa(game->move_count);
	print = ft_calloc(sizeof(char *), 1);
	if (!print)
	{
		ft_putstr_fd(MSG_MALLOC, 2);
		exit(EXIT_FAILURE);
	}
	if (game->move_count == 1)
		game->print_steps = mlx_put_string(game->mlx, "1 step", 60, 30);
	else
	{
		print = ft_strjoin(steps, " steps");
		game->print_steps = mlx_put_string(game->mlx, print, 60, 30);
	}
	free(steps);
	free(print);
}
