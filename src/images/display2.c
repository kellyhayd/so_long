/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:58:05 by krocha-h          #+#    #+#             */
/*   Updated: 2024/02/19 10:23:33 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_hero_red(t_game *game, int32_t i, int32_t j)
{
	mlx_image_to_window(game->mlx, game->sprites.hero_red[0],
		j * BLOC, i * BLOC);
	game->sprites.hero_red[0]->instances[0].enabled = 0;
	mlx_image_to_window(game->mlx, game->sprites.hero_red[1],
		j * BLOC, i * BLOC);
	game->sprites.hero_red[1]->instances[0].enabled = 0;
}

/*
 * @brief Places the hero at its correspondent position in the map.
 *
 * @param game pointer to the t_game structure containing game data
 * @param i the width of the position in the map
 * @param j the height of the position in the map
 *
 * @details Places all the frames and keep only the first one enabled.
 */
static void	display_hero(t_game *game, int32_t i, int32_t j)
{
	int32_t	idx;

	idx = 0;
	display_hero_red(game, i, j);
	while (idx < 16)
	{
		mlx_image_to_window(game->mlx, game->sprites.hero[idx],
			j * BLOC, i * BLOC);
		game->sprites.hero[idx]->instances[0].enabled = 0;
		idx++;
	}
	game->sprites.hero[0]->instances[0].enabled = 1;
	game->hero.current_frame = 0;
	game->hero.i = i;
	game->hero.j = j;
}

void	find_hero(t_game *game)
{
	int32_t	i;
	int32_t	j;

	i = -1;
	while (++i < game->map->height)
	{
		j = -1;
		while (++j < game->map->width)
		{
			if (game->map->matrix[i][j] == 'P')
				display_hero(game, i, j);
		}
	}
}

void	display_lifes(t_game *game)
{
	int32_t	i;
	int32_t	x;

	i = 0;
	x = game->mlx->width - 200;
	while (i < 3)
	{
		mlx_image_to_window(game->mlx, game->sprites.no_heart[i], x, 15);
		i++;
		x += 50;
	}
	i = 0;
	x = game->mlx->width - 200;
	while (i < 3)
	{
		mlx_image_to_window(game->mlx, game->sprites.heart[i], x, 15);
		i++;
		x += 50;
	}
}

void	display_enemy(t_game *game, int32_t i, int32_t j)
{
	static int32_t	id;
	int32_t			idx;

	idx = 0;
	while (idx < 4)
	{
		mlx_image_to_window(game->mlx, game->sprites.enemy[idx],
			j * BLOC, i * BLOC);
		game->sprites.enemy[idx]->instances[id].enabled = 0;
		idx++;
	}
	game->sprites.enemy[0]->instances[id].enabled = 1;
	game->enemy[id].current_frame = 0;
	game->enemy[id].i = i;
	game->enemy[id].j = j;
	id++;
}
