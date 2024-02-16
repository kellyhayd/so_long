/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:09:21 by krocha-h          #+#    #+#             */
/*   Updated: 2024/02/15 14:16:58 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int32_t	main(int argc, char **argv)
{
	int32_t	fd;
	int32_t	i;
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	if (argc != 2)
		return (ft_putstr_fd(MSG_ARGS, 2), EXIT_FAILURE);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd(MSG_OPEN_FILE, 2), EXIT_FAILURE);
	if (!init_build(&game, argv[1], fd))
		return (EXIT_FAILURE);
	init_window(&game);
	init_game(&game);
	close(fd);
	i = 0;
	while (i < game.map->height - 1)
	{
		free(game.map->matrix[i]);
		i++;
	}
	free(game.map->matrix);
	free(game.map);
	return (EXIT_SUCCESS);
}
