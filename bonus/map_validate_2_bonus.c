/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate_2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:17:18 by krocha-h          #+#    #+#             */
/*   Updated: 2024/02/06 14:18:41 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int32_t	validate_filename(char *filename)
{
	int32_t	size;
	char	*type_file;

	size = ft_strlen(filename);
	if (size <= 4)
		return (0);
	type_file = ft_substr(filename, (size - 4), 4);
	if (!type_file)
		return (ft_putstr_fd(MSG_MALLOC, 2), EXIT_FAILURE);
	if (!ft_strnstr(type_file, ".ber", 4))
	{
		free(type_file);
		return (0);
	}
	free(type_file);
	return (1);
}

void	validate_char_size(t_game *game)
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
				exit(EXIT_FAILURE);
			}
			j++;
		}
		if (j > game->map->width)
		{
			ft_putstr_fd(MSG_SIZE, 1);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}
