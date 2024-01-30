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

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include "libft.h"
# include "MLX42.h"

typedef struct s_icon
{
	int32_t	j;
	int32_t	i;
	int32_t	id;
}	t_icon;

typedef struct s_map
{
	int32_t	width;
	int32_t	height;
	char	**matrix;
}	t_map;

typedef struct s_game
{
	t_map		*map;
	mlx_image_t	*hero;
	mlx_image_t	*tile;
	mlx_image_t	*star;
	mlx_image_t	*enemy;
	mlx_image_t	*bg;
	t_icon		hero_spot;
	t_icon		star_spot[1000];
	int32_t		star_count;
}	t_game;



// --------------------- Map Functions

/*
 * @brief Reads the map, storing the lines in a linked list
 *
 * @details After using get_next_line to store the line, it needs
 * to have the '\n' removed and store in a node of the linked list
 *
 * @param fd the map file
 *
 * @return map_list the linked list with each line in a node
 */
t_list	*read_map(int fd);

/*
 * @brief Store map information and the content in a struct
 *
 * @param map_list the linked list that contains the read lines
 *
 * @return t_map the struct with the content of the map and also
 * informations like width and height
 */
t_map	*store_map_info(t_list *map_list);

/*
 * @brief Validates whether the map matches the requirements
 *
 * @details Call functions that checks if the borders, the bottom
 * and the top are walls, validates if the number of components
 * are correct and the type as expected, and guarantee that
 * the map is rectangular.
 *
 * @param map_info struct wich contains width, heigh
 * and the matrix of the lines of the map
 *
 * @return True or False
*/
int32_t	validate_map(t_map *map_info);

void	components_position(mlx_t *mlx, t_game *game);

void	define_imgs(t_game *game, mlx_t *mlx);

void	key_motion(mlx_key_data_t keydata, void* param);

void	background_resize(mlx_t *mlx, t_game *game);

#endif
