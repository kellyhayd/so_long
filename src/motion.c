
#include "so_long.h"
#include "libft.h"
#include <fcntl.h>
#include <stdio.h>

void	collect_star(t_game *game, int32_t i, int32_t j)
{
	char	c;
	int32_t	id;

	c = game->map->matrix[i][j];
	if (c == 'C')
	{
		id = 0;
		while (game->star_spot[id].id < game->star_count)
		{
			if (game->star_spot[id].i == i && game->star_spot[id].j == j)
			{
				game->star->instances[game->star_spot[id].id].enabled = 0;
				break;
			}
			id++;
		}
	}
}

void	cat_walk(t_game *game, int32_t i, int32_t j)
{
	if (game->map->matrix[i][j] != '1' && game->map->matrix[i][j] != 'X')
	{
		game->hero->instances[game->hero_spot.id].x = j * 64;
		game->hero->instances[game->hero_spot.id].y = i * 64;
		game->hero_spot.i = i;
		game->hero_spot.j = j;
	}
}

void	key_motion(mlx_key_data_t keydata, void* param)
{
	t_game	*game;
	int32_t	i;
	int32_t	j;

	game = (t_game *)param;
	i = game->hero_spot.i;
	j = game->hero_spot.j;
	if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		&& keydata.action == MLX_PRESS)
		j++;
	else if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		&& keydata.action == MLX_PRESS)
		i--;
	else if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		&& keydata.action == MLX_PRESS)
		j--;
	else if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		&& keydata.action == MLX_PRESS)
		i++;
	if (game->map->matrix[i][j] == 'C')
		collect_star(game, i, j);
	cat_walk(game, i, j);
}

