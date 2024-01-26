
#include "so_long.h"
#include "libft.h"
#include <fcntl.h>
#include <stdio.h>

void key_motion(mlx_key_data_t keydata, void* param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		game->hero->instances[0].x += 64;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		game->hero->instances[0].y -= 64;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		game->hero->instances[0].x -= 64;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		game->hero->instances[0].y += 64;
}

