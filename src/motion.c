
#include "so_long.h"
#include "libft.h"
#include <fcntl.h>
#include <stdio.h>

void key_motion(mlx_key_data_t keydata, void* param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
	{
		if (game->map->matrix[game->hero_spot.i][game->hero_spot.j + 1] != '1' &&
			game->map->matrix[game->hero_spot.i][game->hero_spot.j + 1] != 'X')
			game->hero_spot.j += 1;
	}
	else if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
	{
		if (game->map->matrix[game->hero_spot.i - 1][game->hero_spot.j] != '1' &&
			game->map->matrix[game->hero_spot.i - 1][game->hero_spot.j] != 'X')
			game->hero_spot.i -= 1;
	}
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
	{
		if (game->map->matrix[game->hero_spot.i][game->hero_spot.j - 1] != '1' &&
			game->map->matrix[game->hero_spot.i][game->hero_spot.j - 1] != 'X')
			game->hero_spot.j -= 1;
	}
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
	{
		if (game->map->matrix[game->hero_spot.i + 1][game->hero_spot.j] != '1' &&
			game->map->matrix[game->hero_spot.i + 1][game->hero_spot.j] != 'X')
			game->hero_spot.i += 1;
	}
	game->hero->instances[game->hero_spot.id].x = game->hero_spot.j * 64;
	game->hero->instances[game->hero_spot.id].y = game->hero_spot.i * 64;
}

