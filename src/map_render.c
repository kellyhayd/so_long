/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:32:55 by krocha-h          #+#    #+#             */
/*   Updated: 2024/02/01 14:15:01 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

void	define_imgs(t_game *game, mlx_t *mlx)
{
	mlx_texture_t*	texture;
	mlx_image_t*	img;

	texture = mlx_load_png("images/cats/cat_01.png");
	img = mlx_texture_to_image(mlx, texture);
	mlx_resize_image(img, BLOC, BLOC);
	game->hero = img;
	texture = mlx_load_png("images/tile.png");
	img = mlx_texture_to_image(mlx, texture);
	mlx_resize_image(img, BLOC, BLOC);
	game->tile = img;
	texture = mlx_load_png("images/tectec/clicker_01.png");
	img = mlx_texture_to_image(mlx, texture);
	mlx_resize_image(img, BLOC, BLOC);
	game->enemy = img;
	texture = mlx_load_png("images/cat_food.png");
	img = mlx_texture_to_image(mlx, texture);
	mlx_resize_image(img, BLOC, BLOC);
	game->star = img;
	texture = mlx_load_png("images/box_pixel.png");
	img = mlx_texture_to_image(mlx, texture);
	mlx_resize_image(img, BLOC, BLOC);
	game->exit = img;
	// texture = mlx_load_png("images/background/png/bg.png");
	// img = mlx_texture_to_image(mlx, texture);
	// game->bg = img;
}

// void	background_resize(mlx_t *mlx, t_game *game)
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

void	components_position(mlx_t *mlx, t_game *game)
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
				mlx_image_to_window(mlx, game->tile, j * BLOC, i * BLOC);
			else if (game->map->matrix[i][j] == 'P')
			{
				game->hero_spot.i = i;
				game->hero_spot.j = j;
				game->hero_spot.id = mlx_image_to_window(mlx, game->hero, j * BLOC, i * BLOC);
				printf("i = %d | j = %d\n", i, j);
			}
			else if (game->map->matrix[i][j] == 'C')
			{
				game->star_spot[id].i = i;
				game->star_spot[id].j = j;
				game->star_spot[id].id = mlx_image_to_window(mlx, game->star, j * BLOC, i * BLOC);
				game->star_count++;
				id++;
			}
			else if (game->map->matrix[i][j] == 'E')
				mlx_image_to_window(mlx, game->exit, j * BLOC, i * BLOC);
			else if (game->map->matrix[i][j] == 'X')
				mlx_image_to_window(mlx, game->enemy, j * BLOC, i * BLOC);
			j++;
		}
		i++;
	}
}
