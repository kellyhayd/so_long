
#include "../include/so_long.h"
#include "../libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

/*
 * @brief Checks if the number of components are as
 * required
 *
 * @param map_info struct wich contains width, heigh
 * and the matrix of the lines of the map
 * 
 * @return True or False
 */
static int32_t	validate_map_components(t_map *map_info)
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
	while (++i < map_info->height)
	{
		j = -1;
		while (++j < map_info->width)
		{
			if (map_info->matrix[i][j] == 'P')
				count_p++;
			if (map_info->matrix[i][j] == 'E')
				count_e++;
			if (map_info->matrix[i][j] == 'C')
				count_c++;
		}
	}
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
static int32_t	validate_top_bottom(t_map *map_info)
{
	int32_t	i;

	i = 0;
	while (i < map_info->width)
	{
		if (map_info->matrix[0][i] != '1' ||
			map_info->matrix[map_info->height - 1][i] != '1')
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
static int32_t	validate_map_border(t_map *map_info)
{
	int32_t	i;
	int32_t	j;

	i = 0;
	while (i < map_info->height)
	{
		j = 0;
		while (j < map_info->width)
		{
			if ((map_info->matrix[i][0] != '1') ||
				(map_info->matrix[i][map_info->width - 1] != '1'))
				return (0); // erro nas paredes laterais
			j++;
		}
		i++;
	}
	return (1);
}

int32_t	validate_map(t_map *map_info)
{
	int32_t	i;
	int32_t	j;

	if (!validate_map_border(map_info) || !validate_top_bottom(map_info))
		return (0);
	if (!validate_map_components(map_info))
		return (0);
	i = 0;
	while (i < map_info->height)
	{
		j = 0;
		while (j < map_info->width)
		{
			if (!ft_strchr("PEC01X", map_info->matrix[i][j]))
				return (0);
			j++;
		}
		if (j > map_info->width)
			return (0);
		i++;
	}
	return (1);
}
