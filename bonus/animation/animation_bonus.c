/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:35:15 by krocha-h          #+#    #+#             */
/*   Updated: 2024/02/15 16:56:24 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	open_box(t_game *game)
{
	if (game->star_collected == game->star_total)
	{
		game->sprites.exit[0]->instances[0].enabled = 0;
		game->sprites.exit[1]->instances[0].enabled = 1;
	}
}

/*
 * @brief Updates the animation frames of all enemies
 *
 * @param game pointer to the t_game structure containing game data
 */
static void	enemy_animation(t_game *game)
{
	int32_t	spot;
	int32_t	id;

	spot = 0;
	while (spot < game->enemy_total)
	{
		id = game->enemy[spot].current_frame;
		if (game->sprites.enemy[id]->instances[spot].enabled == 1)
		{
			game->sprites.enemy[id]->instances[spot].enabled = 0;
			id = (id + 1) % 4;
			game->sprites.enemy[id]->instances[spot].enabled = 1;
			game->enemy[spot].current_frame = id;
		}
		spot++;
	}
}

/*
 * @brief Updates the animation frames of all stars (collectible)
 *
 * @param game pointer to the t_game structure containing game data
 */
static void	star_animation(t_game *game)
{
	int32_t	spot;
	int32_t	id;

	spot = 0;
	while (spot < game->star_total)
	{
		id = game->star[spot].current_frame;
		if (game->sprites.star[id]->instances[spot].enabled == 1)
		{
			game->sprites.star[id]->instances[spot].enabled = 0;
			id = (id + 1) % 4;
			game->sprites.star[id]->instances[spot].enabled = 1;
			game->star[spot].current_frame = id;
		}
		spot++;
	}
}

/*
 * @brief Updates the animation frames of the hero
 *
 * @param game pointer to the t_game structure containing game data
 */
static void	hero_animation(t_game *game)
{
	int32_t	id;

	id = game->hero.current_frame;
	if ((id >= 0 && id <= 7) && game->base == WALK_L)
	{
		id = WALK_L;
		game->sprites.hero[game->hero.current_frame]->instances[0].enabled = 0;
		game->sprites.hero[id]->instances[0].enabled = 1;
	}
	if (game->sprites.hero[id]->instances[0].enabled == 1)
	{
		game->sprites.hero[id]->instances[0].enabled = 0;
		if (game->base == WALK_L)
			id = ((id + 1) % 8) + 8;
		else
			id = (id + 1) % 8;
		game->sprites.hero[id]->instances[0].enabled = 1;
		game->hero.current_frame = id;
	}
}

void	animation(void *param)
{
	t_game			*game;
	static int32_t	counter;

	game = param;
	if (counter == 8)
	{
		if (game->enemy_collision == 1)
		{
			game->sprites.hero[game->hero.current_frame]->instances[0].enabled = 0;
			if (game->base == WALK_R)
				game->sprites.hero_red[0]->instances[0].enabled = 1;
			else
				game->sprites.hero_red[1]->instances[0].enabled = 1;
			game->enemy_collision = 0;
		}
		else
		{
			game->sprites.hero[game->hero.current_frame]->instances[0].enabled = 1;
			if (game->sprites.hero_red[0]->instances[0].enabled == 1)
				game->sprites.hero_red[0]->instances[0].enabled = 0;
			else if (game->sprites.hero_red[1]->instances[0].enabled == 1)
				game->sprites.hero_red[1]->instances[0].enabled = 0;
			hero_animation(game);
		}
		enemy_animation(game);
		star_animation(game);
		counter = 0;
	}
	counter++;
}
