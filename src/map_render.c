
#include "so_long.h"
#include "libft.h"
#include <fcntl.h>
#include <stdio.h>

void	define_imgs(t_game *game, mlx_t *mlx)
{
	mlx_texture_t*	texture;
	mlx_image_t*	img;

	texture = mlx_load_png("images/tile.png");
	img = mlx_texture_to_image(mlx, texture);
	game->tile = img;
	texture = mlx_load_png("images/cats/cat_walking_01.png");
	img = mlx_texture_to_image(mlx, texture);
	game->hero = img;
	// texture = mlx_load_png("images/enemy.png");
	// img = mlx_texture_to_image(mlx, texture);
	// game->enemy = img;
	// texture = mlx_load_png("images/star.png");
	// img = mlx_texture_to_image(mlx, texture);
	// game->star = img;
}

void	components_position(mlx_t *mlx, t_game *game)
{
	int32_t	i;
	int32_t	j;

	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			if (game->map->matrix[i][j] == '1')
				mlx_image_to_window(mlx, game->tile, j * 64, i * 64);
			else if (game->map->matrix[i][j] == 'P')
			{
				game->hero_spot.i = i;
				game->hero_spot.j = j;
				game->hero_spot.id = mlx_image_to_window(mlx, game->hero, j * 64, i * 64);
			}
			j++;
		}
		i++;
	}
}
