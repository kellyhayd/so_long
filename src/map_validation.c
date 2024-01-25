
#include "../include/so_long.h"
#include "../libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

char	**create_map_matrix(t_list *map_list)
{
	char	**map_matrix;
	int32_t	height;
	int32_t	i;

	if (map_list == NULL)
		return (NULL);
	height = ft_lstsize(map_list);
	map_matrix = malloc (height * sizeof(char *));
	if (!map_matrix)
		return (NULL);
	i = 0;
	while (map_list != NULL)
	{
		map_matrix[i] = (char *)map_list->content;
		map_list = map_list->next;
		i++;
	}
	return (map_matrix);
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
		current = ft_lstnew(line);
		if (map_list == NULL)
			map_list = current;
		else
			ft_lstadd_back(&map_list, current);
	}
	return (map_list);
}

int main()
{
	int fd;
	int	i;
	t_list	*map_list;
	char	**map_matrix;

	fd = open("./maps/map_01.ber", O_RDONLY);
	map_list = read_map(fd);
	map_matrix = create_map_matrix(map_list);
	printf("linha: %s\n", map_matrix[0]);
	printf("linha: %s\n", map_matrix[1]);
	printf("linha: %s\n", map_matrix[2]);
	printf("linha: %s\n", map_matrix[3]);
	printf("linha: %s\n", map_matrix[4]);
	close(fd);
	return (0);
}