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
	int32_t	fd;
	t_map	*map;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			return (1);
	}
	else
		return (1);
	map = (t_map *)malloc(sizeof (t_map));
	if (!map)
		return (1);
	map = store_map_info(read_map(fd));
	if (!map)
		return (1);
	// MLX allows you to define its core behaviour before startup.
	mlx_set_setting(MLX_MAXIMIZED, true);
	mlx_t *mlx = mlx_init(map->width, map->height, "so_long", true);
	if (!mlx)
		ft_error();

	/* Do stuff */

	// Create and display the image.
	// mlx_image_t* img = mlx_new_image(mlx, 256, 256);
	// if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
	// 	ft_error();

	mlx_texture_t* texture = mlx_load_png("images/imagem.png");
	mlx_image_t* img = mlx_texture_to_image(mlx, texture);

	mlx_resize_image(img, 100, 100);

	mlx_image_to_window(mlx, img, 0, 256);

	// Even after the image is being displayed, we can still modify the buffer.
	// mlx_put_pixel(img, 0, 0, 0xFF0000FF);

	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}