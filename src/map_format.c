
#include "../include/so_long.h"
#include "../libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

t_map	*store_map_info(t_list *map_list)
{
	t_map	*map_info;
	int32_t	i;

	map_info = (t_map *)malloc(sizeof(t_map));
	if (!map_info)
		return (NULL);
	if (map_list == NULL)
		return (NULL);
	map_info->height = ft_lstsize(map_list);
	map_info->matrix = malloc(map_info->height * sizeof(char *));
	if (!map_info->matrix)
	{
		free(map_info);
		return (NULL);
	}
	i = 0;
	while (map_list != NULL)
	{
		map_info->matrix[i] = (char *)map_list->content;
		map_list = map_list->next;
		i++;
	}
	map_info->width = ft_strlen(map_info->matrix[0]);
	return (map_info);
}

/*
 * @brief Removes the '\n' of the end of each line
 *
 * @ param line the string of the read lineof the map
 */
static void	line_cleaner(char *line)
{
	int32_t	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	line[i] = '\0';
}

t_list	*read_map(int fd)
{
	t_list	*map_list;
	t_list	*current;
	char	*line;

	map_list = NULL;
	while (fd)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		line_cleaner(line);
		current = ft_lstnew(line);
		if (!current)
		{
			ft_lstclear(&map_list, free);
			return (NULL);
		}
		ft_lstadd_back(&map_list, current);
	}
	return (map_list);
}

int main()
{
	int fd;
	int	i;
	t_list	*map_list;
	t_map	*map;

	fd = open("./maps/map_01.ber", O_RDONLY);
	map_list = read_map(fd);
	map = store_map_info(map_list);
	i = 0;
	while (i < map->height)
	{
		printf("linha: %s\n", map->matrix[i]);
		i++;
	}
	printf("HEIGHT: %d\n", map->height);
	printf("WIDTH: %d\n", map->width);
	if (validate_map(map))
		printf("Mapa válido! Sucesso na missão 003\n");
	else
		printf("Mapa torto!\n");
	close(fd);
	return (0);
}