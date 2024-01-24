
// #include "../include/so_long.h"
#include "../libft/libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <aio.h>

int32_t	check_components(int32_t start, int32_t exit, int32_t collectibles)
{
	if (start > 1 || start == 0)
		return (0); //erro de posição start
	if (exit > 1 || exit == 0)
		return (0); //erro de saída
	if (collectibles == 0)
		return (0); //erro de colecionáveis
	return (1);
}

char	*read_line(int fd, int32_t fst_line_size)
{
	char	*line;
	int32_t	lst_line_size;

	lst_line_size = 0;
	line = get_next_line(fd);
	if (line == NULL)
		return (NULL);
	if (!ft_strchr(line, '\n'))
		lst_line_size = ft_strlen(line) + 1;
	else
		lst_line_size = ft_strlen(line);
	if (lst_line_size != fst_line_size) //todas as linhas precisam ter o mesmo tamanho
		return (NULL); //erro de formato
	return (line);
}

int32_t	check_format(int fd, int32_t fst_line_size) //MAIS DE 25 LINHAS, CHATONETTE DO CAPETA!!!!
{
	int		i;
	char	*line;
	int32_t	count_p;
	int32_t	count_e;
	int32_t	count_c;

	count_p = 0;
	count_e = 0;
	count_c = 0;
	while (fd)
	{
		line = read_line(fd, fst_line_size);
		if (line == NULL)
			break;
		i = 0;
		while (line[i])
		{
			if (line[0] != '1' || line[ft_strlen(line) - 2] != '1')
				return (0); //erro de parede
			if (line[i] == 'P')
				count_p++;
			else if (line[i] == 'E')
				count_e++;
			else if (line[i] == 'C')
				count_c++;
			i++;
		}
	}
	if (!check_components(count_p, count_e, count_c))
		return (0);
	return (1);
}

int32_t	validate_map(int fd)
{
	char	*line;
	int32_t	fst_line_size = 0;

	line = get_next_line(fd); //leitura da primeira linha que precisa ser parede
	fst_line_size = ft_strlen(line); //primeira linha define tamanho do mapa
	if (!ft_strchr(line, '1'))
		return (0);
	if (!check_format(fd, fst_line_size))
		return (0);
	return (1); //sucesso! mapa aprovado!
}

int main()
{
	int fd;

	fd = open("./maps/map_01.ber", O_RDONLY);
	if (validate_map(fd) == 1)
		printf("sucesso na missão! mapa 1 aprovado!\n");
	else
		printf("xiii... deu ruim no mapa 1\n");
	close(fd);

	fd = open("./maps/map_02.ber", O_RDONLY);
	if (validate_map(fd) == 1)
		printf("sucesso na missão! mapa 2 aprovado!\n");
	else
		printf("xiii... deu ruim no mapa 2\n");
	close(fd);
	return (0);
}