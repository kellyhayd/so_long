/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display1_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:32:55 by krocha-h          #+#    #+#             */
/*   Updated: 2024/02/15 16:51:26 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	display_star(t_game *game, int32_t i, int32_t j)
{
	static int32_t	id;
	int32_t			idx;

	idx = 0;
	while (idx < 4)
	{
		mlx_image_to_window(game->mlx, game->sprites.star[idx],
			j * BLOC, i * BLOC);
		game->sprites.star[idx]->instances[id].enabled = 0;
		idx++;
	}
	game->sprites.star[0]->instances[id].enabled = 1;
	game->star[id].current_frame = 0;
	game->star[id].i = i;
	game->star[id].j = j;
	id++;
}

void	display_hero_red(t_game *game, int32_t i, int32_t j)
{
	mlx_image_to_window(game->mlx, game->sprites.hero_red[0],
		j * BLOC, i * BLOC);
	game->sprites.hero_red[0]->instances[0].enabled = 0;
	mlx_image_to_window(game->mlx, game->sprites.hero_red[1],
		j * BLOC, i * BLOC);
	game->sprites.hero_red[1]->instances[0].enabled = 0;
}

void	display_hero(t_game *game, int32_t i, int32_t j)
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

void	display_background(t_game *game)
{
	int32_t	multiplier;
	float	ratio;
	int32_t	i;

	ratio = ((float)game->mlx->height / (float)game->sprites.bg->height);
	mlx_resize_image(game->sprites.bg, game->sprites.bg->width * ratio,
		game->sprites.bg->height * ratio);
	multiplier = game->mlx->width / game->sprites.bg->width;
	mlx_image_to_window(game->mlx, game->sprites.bg,
		BLOC, -BLOC);
	if (multiplier > 0)
	{
		i = 1;
		while (multiplier >= 0)
		{
			mlx_image_to_window(game->mlx, game->sprites.bg,
				(game->sprites.bg->width * i) + BLOC, -BLOC);
			multiplier--;
			i++;
		}
	}
}

void	display_components(t_game *game)
{
	int32_t	i;
	int32_t	j;

	display_background(game);
	i = -1;
	while (++i < game->map->height)
	{
		j = -1;
		while (++j < game->map->width)
		{
			if (game->map->matrix[i][j] == '1')
				mlx_image_to_window(game->mlx, game->sprites.tile,
					j * BLOC, i * BLOC);
			else if (game->map->matrix[i][j] == 'P')
				display_hero(game, i, j);
			else if (game->map->matrix[i][j] == 'C')
				display_star(game, i, j);
			else if (game->map->matrix[i][j] == 'X')
				display_enemy(game, i, j);
			else if (game->map->matrix[i][j] == 'E')
				display_exit(game, i, j);
		}
	}
	display_banner(game);
	display_lifes(game);
}
