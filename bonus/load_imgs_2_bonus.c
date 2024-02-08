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

void	load_banner(t_game *game)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("images/basics/Banners/orange.png");
	game->sprites.banner = mlx_texture_to_image(game->mlx, texture);
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
}

void	load_stars(t_game *game)
{
	game->sprites.star[0] = load_imgs("images/flasks/flasks_01.png", game);
	game->sprites.star[1] = load_imgs("images/flasks/flasks_02.png", game);
	game->sprites.star[2] = load_imgs("images/flasks/flasks_03.png", game);
	game->sprites.star[3] = load_imgs("images/flasks/flasks_04.png", game);
}
