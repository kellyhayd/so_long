/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:10:08 by krocha-h          #+#    #+#             */
/*   Updated: 2024/02/08 15:40:18 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# define BLOC 64

# define MSG_OPEN_FILE "Error opening file"
# define MSG_ARGS "Error\nYou need to set a map!\n"
# define MSG_BER "Error\nThe map needs to be '.ber'\n"
# define MSG_CHAR "Error\nThere's some character wrong in this map\n"
# define MSG_COMPONENTS "Error\nTsc! Tsc! Wrong number of components\n"
# define MSG_NOPATH "Error\nThere is no way out in this map, dude!\n"
# define MSG_WALL "Error\nThe player can't run away! We need walls!\n"
# define MSG_SIZE "Error\nThe map must be rectangular\n"
# define MSG_MALLOC "Error in memory allocation\n"
# define MSG_LOAD "Error in loading image\n"

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include "libft.h"
# include "MLX42.h"
# include <stdio.h>

typedef struct s_icon
{
	int32_t	i;
	int32_t	j;
	int32_t	current_frame;
}	t_icon;

typedef struct s_sprites
{
	mlx_image_t	*hero_l[8];
	mlx_image_t	*hero_r[8];
	mlx_image_t	*hero_u[3];
	mlx_image_t	*hero_d[3];
	mlx_image_t	*star[4];
	mlx_image_t	*enemy[4];
	mlx_image_t	*heart[3];
	mlx_image_t	*no_heart[3];
	mlx_image_t	*exit[2];
	mlx_image_t	*game_over;
	mlx_image_t	*game_win;
	mlx_image_t	*end_bg;
	mlx_image_t	*tile;
	mlx_image_t	*banner;
	mlx_image_t	*bg;
}	t_sprites;

typedef struct s_map
{
	int32_t	width;
	int32_t	height;
	char	**matrix;
}	t_map;

typedef struct s_game
{
	mlx_t		*mlx;
	t_map		*map;
	t_sprites	sprites;
	t_icon		hero_r;
	t_icon		enemy[100];
	t_icon		star[100];
	int32_t		star_total;
	int32_t		enemy_total;
	int32_t		life_count;
	int32_t		star_collected;
	int32_t		move_count;
	mlx_image_t	*print_steps;
}	t_game;

// --------------------- Init Game Functions -------------------------//

/*
 * @brief Initializes the game map by reading and validating it from a file
 * 
 * @details Validate filename: calls the validate_filename function
 * to check if the filename is valid;
 * Read map data: calls the read_map function to read the map data
 * from the file or using the provided fd;
 * Store map info: calls the store_map_info function to convert the
 * read map data into a map structure and store it in game->map;
 * Validate map: calls the validate_map function to check
 * if the map data is valid for the game
 * 
 * @param game pointer to the t_game structure containing game data
 * @param filename name of the map file to load
 * @param file descriptor for the map file 
 */
void		init_build(t_game *game, char *argv, int32_t fd);

/*
 * @brief Initializes the display window and sets up MLX settings
 * 
 * @details Get window dimensions: retrieves the map dimensions
 * from the game->map structure;
 * Enable image stretching: sets the MLX setting MLX_STRETCH_IMAGE
 * to true to allow image resizing without distortion;
 * Create MLX instance: initializes an MLX instance with the calculated
 * window size and the title "so_long", and saves it in game->mlx;
 * Error handling: checks if mlx creation was successful, and exits with
 * an error message if not;
 * Define images: calls the define_imgs function to load and resize game images
 * 
 * @param game pointer to the t_game structure containing game data
 */
void		init_window(t_game *game);

/*
 * @brief Initializes the game loop, sets up event handlers,
 * and runs the game until completion
 * 
 * @details Display components: calls the display_components function 
 * to presumably display initial game elements like the map and UI;
 * Set animation loop: sets up the game loop using mlx_loop_hook to call
 * the animation function periodically;
 * Set key press handler: sets up a key press handler using mlx_key_hook
 * to call the key_motion function for handling player input;
 * Start game loop: runs the game loop using mlx_loop to process events
 * and update the game state
 * 
 * @param game pointer to the t_game structure containing game data
 * 
 * @return 1 on successful game completion, error code otherwise
 */
int32_t		init_game(t_game *game);

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
t_list		*read_map(int fd);

/*
 * @brief Store map information and the content in a struct
 *
 * @param map_list the linked list that contains the read lines
 *
 * @return t_map the struct with the content of the map and also
 * informations like width and height
 */
t_map		*store_map_info(t_list *map_list);

/*
 * @brief Checks if the map file is `.ber` format
 *
 * @param argv the path of the map that has been open by main
 *
 * @return `true` or `false`
 */
int32_t		validate_filename(char *argv);

/*
 * @brief Validates whether the map matches the requirements
 *
 * @details Call functions that checks if the borders, the bottom
 * and the top are walls, validates if the number of components
 * are correct and the type as expected, and guarantee that
 * the map is rectangular.
 *
 * @param game pointer to the t_game structure containing game data
 *
 * @return `true` or `false`
*/
void		validate_map(t_game *game);

/*
 * @brief Checks if there is a possible way out of the map
 * collecting all the collectibles
 *
 * @param game pointer to the t_game structure containing game data
 *
 * @return `true` or `false`
 */
int32_t		validate_map_path(t_game *game);

/*
 * @brief Checks if there are the correct number of components
 *
 * @details Must have only one player and one exit and
 * at least one collectible
 * 
 * @param game pointer to the t_game structure containing game data
 * 
 * @return `true` or `false`
*/
int32_t		validate_map_components(t_game *game);

// --------------------- Load Images Functions -------------------------//

/*
 * @brief Defines all images to be placed in the window.
 *
 * @param game pointer to the t_game structure containing game data
 */
void		define_imgs(t_game *game);

/*
 * @brief Load a PNG file into a buffer and converts it to an image
 *
 * @param path the path to the PNG file
 * @param game pointer to the t_game structure containing game data
 *
 * @return `mlx_image_t` The image created from the texture
 */
mlx_image_t	*load_imgs(const char *path, t_game *game);

/*
 * @brief Loads the game background image, resizes it to
 * fit the window height and duplicate it if necessary
 *
 * @param game pointer to the t_game structure containing game data
 */
void		load_background(t_game *game);

/*
 * @brief Loads the image (banner) that is the background
 * of the steps print on the window and resize it
 *
 * @param game pointer to the t_game structure containing game data
 */
void		load_banner(t_game *game);

/*
 * @brief Loads and resizes heart images representing the
 * player's remaining lives
 * 
 * @details Loads red hearts that represent the remaining lifes
 * and empty hearts representing the lost lifes
 *
 * @param game pointer to the t_game structure containing game data
 */
void		load_hearts(t_game *game);

/*
 * @brief Loads and resizes images for game over and game win scenarios
 * 
 * @param game pointer to the t_game structure containing game data
 */
void		load_game_end(t_game *game);

// --------------------- Display Images Functions -------------------------//

/*
 * @brief Places each component at its correspondent position in the map.
 *
 * @param game pointer to the t_game structure containing game data
 */
void		display_components(t_game *game);

/*
 * @brief Places each star at its correspondent position in the map.
 *
 * @details Places all the frames and keep only the first one enabled.
 *
 * @param game pointer to the t_game structure containing game data
 * @param i the width of the position in the map
 * @param j the height of the position in the map
 */
void		display_star(t_game *game, int32_t i, int32_t j);

/*
 * @brief Places each enemy at its correspondent position in the map.
 *
 * @details Places all the frames and keep only the first one enabled.
 *
 * @param game pointer to the t_game structure containing game data
 * @param i the width of the position in the map
 * @param j the height of the position in the map
 */
void		display_enemy(t_game *game, int32_t i, int32_t j);

/*
 * @brief Places the hero at its correspondent position in the map.
 *
 * @details Places all the frames and keep only the first one enabled.
 *
 * @param game pointer to the t_game structure containing game data
 * @param i the width of the position in the map
 * @param j the height of the position in the map
 */
void		display_hero(t_game *game, int32_t i, int32_t j);

/*
 * @brief Places the exit of the game
 *
 * @details Keeps enabled the closed box
 *
 * @param game pointer to the t_game structure containing game data
 * @param i the width of the position in the map
 * @param j the height of the position in the map
 */
void		display_exit(t_game *game, int32_t i, int32_t j);

/*
 * @brief Places the background, calculating the proportional resize
 * and duplicating it if width of image is smaler than window
 *
 * @param game pointer to the t_game structure containing game data
 */
void		display_background(t_game *game);

/*
 * @brief Places the banner that will show the steps count
 *
 * @param game pointer to the t_game structure containing game data
 */
void		display_banner(t_game *game);

/*
 * @brief Places the hearts and "no_hearts" that wil show the lifes of hero
 *
 * @param game pointer to the t_game structure containing game data
 */
void		display_lifes(t_game *game);

// --------------------- Motion Functions -------------------------//

/*
 * @brief Main function that defines action with determined key motion
 *
 * @param keydata Key function callback data.
 * Data related to the mlx_key_hook function
 * @param param The parameter which will have the necessary information so
 * that the game can move foward
 */
void		key_motion(mlx_key_data_t keydata, void *param);

/*
 * @brief Collects a star at the given position and updates game state
 *
 * @details Calls the open_box function, likely to handle opening a box
 * if all the stars were collected
 * 
 * @param game pointer to the t_game structure containing game data
 * @param i row index of the star's position on the map
 * @param j column index of the star's position on the map
 */
void		collect_star(t_game *game, int32_t i, int32_t j);

/*
 * @brief Handles collision with an enemy, reducing player
 * life and displaying game over if necessary
 * 
 * @param game pointer to the t_game structure containing game data
 */
void		enemy_collision(t_game *game);

/*
 * @brief Updates the displayed step count on the game window
 *
 * @param game pointer to the t_game structure containing game data
 */
void		steps_to_window(t_game *game);

// --------------------- Animation Functions -------------------------//

/*
 * @brief Manages overall game animation by periodically calling
 * specific animation functions
 * 
 * @details Increment counter a static counter; 
 * Check if the counter reaches 8: calls hero_animation, enemy_animation,
 * and star_animation functions to update their respective animations
 */
void		animation(void *param);

/*
 * @brief Changes the exit image to an open state when all stars are collected
 *
 * @param game pointer to the t_game structure containing game data
 */
void		open_box(t_game *game);

#endif
