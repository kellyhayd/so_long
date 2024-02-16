#include "so_long_bonus.h"

void	hero_collision(t_game *game)
{
	int32_t	id;

	id = game->hero.current_frame;
	if (game->enemy_collision == 1)
	{
		game->sprites.hero[id]->instances[0].enabled = 0;
		if (game->base == WALK_R)
			game->sprites.hero_red[0]->instances[0].enabled = 1;
		else
			game->sprites.hero_red[1]->instances[0].enabled = 1;
		game->enemy_collision = 0;
	}
	else
	{
		game->sprites.hero[id]->instances[0].enabled = 1;
		if (game->sprites.hero_red[0]->instances[0].enabled == 1)
			game->sprites.hero_red[0]->instances[0].enabled = 0;
		else if (game->sprites.hero_red[1]->instances[0].enabled == 1)
			game->sprites.hero_red[1]->instances[0].enabled = 0;
		hero_animation(game);
	}
}

void	open_box(t_game *game)
{
	if (game->star_collected == game->star_total)
	{
		game->sprites.exit[0]->instances[0].enabled = 0;
		game->sprites.exit[1]->instances[0].enabled = 1;
	}
}