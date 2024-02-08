/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:33:08 by krocha-h          #+#    #+#             */
/*   Updated: 2024/02/06 17:17:07 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	collect_star(t_game *game, int32_t i, int32_t j)
{
	int32_t	id;

	id = 0;
	while (id < game->star_total)
	{
		if (game->star_spot[id].i == i && game->star_spot[id].j == j
			&& game->star.instances[id]->enabled == 1)
		{
			game->star.instances[id] = 0;
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
		while (++idx < 8)
		{
			game->hero_r.instances[idx]->x = j * BLOC;
			game->hero_r.instances[idx]->y = i * BLOC;
		}
		game->hero_r.i = i;
		game->hero_r.j = j;
		return (1);
	}
	return (0);
}

void	define_action(t_game *game, int32_t i, int32_t j)
{
	if (game->map->matrix[i][j] == 'C')
			collect_star(game, i, j);
	else if (game->map->matrix[i][j] == 'E')
	{
		if (game->star_collected == game->star_total)
			mlx_close_window(game->mlx);
	}
	if ((i != game->hero_r.i || j != game->hero_r.j) && cat_walk(game, i, j))
	{
		game->move_count++;
		if (game->move_count == 1)
			ft_printf("Nestor moved %d time\n", game->move_count);
		else
			ft_printf("Nestor moved %d times\n", game->move_count);
	}
}

void	key_motion(mlx_key_data_t keydata, void* param)
{
	t_game	*game;
	int32_t	i;
	int32_t	j;

	game = (t_game *)param;
	i = game->hero_r.i;
	j = game->hero_r.j;
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
		define_action(game, i, j);
	}
}

