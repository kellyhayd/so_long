
#include "so_long.h"
#include "libft.h"
#include <fcntl.h>
#include <stdio.h>

void key_motion(mlx_key_data_t keydata, void* param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		game->hero_position.j += 1;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		game->hero_position.i -= 1;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		game->hero_position.j -= 1;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		game->hero_position.i += 1;
	game->hero->instances[game->hero_position.id].x = game->hero_position.j * 64;
	game->hero->instances[game->hero_position.id].y = game->hero_position.i * 64;
}

