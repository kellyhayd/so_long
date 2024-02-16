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

int32_t	load_game_end(t_game *game)
{
	int32_t			width;
	int32_t			height;
	float			ratio;

	game->sprites.game_over = load_imgs("images/game_over.png", game);
	if (!game->sprites.game_over)
		return (0);
	width = game->sprites.game_over->width;
	height = game->sprites.game_over->height;
	ratio = game->mlx->height / (float)height;
	mlx_resize_image(game->sprites.game_over, width * ratio, height * ratio);
	game->sprites.game_win = load_imgs("images/game_win.png", game);
	if (!game->sprites.game_win)
		return (0);
	width = game->sprites.game_win->width;
	height = game->sprites.game_win->height;
	ratio = game->mlx->height / (float)height;
	mlx_resize_image(game->sprites.game_win, width * ratio, height * ratio);
	game->sprites.end_bg = load_imgs("images/game_end_bg.png", game);
	if (!game->sprites.end_bg)
		return (0);
	mlx_resize_image(game->sprites.end_bg, game->mlx->width, game->mlx->height);
	return (1);
}

int32_t	load_hearts(t_game *game)
{
	int32_t	i;

	i = 0;
	while (i < 3)
	{
		game->sprites.heart[i] = load_imgs("images/icons/heart.png", game);
		game->sprites.no_heart[i] = load_imgs("images/icons/no_heart.png",
				game);
		if (!game->sprites.heart[i] || !game->sprites.no_heart[i])
			return (0);
		mlx_resize_image(game->sprites.heart[i], 46, 41);
		mlx_resize_image(game->sprites.no_heart[i], 46, 41);
		i++;
	}
	game->life_count = 3;
	return (1);
}

int32_t	load_banner(t_game *game)
{
	game->sprites.banner = load_imgs("images/icons/slider.png", game);
	if (!game->sprites.banner)
		return (0);
	mlx_resize_image(game->sprites.banner, 150, 53);
	return (1);
}

int32_t	load_background(t_game *game)
{
	int32_t	width;
	int32_t	height;
	int32_t	ratio;

	game->sprites.bg = load_imgs("images/background/bg4.png", game);
	if (!game->sprites.bg)
		return (0);
	width = game->sprites.bg->width;
	height = game->sprites.bg->height;
	ratio = game->mlx->height / (float)height;
	mlx_resize_image(game->sprites.bg, width * ratio, height * ratio);
	return (1);
}
