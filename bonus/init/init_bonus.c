/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:34:42 by krocha-h          #+#    #+#             */
/*   Updated: 2024/02/15 16:07:14 by krocha-h         ###   ########.fr       */
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
		ft_putstr_fd(MSG_MALLOC, 2);
		exit(EXIT_FAILURE);
	}
	game->mlx = mlx;
	define_imgs(game);
}

/*
 * @brief A placeholder function used for ft_lstclear to avoid memory leaks
 */
static void	do_nothing(void *unused)
{
	(void)(unused);
}

int32_t	init_build(t_game *game, char *filename, int32_t fd)
{
	t_map	*map;
	t_list	*map_list;

	if (!validate_filename(filename))
	{
		ft_putstr_fd(MSG_BER, 2);
		return (0);
	}
	map_list = read_map(fd);
	if (!map_list)
	{
		ft_putstr_fd(MSG_MALLOC, 2);
		return (0);
	}
	map = store_map_info(map_list);
	ft_lstclear(&map_list, do_nothing);
	if (!map)
	{
		ft_putstr_fd(MSG_MALLOC, 2);
		return (0);
	}
	game->map = map;
	return (validate_map(game));
}
