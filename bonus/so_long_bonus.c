/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:34:42 by krocha-h          #+#    #+#             */
/*   Updated: 2024/02/06 17:36:22 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int32_t	init_game(t_game *game)
{
	display_components(game);
	mlx_loop_hook(game->mlx, animation, game);
	mlx_key_hook(game->mlx, key_motion, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (1);
}

void	init_window(t_game *game)
{
	mlx_t	*mlx;
	int32_t	height;
	int32_t	width;

	height = game->map->height;
	width = game->map->width;
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	mlx = mlx_init((width * BLOC), (height * BLOC), "so_long", true);
	if (!mlx)
	{
		ft_printf("Error inicializing mlx\n");
		exit(EXIT_FAILURE);
	}
	game->mlx = mlx;
	define_imgs(game);
}

void	init_build(t_game *game, char *argv, int32_t fd)
{
	t_map			*map;

	if (!map_check_ber(&argv[1]))
	{
		ft_putstr_fd(MSG_BER, 2);
		exit(EXIT_FAILURE);
	}
	map = store_map_info(read_map(fd));
	if (!map)
	{
		ft_printf("Error in memory allocation\n");
		exit(EXIT_FAILURE);
	}
	game->map = map;
	validate_map(game, map);
}
