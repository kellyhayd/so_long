/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_imgs_1_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:35:09 by krocha-h          #+#    #+#             */
/*   Updated: 2024/02/06 14:44:43 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_enemies(t_game *game)
{
	game->sprites.enemy[0] = load_imgs("images/skull/skull_01.png", game);
	game->sprites.enemy[1] = load_imgs("images/skull/skull_02.png", game);
	game->sprites.enemy[2] = load_imgs("images/skull/skull_03.png", game);
	game->sprites.enemy[3] = load_imgs("images/skull/skull_04.png", game);
}

void	load_heros(t_game *game)
{
	game->sprites.hero_r[0] = load_imgs("images/cats/cat_01.png", game);
	game->sprites.hero_r[1] = load_imgs("images/cats/cat_02.png", game);
	game->sprites.hero_r[2] = load_imgs("images/cats/cat_03.png", game);
	game->sprites.hero_r[3] = load_imgs("images/cats/cat_04.png", game);
	game->sprites.hero_r[4] = load_imgs("images/cats/cat_05.png", game);
	game->sprites.hero_r[5] = load_imgs("images/cats/cat_06.png", game);
	game->sprites.hero_r[6] = load_imgs("images/cats/cat_07.png", game);
	game->sprites.hero_r[7] = load_imgs("images/cats/cat_08.png", game);
}

mlx_image_t	*load_imgs(const char *path, t_game *game)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png(path);
	img = mlx_texture_to_image(game->mlx, texture);
	mlx_resize_image(img, BLOC, BLOC);
	mlx_delete_texture(texture);
	return (img);
}

void	define_imgs(t_game *game)
{
	game->sprites.tile = load_imgs("images/tiles/tile2.png", game);
	game->sprites.exit = load_imgs("images/box/box_closed.png", game);
	game->sprites.banner = load_imgs("images/basics/Banners/orange.png", game);
	load_heros(game);
	load_enemies(game);
	load_stars(game);
	load_background(game);
	load_banner(game);
	load_hearts(game);
	load_game_end(game);
}
