/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:33:01 by krocha-h          #+#    #+#             */
/*   Updated: 2024/02/19 10:23:33 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
 * @brief Checks if there is any unexpected character
 *
 * @details Must have only `P`, `E`, `C`, `0`, `1` or `X`
 *
 * @param game pointer to the t_game structure containing game data
 */
static int32_t	validate_char(t_game *game)
{
	int32_t	i;
	int32_t	j;

	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			if (!ft_strchr("PEC01X", game->map->matrix[i][j]))
			{
				ft_putstr_fd(MSG_CHAR, 2);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

/*
 * @brief Checks if there is any inexpected component (!= 10PECX) or
 * if the map is not rectangular
 *
 * @param game pointer to the t_game structure containing game data
 *
*/
static int32_t	validate_size(t_game *game)
{
	int32_t	i;

	if (game->map->width < 3 || game->map->height < 3)
	{
		ft_putstr_fd(MSG_SIZE, 1);
		return (0);
	}
	i = 0;
	while (i < game->map->height)
	{
		if (game->map->width != (int32_t)ft_strlen(game->map->matrix[i]))
		{
			ft_putstr_fd(MSG_SIZE, 1);
			return (0);
		}
		i++;
	}
	return (1);
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

int32_t	validate_map(t_game *game)
{
	if (!validate_size(game) || !validate_char(game))
		return (0);
	if (!validate_map_border(game) || !validate_top_bottom(game))
	{
		ft_putstr_fd(MSG_WALL, 2);
		return (0);
	}
	if (!validate_map_components(game))
	{
		ft_putstr_fd(MSG_COMPONENTS, 2);
		return (0);
	}
	if (!validate_map_path(game))
	{
		ft_putstr_fd(MSG_NOPATH, 2);
		return (0);
	}
	return (1);
}
