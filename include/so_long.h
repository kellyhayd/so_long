/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:10:08 by krocha-h          #+#    #+#             */
/*   Updatedt_: 2024/01/17 13:55:40 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H


#	include <stdlib.h>
#	include <stdio.h>
#	include <unistd.h>
#	include <string.h>
#	include "MLX42/MLX42.h"


#	define WIDTH 256
#	define HEIGHT 256

/**
 * Main MLX handle, carries important data in regards to the program.
 * @param window The window itself.
 * @param context Abstracted opengl data.
 * @param width The width of the window.
 * @param height The height of the window.
 * @param delta_time The time difference between the previous frame and the current frame.
//  */
// typedef struct	s_mlx
// {
// 	void	*window;
// 	void	*context;
// 	int32_t	width;
// 	int32_t	height;
// 	double	delta_time;
// }	t_mlx;

typedef struct s_fmt_map
{
	int32_t	start;
	int32_t	exit;
	int32_t	collectibles;
}	t_fmt_map;

#endif
