/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:33:08 by krocha-h          #+#    #+#             */
/*   Updated: 2024/02/01 20:39:55 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

void	hero_animation(void *param)
{
	t_game	*game;
	static int	counter;

	game = param;
	int32_t			time;
	// int32_t			j;
	static int32_t	i;

	time = (int32_t)mlx_get_time();
	// if (time % 2 == 0)
	// {
	// 	if (game->hero[0]->instances[game->hero_spot.id].enabled == 1)
	// 	{
	// 		game->hero[0]->instances[game->hero_spot.id].enabled = 0;
	// 		game->hero[1]->instances[game->hero_spot.id].enabled = 1;
	// 	}
	// 	else
	// 	{
	// 		game->hero[0]->instances[game->hero_spot.id].enabled = 1;
	// 		game->hero[1]->instances[game->hero_spot.id].enabled = 0;
	// 	}
	// }
	if (counter == 50)
	{
		if (game->hero[0]->instances[game->hero_spot.id].enabled == 1)
		{
			game->hero[0]->instances[game->hero_spot.id].enabled = 0;
			game->hero[1]->instances[game->hero_spot.id].enabled = 1;
		}
		else
		{
			game->hero[0]->instances[game->hero_spot.id].enabled = 1;
			game->hero[1]->instances[game->hero_spot.id].enabled = 0;
		}
		counter = 0;
	}
	counter++;
	printf("%d\n", counter);
}

static void	collect_star(t_game *game, int32_t i, int32_t j)
{
	char	c;
	int32_t	id;

	c = game->map->matrix[i][j];
	if (c == 'C')
	{
		id = 0;
		while (game->star_spot[id].id < game->star_count)
		{
			if (game->star_spot[id].i == i && game->star_spot[id].j == j)
			{
				game->star->instances[game->star_spot[id].id].enabled = 0;
				game->star_collected++;
				break ;
			}
			id++;
		}
	}
}

static int32_t	cat_walk(t_game *game, int32_t i, int32_t j)
{
	if (game->map->matrix[i][j] == '0' || game->map->matrix[i][j] == 'C')
	{
		game->hero[0]->instances[game->hero_spot.id].x = j * BLOC;
		game->hero[0]->instances[game->hero_spot.id].y = i * BLOC;
		game->hero[1]->instances[game->hero_spot.id].x = j * BLOC;
		game->hero[1]->instances[game->hero_spot.id].y = i * BLOC;
		game->hero_spot.i = i;
		game->hero_spot.j = j;
		return (1);
	}
	if (game->map->matrix[i][j] == 'E' && game->star_collected == game->star_count)
	{
		game->hero[0]->instances[game->hero_spot.id].x = j * BLOC;
		game->hero[0]->instances[game->hero_spot.id].y = i * BLOC;
		game->hero[1]->instances[game->hero_spot.id].x = j * BLOC;
		game->hero[1]->instances[game->hero_spot.id].y = i * BLOC;
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
		if (game->map->matrix[i][j] == 'C')
			collect_star(game, i, j);
		if (game->map->matrix[i][j] == 'E')
		{
			if (game->star_collected == game->star_count)
				mlx_close_window(game->mlx);
		}
		if (cat_walk(game, i, j))
		{
			game->move_count++;
			printf("Movements: %d\n", game->move_count); // PRINTF ORIGINAL *****************
		}
	}
}

