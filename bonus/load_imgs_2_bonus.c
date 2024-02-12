/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_imgs_2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:40:39 by krocha-h          #+#    #+#             */
/*   Updated: 2024/02/08 18:22:32 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_game_end(t_game *game)
{
	mlx_texture_t	*texture;
	int32_t			width;
	int32_t			height;
	float			ratio;

	texture = mlx_load_png("images/game_over.png");
	game->sprites.game_over = mlx_texture_to_image(game->mlx, texture);
	width = game->sprites.game_over->width;
	height = game->sprites.game_over->height;
	ratio = game->mlx->height / (float)height;
	mlx_resize_image(game->sprites.game_over, width * ratio, height * ratio);
	texture = mlx_load_png("images/game_win.png");
	game->sprites.game_win = mlx_texture_to_image(game->mlx, texture);
	width = game->sprites.game_win->width;
	height = game->sprites.game_win->height;
	ratio = game->mlx->height / (float)height;
	mlx_resize_image(game->sprites.game_win, width * ratio, height * ratio);
	texture = mlx_load_png("images/game_end_bg.png");
	game->sprites.end_bg = mlx_texture_to_image(game->mlx, texture);
	mlx_resize_image(game->sprites.end_bg, game->mlx->width, game->mlx->height);
	mlx_delete_texture(texture);
}

void	load_hearts(t_game *game)
{
	int32_t			i;
	mlx_texture_t	*texture;

	i = 0;
	while (i < 3)
	{
		texture = mlx_load_png("images/basics/Icons/heart.png");
		game->sprites.heart[i] = mlx_texture_to_image(game->mlx, texture);
		mlx_resize_image(game->sprites.heart[i], 46, 41);
		mlx_delete_texture(texture);
		i++;
	}
	i = 0;
	while (i < 3)
	{
		texture = mlx_load_png("images/basics/Icons/no_heart.png");
		game->sprites.no_heart[i] = mlx_texture_to_image(game->mlx, texture);
		mlx_resize_image(game->sprites.no_heart[i], 46, 41);
		mlx_delete_texture(texture);
		i++;
	}
	game->life_count = 3;
}

void	load_banner(t_game *game)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("images/basics/Sliders/orange.png");
	game->sprites.banner = mlx_texture_to_image(game->mlx, texture);
	mlx_resize_image(game->sprites.banner, 150, 53);
	mlx_delete_texture(texture);
}

void	load_background(t_game *game)
{
	mlx_texture_t	*texture;
	int32_t			width;
	int32_t			height;
	int32_t			ratio;

	texture = mlx_load_png("images/background/bg4.png");
	game->sprites.bg = mlx_texture_to_image(game->mlx, texture);
	width = game->sprites.bg->width;
	height = game->sprites.bg->height;
	ratio = game->mlx->height / (float)height;
	mlx_resize_image(game->sprites.bg, width * ratio, height * ratio);
	mlx_delete_texture(texture);
}

void	load_stars(t_game *game)
{
	game->sprites.star[0] = load_imgs("images/flasks/flasks_01.png", game);
	game->sprites.star[1] = load_imgs("images/flasks/flasks_02.png", game);
	game->sprites.star[2] = load_imgs("images/flasks/flasks_03.png", game);
	game->sprites.star[3] = load_imgs("images/flasks/flasks_04.png", game);
}
