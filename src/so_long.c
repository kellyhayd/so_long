/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:09:21 by krocha-h          #+#    #+#             */
/*   Updated: 2024/02/02 17:19:15 by krocha-h         ###   ########.fr       */
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
// static void ft_hook(void* param)
// {
// 	// const mlx_t *mlx = param;
// 	(void)(param);
// }

int32_t	map_check_ber(char *argv)
{
	int32_t	size;
	char	*type_file;

	size = ft_strlen(argv);
	type_file = ft_substr(argv, (size - 4), 4);
	if (!ft_strnstr(type_file, ".ber", 4))
		return (0);
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
			return (1);
	}
	else
		return (1);
	if (!map_check_ber(argv[1]))
		return (1);
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (0);
	map = store_map_info(read_map(fd));
	if (!map)
		return (1);
	game->map = map;
	if (!validate_map(game))
		return (1);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	mlx = mlx_init((map->width * BLOC), (map->height * BLOC), "so_long", true);
	if (!mlx)
		ft_error();
	game->mlx = mlx;
	define_imgs(game);
	background_resize(game);
	components_position(game);
	// mlx_put_string(mlx, "kelly", 100, 100);
	mlx_loop_hook(mlx, hero_animation, game);
	mlx_key_hook(mlx, &key_motion, game);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
