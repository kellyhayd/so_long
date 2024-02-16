/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load1_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:35:09 by krocha-h          #+#    #+#             */
/*   Updated: 2024/02/15 16:53:54 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/*
 * @brief Loads the star's (collectible) animation frames from image
 * files and resizes them
 *
 * @param game pointer to the t_game structure containing game data
 */
static int32_t	load_stars(t_game *game)
{
	int32_t	i;

	game->sprites.star[0] = load_imgs("images/flasks/flasks_01.png", game);
	game->sprites.star[1] = load_imgs("images/flasks/flasks_02.png", game);
	game->sprites.star[2] = load_imgs("images/flasks/flasks_03.png", game);
	game->sprites.star[3] = load_imgs("images/flasks/flasks_04.png", game);
	i = 0;
	while (i < 4)
	{
		if (!game->sprites.star[i])
			return (0);
		mlx_resize_image(game->sprites.star[i], BLOC, BLOC);
		i++;
	}
	return (1);
}

/*
 * @brief Loads the enemy character's animation frames from image
 * files and resizes them
 *
 * @param game pointer to the t_game structure containing game data
 */
static int32_t	load_enemies(t_game *game)
{
	int32_t	i;

	game->sprites.enemy[0] = load_imgs("images/skull/skull_01.png", game);
	game->sprites.enemy[1] = load_imgs("images/skull/skull_02.png", game);
	game->sprites.enemy[2] = load_imgs("images/skull/skull_03.png", game);
	game->sprites.enemy[3] = load_imgs("images/skull/skull_04.png", game);
	i = 0;
	while (i < 4)
	{
		if (!game->sprites.enemy[i])
			return (0);
		mlx_resize_image(game->sprites.enemy[i], BLOC, BLOC);
		i++;
	}
	return (1);
}

mlx_image_t	*load_imgs(const char *path, t_game *game)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png(path);
	if (!texture)
	{
		ft_putstr_fd(MSG_LOAD, 2);
		return (0);
	}
	img = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	return (img);
}

int32_t	define_imgs(t_game *game)
{
	game->sprites.tile = load_imgs("images/tiles/tile2.png", game);
	if (!game->sprites.tile)
		return (0);
	mlx_resize_image(game->sprites.tile, BLOC, BLOC);
	game->sprites.exit[0] = load_imgs("images/box/box_closed.png", game);
	if (!game->sprites.exit[0])
		return (0);
	mlx_resize_image(game->sprites.exit[0], BLOC, BLOC);
	game->sprites.exit[1] = load_imgs("images/box/box_open.png", game);
	if (!game->sprites.exit[1])
		return (0);
	mlx_resize_image(game->sprites.exit[1], BLOC, BLOC);
	if (!load_heros(game) || !load_hero_red(game) || !load_enemies(game))
		return (0);
	if (!load_stars(game))
		return (0);
	load_background(game);
	load_banner(game);
	load_hearts(game);
	load_game_end(game);
	return (1);
}
