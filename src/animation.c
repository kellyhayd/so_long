/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:29:05 by krocha-h          #+#    #+#             */
/*   Updated: 2024/02/06 14:30:30 by krocha-h         ###   ########.fr       */
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
	int32_t	id;

	id = game->hero_spot.id;
	i = 0;
	while (i < 3)
	{
		if (game->hero_walk[i]->instances[id].enabled == 1)
		{
			game->hero_walk[i]->instances[id].enabled = 0;
			game->hero_walk[(i + 1) % 3]->instances[id].enabled = 1;
			break ;
		}
		i++;
	}
}
