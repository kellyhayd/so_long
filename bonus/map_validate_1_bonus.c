/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate_1_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:33:01 by krocha-h          #+#    #+#             */
/*   Updated: 2024/02/08 17:11:21 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/*
 * @brief Checks if the number of components are as
 * required
 *
 * @param map_info struct wich contains width, heigh
 * and the matrix of the lines of the map
 *
 * @return True or False
 */
static int32_t	validate_map_components(t_game *game)
{
	int32_t	i;
	int32_t	j;
	int32_t	counter[2];

	ft_bzero(counter, sizeof(int) * 2);
	i = -1;
	while (++i < game->map->height)
	{
		j = -1;
		while (++j < game->map->width)
		{
			if (game->map->matrix[i][j] == 'P')
			{
				game->hero_r.i = i;
				game->hero_r.j = j;
				counter[0]++;
			}
			if (game->map->matrix[i][j] == 'E')
				counter[1]++;
			if (game->map->matrix[i][j] == 'C')
				game->star_total++;
			if (game->map->matrix[i][j] == 'X')
				game->enemy_total++;
		}
	}
	return (counter[0] == 1 && counter[1] == 1 && game->star_total > 0);
}

/*
 * @brief Checks if bottom and top are wall
 *
 * @param map_info struct wich contains width, heigh
 * and the matrix of the lines of the map
 *
 * @return True or False
 */
static int32_t	validate_top_bottom(t_game *game)
{
	int32_t	i;

	i = 0;
	while (i < game->map->width)
	{
		if (game->map->matrix[0][i] != '1' ||
			game->map->matrix[game->map->height - 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

/*
 * @brief Checks if the lateral borders are wall
 *
 * @param map_info struct wich contains width, heigh
 * and the matrix of the lines of the map
 *
 * @return True or False
 */
static int32_t	validate_map_border(t_game *game)
{
	int32_t	i;
	int32_t	j;

	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			if ((game->map->matrix[i][0] != '1') ||
				(game->map->matrix[i][game->map->width - 1] != '1'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	validate_map(t_game *game, t_map *map)
{
	validate_char_size(game);
	if (!validate_map_border(game) || !validate_top_bottom(game))
	{
		ft_putstr_fd(MSG_WALL, 2);
		exit(EXIT_FAILURE);
	}
	if (!validate_map_components(game))
	{
		ft_putstr_fd(MSG_COMPONENTS, 2);
		exit(EXIT_FAILURE);
	}
	if (!validate_map_path(game))
	{
		ft_putstr_fd(MSG_NOPATH, 2);
		exit(EXIT_FAILURE);
	}
}
