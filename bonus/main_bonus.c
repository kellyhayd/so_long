/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:09:21 by krocha-h          #+#    #+#             */
/*   Updated: 2024/02/06 14:36:09 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int32_t	main(int argc, char **argv)
{
	int32_t	fd;
	mlx_t	*mlx;
	t_game	*game;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			return (ft_printf("Error opening file"), EXIT_FAILURE);
	}
	else
		return (ft_putstr_fd(MSG_ARGS, 2), EXIT_FAILURE);
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (0);
	init_build(game, argv[1], fd);
	init_game(game, mlx);
	return (EXIT_SUCCESS);
}
