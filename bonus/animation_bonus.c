
#include "so_long.h"

void	open_box(t_game *game)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	if (game->star_collected == game->star_total)
	{
		texture = mlx_load_png("images/box/box_open.png");
		img = mlx_texture_to_image(game->mlx, texture);
		game->exit = img;
	}
	else if (game->star_collected < game->star_total)
	{
		texture = mlx_load_png("images/box/box_closed.png");
		img = mlx_texture_to_image(game->mlx, texture);
		game->exit = img;
	}
}

void	hero_move(t_game *game)
{
	int32_t	i;

	i = 0;
	while (i < 3)
	{
		if (game->hero_walk[i]->instances[game->hero_spot.id].enabled == 1)
		{
			game->hero_walk[i]->instances[game->hero_spot.id].enabled = 0;
			game->hero_walk[(i+1) % 3]->instances[game->hero_spot.id].enabled = 1;
			break;
		}
		i++;
	}
}