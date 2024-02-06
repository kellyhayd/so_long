
#include "so_long_bonus.h"

void	load_background(t_game *game)
{
	mlx_texture_t	*texture;
	int32_t			width;
	int32_t			height;
	int32_t			ratio;

	texture = mlx_load_png("images/background/bg4.png");
	game->sprites.bg = mlx_texture_to_image(game->mlx, texture);
	width = game->sprites.bg->width;
	height = game->sprites.bg->height;
	ratio = game->mlx->height / (float)height;
	mlx_resize_image(game->sprites.bg, width * ratio, height * ratio);
}

void	load_stars(t_game *game)
{
	game->sprites.star[0] = load_imgs("images/flasks/flasks_01.png", game);
	game->sprites.star[1] = load_imgs("images/flasks/flasks_02.png", game);
	game->sprites.star[2] = load_imgs("images/flasks/flasks_03.png", game);
	game->sprites.star[3] = load_imgs("images/flasks/flasks_04.png", game);
}

void	load_enemies(t_game *game)
{
	game->sprites.enemy[0] = load_imgs("images/skull/skull_01.png", game);
	game->sprites.enemy[1] = load_imgs("images/skull/skull_02.png", game);
	game->sprites.enemy[2] = load_imgs("images/skull/skull_03.png", game);
	game->sprites.enemy[3] = load_imgs("images/skull/skull_04.png", game);
}

void	load_heros(t_game *game)
{
	game->sprites.hero_r[0] = load_imgs("images/cats/cat_01.png", game);
	game->sprites.hero_r[1] = load_imgs("images/cats/cat_02.png", game);
	game->sprites.hero_r[2] = load_imgs("images/cats/cat_03.png", game);
	game->sprites.hero_r[3] = load_imgs("images/cats/cat_04.png", game);
	game->sprites.hero_r[4] = load_imgs("images/cats/cat_05.png", game);
	game->sprites.hero_r[5] = load_imgs("images/cats/cat_06.png", game);
	game->sprites.hero_r[6] = load_imgs("images/cats/cat_07.png", game);
	game->sprites.hero_r[7] = load_imgs("images/cats/cat_08.png", game);
}

mlx_image_t	*load_imgs(const char *path, t_game *game)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png(path);
	img = mlx_texture_to_image(game->mlx, texture);
	mlx_resize_image(img, BLOC, BLOC);
	return (img);

}

void	define_imgs(t_game *game)
{
	game->sprites.tile = load_imgs("images/tiles/tile2.png", game);
	game->sprites.exit = load_imgs("images/box/box_closed.png", game);
	game->sprites.banner = load_imgs("images/basics/Banners/Banner_Orange.png", game);
	load_heros(game);
	load_enemies(game);
	load_stars(game);
	load_background(game);
}