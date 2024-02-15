/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:20:26 by krocha-h          #+#    #+#             */
/*   Updated: 2024/02/15 16:10:18 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_map(t_game *game)
{
	int32_t	i;

	i = 0;
	while (i < game->map->height)
	{
		free(game->map->matrix[i]);
		i++;
	}
	// free(game->map);
}

void	free_sprite(t_game *game)
{
	int32_t	i;

	i = 0;
	while (i < 16)
	{
		mlx_delete_image(game->mlx, game->sprites.hero[i]);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		mlx_delete_image(game->mlx, game->sprites.star[i]);
		mlx_delete_image(game->mlx, game->sprites.enemy[i]);
		i++;
	}
	i = 0;
	while (i < 3)
	{
		mlx_delete_image(game->mlx, game->sprites.heart[i]);
		mlx_delete_image(game->mlx, game->sprites.no_heart[i]);
		i++;
	}
	i = 0;
	while (i < 2)
	{
		mlx_delete_image(game->mlx, game->sprites.exit[i]);
		i++;
	}
	mlx_delete_image(game->mlx, game->sprites.game_win);
	mlx_delete_image(game->mlx, game->sprites.game_over);
	mlx_delete_image(game->mlx, game->sprites.end_bg);
	mlx_delete_image(game->mlx, game->sprites.tile);
	mlx_delete_image(game->mlx, game->sprites.bg);
	mlx_delete_image(game->mlx, game->sprites.banner);
	mlx_delete_image(game->mlx, game->print_steps);

}

void	free_memory(t_game *game)
{
	free_map(game);
	// free_sprite(game);
	free(game);
}
