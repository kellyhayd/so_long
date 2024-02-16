/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_hero_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:42:44 by krocha-h          #+#    #+#             */
/*   Updated: 2024/02/15 16:30:55 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int32_t	check_load_heros(t_game *game)
{
	int32_t	i;

	i = -1;
	while (++i < 16)
	{
		if (!game->sprites.hero[i])
			return (0);
		mlx_resize_image(game->sprites.hero[i], BLOC, BLOC);
	}
	return (1);
}

int32_t	load_heros(t_game *game)
{
	game->sprites.hero[0] = load_imgs("images/cats/cat_r0.png", game);
	game->sprites.hero[1] = load_imgs("images/cats/cat_r1.png", game);
	game->sprites.hero[2] = load_imgs("images/cats/cat_r2.png", game);
	game->sprites.hero[3] = load_imgs("images/cats/cat_r3.png", game);
	game->sprites.hero[4] = load_imgs("images/cats/cat_r4.png", game);
	game->sprites.hero[5] = load_imgs("images/cats/cat_r5.png", game);
	game->sprites.hero[6] = load_imgs("images/cats/cat_r6.png", game);
	game->sprites.hero[7] = load_imgs("images/cats/cat_r7.png", game);
	game->sprites.hero[8] = load_imgs("images/cats/cat_l0.png", game);
	game->sprites.hero[9] = load_imgs("images/cats/cat_l1.png", game);
	game->sprites.hero[10] = load_imgs("images/cats/cat_l2.png", game);
	game->sprites.hero[11] = load_imgs("images/cats/cat_l3.png", game);
	game->sprites.hero[12] = load_imgs("images/cats/cat_l4.png", game);
	game->sprites.hero[13] = load_imgs("images/cats/cat_l5.png", game);
	game->sprites.hero[14] = load_imgs("images/cats/cat_l6.png", game);
	game->sprites.hero[15] = load_imgs("images/cats/cat_l7.png", game);
	return (check_load_heros(game));
}

int32_t	load_hero_red(t_game *game)
{
	game->sprites.hero_red[0] = load_imgs("images/cats/cat_xr1.png", game);
	if (!game->sprites.hero_red[0])
		return (0);
	game->sprites.hero_red[1] = load_imgs("images/cats/cat_xl1.png", game);
	if (!game->sprites.hero_red[1])
		return (0);
	mlx_resize_image(game->sprites.hero_red[0], BLOC, BLOC);
	mlx_resize_image(game->sprites.hero_red[1], BLOC, BLOC);
	return (1);
}
