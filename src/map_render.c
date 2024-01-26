
#include "so_long.h"
#include "libft.h"
#include <fcntl.h>
#include <stdio.h>

void	define_titles(mlx_t *mlx, mlx_image_t* img, t_map *map_info)
{
	int32_t	i;
	int32_t	j;

	i = 0;
	while (i < map_info->height)
	{
		j = 0;
		while (j < map_info->width)
		{
			if (map_info->matrix[i][j] == '1')
				mlx_image_to_window(mlx, img, j * 50, i * 50);
			j++;
		}
		i++;
	}
}