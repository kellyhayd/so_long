
// #include "../include/so_long.h"
#include "../libft/libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <aio.h>

int32_t	validate_map(int fd)
{
	char	*line;
	int		i;
	int32_t	count_p = 0;
	int32_t	count_e = 0;
	int32_t	count_c = 0;
	int32_t	fst_line_size = 0;
	int32_t	lst_line_size = 0;

	line = get_next_line(fd); //leitura da primeira linha que precisa ser parede
	fst_line_size = ft_strlen(line); //primeira linha define tamanho do mapa
	printf("%s\n", line); //EXCLUIR *****
	while (*line != '\n')
	{
		if (!(ft_strchr(line, '1')))
		{
			printf("primeira linha deu erro\n"); //EXCLUIR *****
			return (0); //erro de parede 
		}
		else
			*line++;
	}
	printf("tamanho da PRIMEIRA linha = %d\n", fst_line_size); //EXCLUIR *****
	while (fd)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		if (!ft_strchr(line, '\n'))
			lst_line_size = ft_strlen(line) + 1;
		else
			lst_line_size = ft_strlen(line);
		printf("%s\n", line); //EXCLUIR *****
		printf("tamanho da linha atual = %d\n", lst_line_size); //EXCLUIR *****
		if (lst_line_size != fst_line_size) //todas as linhas precisam ter o mesmo tamanho
			return (printf("mapa torto")); //erro de formato
		i = 0;
		while (line[i])
		{
			if (line[0] != '1' || line[ft_strlen(line) - 2] != '1')
			{
				printf("%c\n", line[i]); //EXCLUIR *****
				return (0); //erro de parede
			}
			if (line[i] == 'P')
				count_p++;
			else if (line[i] == 'C')
				count_c++;
			else if (line[i] == 'E')
				count_e++;
			i++;
		}
	}
	printf("START = %d\n", count_p); //EXCLUIR *****
	printf("EXIT = %d\n", count_e); //EXCLUIR *****
	printf("COLLECTIBLES = %d\n", count_c); //EXCLUIR *****
	if (count_p > 1 || count_p <= 0)
		return (0); //erro de posição start
	if (count_e > 1 || count_e <= 0)
		return (0); //erro de saída
	if (count_c <= 0)
		return (0); //erro de colecionáveis
	return (1); //sucesso! mapa aprovado!
}

int main()
{
	int fd;

	fd = open("./maps/map_01.ber", O_RDONLY);
	if (validate_map(fd) == 1)
		printf("sucesso na missão!\n");
	else
		printf("deu ruim no mapa\n");
	return (0);
}