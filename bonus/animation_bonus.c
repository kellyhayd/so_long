/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:35:15 by krocha-h          #+#    #+#             */
/*   Updated: 2024/02/06 17:41:20 by krocha-h         ###   ########.fr       */
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

void	hero_move(t_game *game)
{
	int32_t	i;
	int32_t	id;

	id = game->hero_r.current_frame;
	i = 0;
	while (i < 8)
	{
		if (game->hero_r.instances[id]->enabled == 1)
		{
			game->hero_r.instances[id]->enabled = 0;
			game->hero_r.instances[(id + 1) % 8]->enabled = 1;
			break ;
		}
		i++;
	}
}

void	animation(void *param)
{
	int32_t	i;
	int32_t	j;
	t_game	*game;
	static int32_t	counter;

	game = param;
	open_box(game);
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
	if (counter == 24)
	{
		hero_move(game);
		counter = 0;
	}
	counter++;
}
