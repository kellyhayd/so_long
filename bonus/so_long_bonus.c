
#include "so_long_bonus.h"

int32_t	init_game(t_game *game, mlx_t	*mlx)
{
	display_components(game);
	mlx_loop_hook(mlx, animation, game);
	mlx_key_hook(mlx, &key_motion, game);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (1);
}

void	init_window(t_game *game)
{
	mlx_t	*mlx;

	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	mlx = mlx_init((game->map->width * BLOC), (game->map->height * BLOC), "so_long", true);
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

	if (!map_check_ber(argv[1]))
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
	validate_map(game);
}

