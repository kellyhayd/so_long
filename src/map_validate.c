/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:33:01 by krocha-h          #+#    #+#             */
/*   Updated: 2024/02/02 16:17:59 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	validate_map_path(t_map *map_info, t_game *game)
// {
// 	char	**map;
// 	int32_t	star_count;
// 	int32_t	i;
// 	int32_t	j;

// 	map = map_info->matrix;
// 	i = 0;
// 	while (i < map_info->width)
// 	{
// 		j = 0;
// 		while (j < map_info->height)
// 		{
// 			if (map_info->matrix[i][j] == 'P')
// 				break ;
// 			j++;
// 		}
// 		i++;
// 	}
// }


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
	int32_t	count_p;
	int32_t	count_e;
	int32_t	count_c;

	count_p = 0;
	count_e = 0;
	count_c = 0;
	i = -1;
	while (++i < game->map->height)
	{
		j = -1;
		while (++j < game->map->width)
		{
			if (game->map->matrix[i][j] == 'P')
				count_p++;
			if (game->map->matrix[i][j] == 'E')
				count_e++;
			if (game->map->matrix[i][j] == 'C')
				count_c++;
		}
	}
	game->star_total = count_c;
	return (count_p == 1 && count_e == 1 && count_c > 0);
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
			return (0); // erro das paredes de topo || base
		i++;
	}
	return (1); //tudo certo com topo || base
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
				return (0); // erro nas paredes laterais
			j++;
		}
		i++;
	}
	return (1);
}

int32_t	validate_map(t_game *game)
{
	int32_t	i;
	int32_t	j;

	if (!validate_map_border(game) || !validate_top_bottom(game))
		return (0);
	if (!validate_map_components(game))
		return (0);
	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			if (!ft_strchr("PEC01X", game->map->matrix[i][j]))
				return (0);
			j++;
		}
		if (j > game->map->width)
			return (0);
		i++;
	}
	return (1);
}
