/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion1_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:33:08 by krocha-h          #+#    #+#             */
/*   Updated: 2024/02/16 13:55:50 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	define_direction(t_game *game, int32_t j)
{
	if (j > game->hero.j)
		game->base = WALK_R;
	if (j < game->hero.j)
		game->base = WALK_L;
}

/*
 * @brief This function handles the movement of the hero character in a game.
 * It checks for collisions and updates the hero's position and animation state
 *
 * @param game pointer to the t_game structure containing game data
 * @param i width position on the map
 * @param j height position on the map
 *
 * @return `1` Movement successful and hero position updated
 * @return `0` Movement failed due to collision or other conditions
 */
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
		define_direction(game, j);
		game->sprites.hero_red[0]->instances[0].x = j * BLOC;
		game->sprites.hero_red[1]->instances[0].x = j * BLOC;
		game->sprites.hero_red[0]->instances[0].y = i * BLOC;
		game->sprites.hero_red[1]->instances[0].y = i * BLOC;
		while (++idx < 16)
		{
			game->sprites.hero[idx]->instances[0].x = j * BLOC;
			game->sprites.hero[idx]->instances[0].y = i * BLOC;
		}
		game->hero.i = i;
		game->hero.j = j;
		return (1);
	}
	return (0);
}

/*
 * @brief Once a key has been pressed,
 * the function decides the necessary action to be taken
 *
 * @details The function also prints in terminal the number
 * of steps taken in the game
 *
 * @param game pointer to the t_game structure containing game data
 * @param i width position on the map
 * @param j height position on the map
 */
static void	define_action(t_game *game, int32_t i, int32_t j)
{
	float	x;
	float	y;

	x = (game->mlx->width - game->sprites.game_win->width) / 2;
	y = (game->mlx->height - game->sprites.game_win->height) / 2;
	if (game->map->matrix[i][j] == 'C')
		collect_star(game, i, j);
	if (game->map->matrix[i][j] == 'E')
	{
		if (game->star_collected == game->star_total)
		{
			mlx_image_to_window(game->mlx, game->sprites.end_bg, 0, 0);
			mlx_image_to_window(game->mlx, game->sprites.game_win, x, y);
			game->close_game = 1;
		}
	}
	if ((i != game->hero.i || j != game->hero.j) && cat_walk(game, i, j))
	{
		game->move_count++;
		if (game->move_count == 1)
			ft_printf("Nestor moved %d time\n", game->move_count);
		else
			ft_printf("Nestor moved %d times\n", game->move_count);
	}
	steps_to_window(game);
}

void	key_motion(mlx_key_data_t keydata, void *param)
{
	t_game	*game;
	int32_t	i;
	int32_t	j;

	game = (t_game *)param;
	i = game->hero.i;
	j = game->hero.j;
	if (keydata.action == MLX_PRESS)
	{
		if (game->close_game == 0)
		{
			if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT))
				j++;
			else if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP))
				i--;
			else if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT))
				j--;
			else if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN))
				i++;
			define_action(game, i, j);
		}
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(game->mlx);
	}
}
