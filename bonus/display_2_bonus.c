/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:58:05 by krocha-h          #+#    #+#             */
/*   Updated: 2024/02/08 15:25:15 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	display_lifes(t_game *game)
{
	int32_t	i;
	int32_t	x;

	i = 0;
	x = game->mlx->width - 100;
	while (i < 3)
	{
		mlx_image_to_window(game->mlx, game->sprites.heart[i], x, 15);
		i++;
		x -= 50;
	}
	
}

void	display_banner(t_game *game)
{
	mlx_image_to_window(game->mlx, game->sprites.banner, 20, 15);
	game->print_steps = mlx_put_string(game->mlx, "No move", 60, 30);
}

void	display_enemy(t_game *game, int32_t i, int32_t j)
{
	static int32_t	id;
	int32_t	idx;

	idx = 0;
	while (idx < 4)
	{
		id = mlx_image_to_window(game->mlx, game->sprites.enemy[idx],
				j * BLOC, i * BLOC);
		game->enemy[id].instances[idx] = &game->sprites.enemy[idx]->instances[id];
		game->enemy[id].instances[idx]->enabled = 0;
		idx++;
	}
	game->enemy[id].current_frame = 0;
	game->enemy[id].instances[0]->enabled = 1;
	game->enemy[id].i = i;
	game->enemy[id].j = j;
	id++;
}
