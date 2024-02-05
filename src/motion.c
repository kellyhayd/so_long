/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:33:08 by krocha-h          #+#    #+#             */
/*   Updated: 2024/02/02 15:55:09 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	hero_animation(void *param)
{
	int32_t	i;
	int32_t	j;
	t_game	*game;

	game = param;
	open_box(game);
	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			if (game->map->matrix[i][j] == 'E')
				mlx_image_to_window(game->mlx, game->exit, j * BLOC, i * BLOC);
			j++;
		}
		i++;
	}
}

// void	hero_animation(void *param)
// {
// 	t_game	*game;
// 	static int	counter;

// 	game = param;
// 	if (counter == 12)
// 	{

// 		if (game->hero_walk[0]->instances[game->hero_spot.id].enabled == 1)
// 		{
// 			game->hero_walk[0]->instances[game->hero_spot.id].enabled = 0;
// 			game->hero_walk[1]->instances[game->hero_spot.id].enabled = 1;
// 			game->hero_walk[2]->instances[game->hero_spot.id].enabled = 0;
// 		}
// 		else if (game->hero_walk[1]->instances[game->hero_spot.id].enabled == 1)
// 		{
// 			game->hero_walk[0]->instances[game->hero_spot.id].enabled = 0;
// 			game->hero_walk[1]->instances[game->hero_spot.id].enabled = 0;
// 			game->hero_walk[2]->instances[game->hero_spot.id].enabled = 1;
// 		}
// 		else
// 		{
// 			game->hero_walk[0]->instances[game->hero_spot.id].enabled = 1;
// 			game->hero_walk[1]->instances[game->hero_spot.id].enabled = 0;
// 			game->hero_walk[2]->instances[game->hero_spot.id].enabled = 0;
// 		}
// 		counter = 0;
// 	}
// 	counter++;
// }

static void	collect_star(t_game *game, int32_t i, int32_t j)
{
	int32_t	id;

	id = 0;
	while (id < game->star_total)
	{
		if (game->star_spot[id].i == i && game->star_spot[id].j == j)
		{
			game->star->instances[game->star_spot[id].id].enabled = 0;
			game->star_collected++;
			break ;
		}
		id++;
	}
	open_box(game);
}

static int32_t	cat_walk(t_game *game, int32_t i, int32_t j)
{
	int32_t	idx;

	idx = -1;
	if (game->map->matrix[i][j] == '0' || game->map->matrix[i][j] == 'C' ||
		game->map->matrix[i][j] == 'P' || (game->map->matrix[i][j] == 'E'
		&& game->star_collected == game->star_total))
	{
		while (++idx < 3)
		{
			game->hero_walk[idx]->instances[game->hero_spot.id].x = j * BLOC;
			game->hero_walk[idx]->instances[game->hero_spot.id].y = i * BLOC;
		}
		game->hero_spot.i = i;
		game->hero_spot.j = j;
		return (1);
	}
	return (0);
}

void	key_motion(mlx_key_data_t keydata, void* param)
{
	t_game	*game;
	int32_t	i;
	int32_t	j;

	game = (t_game *)param;
	hero_animation(game);
	i = game->hero_spot.i;
	j = game->hero_spot.j;
	if (keydata.action == MLX_PRESS)
	{
		if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT))
			j++;
		else if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP))
			i--;
		else if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT))
			j--;
		else if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN))
			i++;
		else if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(game->mlx);
		if (game->map->matrix[i][j] == 'C')
			collect_star(game, i, j);
		else if (game->map->matrix[i][j] == 'E')
		{
			if (game->star_collected == game->star_total)
				mlx_close_window(game->mlx);
		}
		if (cat_walk(game, i, j))
		{
			game->move_count++;
			printf("Movements: %d\n", game->move_count); // PRINTF ORIGINAL *****************
		}
	}
}

