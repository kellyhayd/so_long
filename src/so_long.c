/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:09:21 by krocha-h          #+#    #+#             */
/*   Updated: 2024/02/06 12:45:21 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int32_t	init_game(t_game *game, mlx_t *mlx, t_map *map)
{
	if (!validate_map(game))
		return (0);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	mlx = mlx_init((map->width * BLOC), (map->height * BLOC), "so_long", true);
	if (!mlx)
		return (0);
	game->mlx = mlx;
	define_imgs(game);
	background_resize(game);
	components_position(game);
	mlx_loop_hook(mlx, animation, game);
	mlx_key_hook(mlx, &key_motion, game);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (1);
}

int32_t	main(int argc, char **argv)
{
	int32_t			fd;
	t_map			*map;
	mlx_t			*mlx;
	t_game			*game;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			return (ft_printf("Error opening file"), EXIT_FAILURE);
	}
	else
		return (ft_putstr_fd(MSG_ARGS, 2), EXIT_FAILURE);
	if (!map_check_ber(argv[1]))
		return (ft_putstr_fd(MSG_BER, 2), EXIT_FAILURE);
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (0);
	map = store_map_info(read_map(fd));
	if (!map)
		return (1);
	game->map = map;
	mlx = NULL;
	if (!init_game(game, mlx, map))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
