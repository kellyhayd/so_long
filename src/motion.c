
#include "so_long.h"
#include "libft.h"
#include <fcntl.h>
#include <stdio.h>

void	component_front(t_game *game)
{
	char	c;

	c = game->map->matrix[game->hero_spot.i][game->hero_spot.j + 1];
	if (c != '1' && c != 'C' && c != 'X')
		game->hero_spot.j += 1;
	// if (c == 'X')
	// 	//perde vida
	if (c == 'C')
	{
		game->star->enabled = 0;
		//ganha um estrela
		game->hero_spot.j += 1;
	}
}

void	component_back(t_game *game)
{
	char	c;

	c = game->map->matrix[game->hero_spot.i][game->hero_spot.j - 1];
	if (c != '1' && c != 'C' && c != 'X')
		game->hero_spot.j -= 1;
	// if (c == 'X')
	// 	//perde vida
	if (c == 'C')
	{
		game->star->enabled = 0;
		//ganha um estrela
		game->hero_spot.j -= 1;
	}
}

void	component_up(t_game *game)
{
	char	c;

	c = game->map->matrix[game->hero_spot.i - 1][game->hero_spot.j];
	if (c != '1' && c != 'C' && c != 'X')
		game->hero_spot.i -= 1;
	// if (c == 'X')
	// 	//perde vida
	if (c == 'C')
	{
		game->star->enabled = 0;
		//ganha um estrela
		game->hero_spot.i -= 1;
	}
}

void	component_down(t_game *game)
{
	char	c;

	c = game->map->matrix[game->hero_spot.i + 1][game->hero_spot.j];
	if (c != '1' && c != 'C' && c != 'X')
		game->hero_spot.i += 1;
	// if (c == 'X')
	// 	//perde vida
	if (c == 'C')
	{
		game->star->enabled = 0;
		//ganha um estrela
		game->hero_spot.i += 1;
	}
}

void	key_motion(mlx_key_data_t keydata, void* param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		component_front(game);
	else if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		component_up(game);
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		component_back(game);
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		component_down(game);
	game->hero->instances[game->hero_spot.id].x = game->hero_spot.j * 64;
	game->hero->instances[game->hero_spot.id].y = game->hero_spot.i * 64;
}

