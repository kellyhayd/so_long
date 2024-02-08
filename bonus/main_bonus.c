/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:09:21 by krocha-h          #+#    #+#             */
/*   Updated: 2024/02/08 16:10:21 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int32_t	main(int argc, char **argv)
{
	int32_t	fd;
	t_game	*game;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			return (ft_printf("Error opening file"), EXIT_FAILURE);
	}
	else
		return (ft_putstr_fd(MSG_ARGS, 2), EXIT_FAILURE);
	game = (t_game *)ft_calloc(sizeof(t_game), 1);
	if (!game)
		return (0);
	init_build(game, argv[1], fd);
	init_window(game);
	init_game(game);
	return (EXIT_SUCCESS);
}
