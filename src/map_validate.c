/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:33:01 by krocha-h          #+#    #+#             */
/*   Updated: 2024/02/02 17:29:01 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_copy(t_game *game)
{
	char	**map_check;
	int32_t	i;
	int32_t	j;

	map_check = malloc(game->map->height * sizeof(char **));
	if (!map_check)
		return (NULL);
	i = 0;
	while (i < game->map->height)
	{
		map_check[i] = malloc(game->map->width * sizeof(char *));
		if (!map_check[i])
			return (NULL);
		j = 0;
		while (j < game->map->width)
		{
			map_check[i][j] = game->map->matrix[i][j];
			j++;
		}
		i++;
	}
	return (map_check);
}

void map_free(char **map_check, int32_t height)
{
	int32_t	i;

	if (!map_check)
		return ;
	i = 0;
	while (i < height)
	{
		if (!map_check[i])
			break ;
		free(map_check[i]);
		i++;
	}
	free(map_check);
}

int32_t	check_fill_map(char **map_check, t_game *game)
{
	int32_t	star_count;
	int32_t	exit_success;
	int32_t	i;
	int32_t	j;

	star_count = 0;
	exit_success = 0;
	i = -1;
	while (++i < game->map->height)
	{
		j = -1;
		while (++j < game->map->width)
		{
			if (game->map->matrix[i][j] == 'C' &&
				map_check[i][j] == '*')
				star_count++;
			if (game->map->matrix[i][j] == 'E' &&
				map_check[i][j] == '*')
				exit_success = 1;
		}
	}
	return (star_count == game->star_total && exit_success == 1);
}

void	fill_map(char **map_check, int32_t i, int32_t j, t_game *game)
{
	if (i < 0 || j < 0 || i >= game->map->height || j >= game->map->width)
		return ;
	if (map_check[i][j] == '*' || map_check[i][j] == '1')
		return ;
	map_check[i][j] = '*';
	fill_map(map_check, i + 1, j, game);
	fill_map(map_check, i, j + 1, game);
	fill_map(map_check, i - 1, j, game);
	fill_map(map_check, i, j - 1, game);
}

int32_t	validate_map_path(t_game *game)
{
	char	**map_check;
	int32_t	ok;

	map_check = map_copy(game);
	if (!map_check)
	{
		map_free(map_check, game->map->height);
		return (0);
	}
	fill_map(map_check, game->hero_spot.i, game->hero_spot.j, game);
	ok = check_fill_map(map_check, game);
	map_free(map_check, game->map->height);
	return (ok);
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
static int32_t	validate_map_components(t_game *game)
{
	int32_t	i;
	int32_t	j;
	int32_t	count_p;
	int32_t	count_e;

	count_p = 0;
	count_e = 0;
	i = -1;
	while (++i < game->map->height)
	{
		j = -1;
		while (++j < game->map->width)
		{
			if (game->map->matrix[i][j] == 'P')
			{
				game->hero_spot.i = i;
				game->hero_spot.j = j;
				count_p++;
			}
			if (game->map->matrix[i][j] == 'E')
				count_e++;
			if (game->map->matrix[i][j] == 'C')
				game->star_total++;
		}
	}
	return (count_p == 1 && count_e == 1 && game->star_total > 0);
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
	if (!validate_map_path(game))
		return (0);
	return (1);
}
