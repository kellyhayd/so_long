/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:09:21 by krocha-h          #+#    #+#             */
/*   Updated: 2024/01/17 13:58:39 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

// Exit the program as failure.
static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

// Print the window width and height.
static void ft_hook(void* param)
{
	// const mlx_t *mlx = param;
	(void)(param);
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
			return (1);
	}
	else
		return (1);
	map = store_map_info(read_map(fd));
	if (!map)
		return (1);
	game = (t_game *)malloc(sizeof(t_game));
	game->map = map;
	mlx = mlx_init((map->width * 64), (map->height * 64), "so_long", true);
	if (!mlx)
		ft_error();
	define_imgs(game, mlx);
	background_resize(mlx, game);
	components_position(mlx, game);
	mlx_key_hook(mlx, &key_motion, game);
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
