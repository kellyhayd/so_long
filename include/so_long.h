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

#define BLOC 64

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include "libft.h"
# include "MLX42.h"

#include <stdio.h> //************************************************************************//

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
	mlx_t		*mlx;
	mlx_image_t	*hero_walk[8];
	mlx_image_t	*tile;
	mlx_image_t	*star;
	mlx_image_t	*enemy;
	mlx_image_t	*exit;
	mlx_image_t	*bg;
	t_icon		hero_spot;
	t_icon		star_spot[1000];
	int32_t		star_total;
	int32_t		star_collected;
	int32_t		move_count;
}	t_game;

// --------------------- Map Functions -------------------------//

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

/*
 * @brief Places each component at its correspondent position in the map.
 *
 * @param game the struct that contains all the necessaries information
 * of the game (map, components information, position and count)
 */
void	components_position(t_game *game);

// --------------------- Image Functions -------------------------//

/*
 * @brief Defines all images to be placed in the window.
 *
 * @param game the struct that contains all the necessaries information
 * of the game (map, components information, position and count)
 */
void	define_imgs(t_game *game);

/*
 * @brief Defines the sprites of the hero
 *
 * @param game the struct that contains all the necessaries information
 * of the game (map, components information, position and count)
 */
void	store_heros(t_game *game);

/*
 * @brief Load a PNG file into a buffer and converts it to an image
 *
 * @param path the path to the PNG file
 * @param game the struct that contains all the necessaries information
 * of the game (map, components information, position and count)
 *
 * @return `mlx_image_t` The image created from the texture
 */
mlx_image_t	*store_imgs(const char *path, t_game *game);

/*
 * @brief Resizes the background considering the size of the window
 *
 * @param game the struct that contains all the necessaries information
 * of the game (map, components information, position and count)
 */
void	background_resize(t_game *game);

// --------------------- Motion Functions -------------------------//

/*
 * @brief Main function that defines action with determined key motion
 *
 * @param keydata Key function callback data.
 * Data related to the mlx_key_hook function
 * @param param The parameter which will have the necessary information so
 * that the game can move foward
 */
void	key_motion(mlx_key_data_t keydata, void* param);

void	hero_animation(void *param);



#endif
