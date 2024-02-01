/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:32:55 by krocha-h          #+#    #+#             */
/*   Updated: 2024/02/01 18:06:47 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"



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
	game->hero = store_imgs("images/cats/cat_01.png", game);
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
				game->hero_spot.id = mlx_image_to_window(game->mlx, game->hero, j * BLOC, i * BLOC);
				printf("i = %d | j = %d\n", i, j);
			}
			else if (game->map->matrix[i][j] == 'C')
			{
				game->star_spot[id].i = i;
				game->star_spot[id].j = j;
				game->star_spot[id].id = mlx_image_to_window(game->mlx, game->star, j * BLOC, i * BLOC);
				game->star_count++;
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
