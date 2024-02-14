/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:35:15 by krocha-h          #+#    #+#             */
/*   Updated: 2024/02/08 17:45:28 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	open_box(t_game *game)
{
	mlx_texture_t	*texture;

	if (game->star_collected == game->star_total)
	{
		texture = mlx_load_png("images/box/box_open.png");
		game->sprites.exit = mlx_texture_to_image(game->mlx, texture);
	}
	else if (game->star_collected < game->star_total)
	{
		texture = mlx_load_png("images/box/box_closed.png");
		game->sprites.exit = mlx_texture_to_image(game->mlx, texture);
	}
}

// void	enemy_animation(t_game *game)
// {
// 	int32_t	spot;
// 	int32_t	id;

// 	spot = 0;
// 	while (spot < game->enemy_total)
// 	{
// 		id = 0;
// 		while (id < 4)
// 		{
// 			if (game->enemy[spot].instances[id]->enabled == 1)
// 			{
// 				game->enemy[spot].instances[id]->enabled = 0;
// 				game->enemy[spot].instances[(id + 1) % 4]->enabled = 1;
// 				game->enemy[spot].current_frame = (id + 1) % 4;
// 				break ;
// 			}
// 			id++;
// 		}
// 		spot++;
// 	}
// }

void	star_animation(t_game *game)
{
	int32_t	spot;
	int32_t	id;

	spot = 0;
	while (spot < game->star_total)
	{
		id = game->star[spot].current_frame;
		if (game->sprites.star[id]->instances[spot].enabled == 1)
		{
			game->sprites.star[id]->instances[spot].enabled = 0;
			id = (id + 1) % 4;
			game->sprites.star[id]->instances[spot].enabled = 1;
			game->star[spot].current_frame = id;
		}
		spot++;
	}
}

void	hero_animation(t_game *game)
{
	int32_t	id;

	id = game->hero_r.current_frame;
	if (game->sprites.hero_r[id]->instances[0].enabled == 1)
	{
		game->sprites.hero_r[id]->instances[0].enabled = 0;
		id = (id + 1) % 8;
		game->sprites.hero_r[id]->instances[0].enabled = 1;
		game->hero_r.current_frame = id;
	}
}

void	animation(void *param)
{
	int32_t	i;
	int32_t	j;
	t_game	*game;
	static int32_t	counter;

	game = param;
	// open_box(game);
	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			if (game->map->matrix[i][j] == 'E')
				mlx_image_to_window(game->mlx, game->sprites.exit,
						j * BLOC, i * BLOC);
			j++;
		}
		i++;
	}
	if (counter == 8)
	{
		hero_animation(game);
		// enemy_animation(game);
		star_animation(game);
		counter = 0;
	}
	counter++;
}
