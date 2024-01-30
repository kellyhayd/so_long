/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:32:55 by krocha-h          #+#    #+#             */
/*   Updated: 2024/01/30 15:34:10 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

void	define_imgs(t_game *game, mlx_t *mlx)
{
	mlx_texture_t*	texture;
	mlx_image_t*	img;

	texture = mlx_load_png("images/cat_walking_01.png");
	img = mlx_texture_to_image(mlx, texture);
	game->hero = img;

	texture = mlx_load_png("images/tile3.png");
	img = mlx_texture_to_image(mlx, texture);
	game->tile = img;

	// texture = mlx_load_png("images/enemy.png");
	// img = mlx_texture_to_image(mlx, texture);
	// game->enemy = img;

	texture = mlx_load_png("images/kitty_01.png");
	img = mlx_texture_to_image(mlx, texture);
	mlx_resize_image(img, 64, 64);
	game->star = img;

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
// 	mlx_image_to_window(mlx, game->bg, 64, -64);
// 	if (multiplier > 0)
// 	{
// 		i = 1;
// 		while (multiplier >= 0)
// 		{
// 			mlx_image_to_window(mlx, game->bg, (game->bg->width * i) + 64, -64);
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
				mlx_image_to_window(mlx, game->tile, j * 64, i * 64);
			else if (game->map->matrix[i][j] == 'P')
			{
				game->hero_spot.i = i;
				game->hero_spot.j = j;
				game->hero_spot.id = mlx_image_to_window(mlx, game->hero, j * 64, i * 64);
			}
			else if (game->map->matrix[i][j] == 'C')
			{
				game->star_spot[id].id = mlx_image_to_window(mlx, game->star, j * 64, i * 64);
				game->star_spot[id].i = i;
				game->star_spot[id].j = j;
				game->star_count++;
				id++;
			}
			j++;
		}
		i++;
	}
}
