/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:33:08 by krocha-h          #+#    #+#             */
/*   Updated: 2024/02/08 14:34:22 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int32_t	cat_walk(t_game *game, int32_t i, int32_t j)
{
	int32_t	idx;

	idx = -1;
	if (game->map->matrix[i][j] == 'X')
		enemy_collision(game);
	if (game->map->matrix[i][j] == '0' || game->map->matrix[i][j] == 'C' ||
		game->map->matrix[i][j] == 'P' || (game->map->matrix[i][j] == 'E'
		&& game->star_collected == game->star_total))
	{
		while (++idx < 8)
		{
			game->sprites.hero_r[idx]->instances[0].x = j * BLOC;
			game->sprites.hero_r[idx]->instances[0].y = i * BLOC;
		}
		game->hero_r.i = i;
		game->hero_r.j = j;
		return (1);
	}
	return (0);
}

void	define_action(t_game *game, int32_t i, int32_t j)
{
	int32_t			x;
	int32_t			y;

	x = (game->mlx->width - game->sprites.game_over->width) / 2;
	y = (game->mlx->height - game->sprites.game_over->height) / 2;
	if (game->map->matrix[i][j] == 'C')
			collect_star(game, i, j);
	if (game->map->matrix[i][j] == 'E')
	{
		if (game->star_collected == game->star_total)
		{
			mlx_image_to_window(game->mlx, game->sprites.end_bg, 0, 0);
			mlx_image_to_window(game->mlx, game->sprites.game_win, x, y);
		}
	}
	if ((i != game->hero_r.i || j != game->hero_r.j) && cat_walk(game, i, j))
	{
		game->move_count++;
		if (game->move_count == 1)
			ft_printf("Nestor moved %d time\n", game->move_count);
		else
			ft_printf("Nestor moved %d times\n", game->move_count);
	}
	steps_to_window(game);
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

