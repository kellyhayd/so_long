/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:35:15 by krocha-h          #+#    #+#             */
/*   Updated: 2024/02/06 14:35:21 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_box(t_game *game)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	if (game->star_collected == game->star_total)
	{
		texture = mlx_load_png("images/box/box_open.png");
		img = mlx_texture_to_image(game->mlx, texture);
		game->exit = img;
	}
	else if (game->star_collected < game->star_total)
	{
		texture = mlx_load_png("images/box/box_closed.png");
		img = mlx_texture_to_image(game->mlx, texture);
		game->exit = img;
	}
}

void	hero_move(t_game *game)
{
	int32_t	i;

	i = 0;
	while (i < 8)
	{
		if (game->hero_walk[i]->instances[game->hero_spot.id].enabled == 1)
		{
			game->hero_walk[i]->instances[game->hero_spot.id].enabled = 0;
			game->hero_walk[(i + 1) % 8]->instances[game->hero_spot.id].enabled = 1;
			break ;
		}
		i++;
	}
}
