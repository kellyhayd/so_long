/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:17:18 by krocha-h          #+#    #+#             */
/*   Updated: 2024/02/15 10:36:17 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/*
 * @brief Finds the starting position of the hero character on the game map
 *
 * @param game pointer to the t_game structure containing game data
 *
 * @return `1` if the hero is found and its position is stored in game->hero,
 * `0` otherwise
 */
static int32_t	map_find_hero(t_game *game)
{
	int32_t	i;
	int32_t	j;

	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			if (game->map->matrix[i][j] == 'P')
			{
				game->hero.i = i;
				game->hero.j = j;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

/*
 * @brief Counts the occurrences of a specific character in the game map
 *
 * @param game pointer to the t_game structure containing game data
 * @param c the character (component) to count occurrences of
 *
 * @return The number of occurrences of the character c in the map
 */
static int32_t	map_count_occurrences(t_game *game, char c)
{
	int32_t	i;
	int32_t	j;
	int32_t	counter;

	counter = 0;
	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			if (game->map->matrix[i][j] == c)
				counter++;
			j++;
		}
		i++;
	}
	return (counter);
}

/*
 * @brief Checks if the number of components are as
 * required
 *
 * @param map_info struct wich contains width, heigh
 * and the matrix of the lines of the map
 *
 * @return True or False
 */
int32_t	validate_map_components(t_game *game)
{
	int32_t	players;
	int32_t	exits;

	players = map_count_occurrences(game, 'P');
	exits = map_count_occurrences(game, 'E');
	game->star_total = map_count_occurrences(game, 'C');
	game->enemy_total = map_count_occurrences(game, 'X');
	return (map_find_hero(game) && players == 1
		&& exits == 1 && game->star_total > 0);
}

int32_t	validate_filename(char *filename)
{
	int32_t	size;
	char	*type_file;

	size = ft_strlen(filename);
	if (size <= 4)
		return (0);
	type_file = ft_substr(filename, (size - 4), 4);
	if (!type_file)
	{
		ft_putstr_fd(MSG_MALLOC, 2);
		exit(EXIT_FAILURE);
	}
	if (!ft_strnstr(type_file, ".ber", 4))
	{
		free(type_file);
		return (0);
	}
	free(type_file);
	return (1);
}
