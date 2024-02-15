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

void	load_heros(t_game *game)
{
	int32_t	i;

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
	i = 0;
	while (i < 16)
	{
		mlx_resize_image(game->sprites.hero[i], BLOC, BLOC);
		i++;
	}
}

void	load_hero_red(t_game *game)
{
	game->sprites.hero_red[0] = load_imgs("images/cats/cat_xr1.png", game);
	game->sprites.hero_red[1] = load_imgs("images/cats/cat_xl1.png", game);
	mlx_resize_image(game->sprites.hero_red[0], BLOC, BLOC);
	mlx_resize_image(game->sprites.hero_red[1], BLOC, BLOC);
}
