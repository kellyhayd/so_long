/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:58:05 by krocha-h          #+#    #+#             */
/*   Updated: 2024/02/06 17:43:10 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	display_banner(t_game *game)
{
	(void)game;
	// mlx_image_to_window(game->mlx, game->sprites.banner, 50, 50);
}

void	display_enemy(t_game *game, int32_t i, int32_t j)
{
	int32_t	id;
	int32_t	idx;

	idx = 0;
	while (idx < 4)
	{
		id = mlx_image_to_window(game->mlx, game->sprites.enemy[idx],
				j * BLOC, i * BLOC);
		game->enemy.instances[idx] = &game->sprites.enemy[idx]->instances[id];
		game->enemy.instances[idx]->enabled = 0;
		idx++;
	}
	game->enemy.current_frame = 0;
	game->enemy.i = i;
	game->enemy.j = j;
}
