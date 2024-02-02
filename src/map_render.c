/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:32:55 by krocha-h          #+#    #+#             */
/*   Updated: 2024/02/02 14:00:45 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

void	store_heros(t_game *game)
{
	game->hero_walk[0] = store_imgs("images/cats/cat_01.png", game);
	game->hero_walk[1] = store_imgs("images/cats/cat_02.png", game);
	game->hero_walk[2] = store_imgs("images/cats/cat_03.png", game);
	game->hero_walk[3] = store_imgs("images/cats/cat_04.png", game);
	game->hero_walk[4] = store_imgs("images/cats/cat_05.png", game);
	game->hero_walk[5] = store_imgs("images/cats/cat_06.png", game);
	game->hero_walk[6] = store_imgs("images/cats/cat_07.png", game);
	game->hero_walk[7] = store_imgs("images/cats/cat_08.png", game);
}

mlx_image_t	*store_imgs(const char *path, t_game *game)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png(path);
	img = mlx_texture_to_image(game->mlx, texture);
	mlx_resize_image(img, BLOC, BLOC);
	return (img);

}

void	define_imgs(t_game *game)
{
	store_heros(game);
	game->tile = store_imgs("images/tile.png", game);
	game->enemy = store_imgs("images/tectec/clicker_01.png", game);
	game->star = store_imgs("images/cat_food.png", game);
	game->exit = store_imgs("images/box_pixel.png", game);
	// game->bg = store_imgs("images/background/png/bg.png", game);
}

// void	background_resize(t_game *game)
// {
// 	float	resizer;
// 	int32_t	multiplier;
// 	int32_t	i;

// 	resizer = mlx->height / (float)game->bg->height;
// 	mlx_resize_image(game->bg, game->bg->width * resizer, game->bg->height * resizer);
// 	multiplier = mlx->width / game->bg->width;
// 	mlx_image_to_window(mlx, game->bg, BLOC, -BLOC);
// 	if (multiplier > 0)
// 	{
// 		i = 1;
// 		while (multiplier >= 0)
// 		{
// 			mlx_image_to_window(mlx, game->bg, (game->bg->width * i) + BLOC, -BLOC);
// 			multiplier--;
// 			i++;
// 		}
// 	}
// }

void	components_position(t_game *game)
{
	int32_t	i;
	int32_t	j;
	int32_t	id;

	i = 0;
	id = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			if (game->map->matrix[i][j] == '1')
				mlx_image_to_window(game->mlx, game->tile, j * BLOC, i * BLOC);
			else if (game->map->matrix[i][j] == 'P')
			{
				game->hero_spot.i = i;
				game->hero_spot.j = j;
				game->hero_spot.id = mlx_image_to_window(game->mlx, game->hero_walk[0], j * BLOC, i * BLOC);
				mlx_image_to_window(game->mlx, game->hero_walk[1], j * BLOC, i * BLOC);
				game->hero_walk[1]->instances->enabled = 0;
				mlx_image_to_window(game->mlx, game->hero_walk[2], j * BLOC, i * BLOC);
				game->hero_walk[2]->instances->enabled = 0;
			}
			else if (game->map->matrix[i][j] == 'C')
			{
				game->star_spot[id].i = i;
				game->star_spot[id].j = j;
				game->star_spot[id].id = mlx_image_to_window(game->mlx, game->star, j * BLOC, i * BLOC);
				game->star_total++;
				id++;
			}
			else if (game->map->matrix[i][j] == 'E')
				mlx_image_to_window(game->mlx, game->exit, j * BLOC, i * BLOC);
			else if (game->map->matrix[i][j] == 'X')
				mlx_image_to_window(game->mlx, game->enemy, j * BLOC, i * BLOC);
			j++;
		}
		i++;
	}
}
