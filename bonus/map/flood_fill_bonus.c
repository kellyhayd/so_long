/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate_path_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:35:01 by krocha-h          #+#    #+#             */
/*   Updated: 2024/02/08 15:33:38 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	**map_copy(t_game *game)
{
	char	**map_check;
	int32_t	i;
	int32_t	j;

	map_check = ft_calloc(game->map->height, sizeof(char **));
	if (!map_check)
		return (NULL);
	i = 0;
	while (i < game->map->height)
	{
		map_check[i] = ft_calloc(game->map->width, sizeof(char *));
		if (!map_check[i])
		{
			ft_putstr_fd(MSG_MALLOC, 2);
			exit(EXIT_FAILURE);
		}
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

void	map_free(char **map_check, int32_t height)
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
	if (map_check[i][j] == '*' || map_check[i][j] == '1'
			|| map_check[i][j] == 'X')
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
		ft_putstr_fd(MSG_MALLOC, 2);
		exit(EXIT_FAILURE);
		return (0);
	}
	fill_map(map_check, game->hero_r.i, game->hero_r.j, game);
	ok = check_fill_map(map_check, game);
	map_free(map_check, game->map->height);
	return (ok);
}
