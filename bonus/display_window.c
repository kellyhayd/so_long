/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:32:55 by krocha-h          #+#    #+#             */
/*   Updated: 2024/02/02 16:43:21 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	display_enemy(t_game *game, int32_t i, int32_t j)
{
	int32_t	id;
	int32_t	idx;

	idx = 0;
	while (idx < 4)
	{
		id = mlx_image_to_window(game->mlx, game->sprites.enemy[idx], j * BLOC, i * BLOC);
		game->enemy.instances[idx] = &game->sprites.enemy[idx]->instances[id];
		game->enemy.instances[idx]->enabled = 0;
		idx++;
	}
	game->enemy.current_frame = 0;
	game->enemy.i = i;
	game->enemy.j = j;
}

void	display_star(t_game *game, int32_t i, int32_t j)
{
	int32_t	id;
	int32_t	idx;

	idx = 0;
	while (idx < 4)
	{
		id = mlx_image_to_window(game->mlx, game->sprites.star[idx], j * BLOC, i * BLOC);
		game->star.instances[idx] = &game->sprites.star[idx]->instances[id];
		game->star.instances[idx]->enabled = 0;
		idx++;
	}
	game->star.current_frame = 0;
	game->star.i = i;
	game->star.j = j;
}

void	display_player(t_game *game, int32_t i, int32_t j)
{
	int32_t	id;
	int32_t	idx;

	idx = 0;
	while (idx < 8)
	{
		id = mlx_image_to_window(game->mlx, game->sprites.hero_r[idx], j * BLOC, i * BLOC);
		game->hero_r.instances[idx] = &game->sprites.hero_r[idx]->instances[id];
		game->hero_r.instances[idx]->enabled = 0;
		idx++;
	}
	game->hero_r.current_frame = 0;
	game->hero_r.i = i;
	game->hero_r.j = j;
}

void	display_background(t_game *game)
{
	int32_t	multiplier;
	int32_t	i;

	multiplier = game->mlx->width / game->sprites.bg->width;
	mlx_image_to_window(game->mlx, game->sprites.bg, BLOC, -BLOC);
	if (multiplier > 0)
	{
		i = 1;
		while (multiplier >= 0)
		{
			mlx_image_to_window(game->mlx, game->sprites.bg, (game->sprites.bg->width * i) + BLOC, -BLOC);
			multiplier--;
			i++;
		}
	}
}

void	display_components(t_game *game)
{
	int32_t	i;
	int32_t	j;
	int32_t	id;

	display_background(game);
	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			if (game->map->matrix[i][j] == '1')
				mlx_image_to_window(game->mlx, game->sprites.tile,
					j * BLOC, i * BLOC);
			else if (game->map->matrix[i][j] == 'P')
				display_player(game, i, j);
			else if (game->map->matrix[i][j] == 'C')
				display_star(game, i, j);
			else if (game->map->matrix[i][j] == 'X')
				display_enemy(game, i, j);
			j++;
		}
		i++;
	}
}
