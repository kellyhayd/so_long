
#include "so_long.h"
#include "libft.h"
#include <fcntl.h>
#include <stdio.h>

// void	component_down(t_game *game)
// {
// 	char	c;

// 	c = game->map->matrix[game->hero_spot.i + 1][game->hero_spot.j];
// 	if (c != '1' && c != 'C' && c != 'X')
// 		game->hero_spot.i += 1;
// 	// if (c == 'X')
// 	// 	//perde vida
// 	if (c == 'C')
// 	{
// 		game->star->enabled = 0;
// 		//ganha um estrela
// 		game->hero_spot.i += 1;
// 	}
// }

void	key_motion(mlx_key_data_t keydata, void* param)
{
	t_game	*game;
	char	c;
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
	c = game->map->matrix[i][j];
	if (c != '1' && c != 'X')
	{
		game->hero->instances[game->hero_spot.id].x = j * 64;
		game->hero->instances[game->hero_spot.id].y = i * 64;
		game->hero_spot.i = i;
		game->hero_spot.j = j;
	}
}

