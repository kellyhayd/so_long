## Prints error message to stdout instead of stderr

Either prints all errors to stdout or all to stderr.

- bonus/main_bonus.c:24
- so_long_bonus.c:37
- so_long_bonus.c:56

## Uses local variable instead of constant in .h for error message

Prefer to organize and document all error messages in one place, the .h file.

- bonus/main_bonus.c:24
- so_long_bonus.c:37
- so_long_bonus.c:56

## Segfault if map filename length is less than 4 characters

When doing math, like subtracting a value, ensure that value can't has unexpected results.

- bonus/map_validate_2_bonus.c, map_check_ber, size may be less than 4 characters resulting in segfault

## Potential segfault if ft_substr can't allocate

ft_substr may return NULL if it can't allocate memory, but the result is passed directly to
ft_strnstr. Although ft_strnstr does `big[i] != '\0'` starting at i = 0, effectively if big is NULL
big[0] is also NULL, and NULL is 0 which is '\0'. As a good practise, though, ensure result of functions
that return char * isn't NULL before using the return.

- bonus/map_validate_2_bonus.c, map_check_ber

## Allocated memory not freed after ft_substr

ft_substr returns NULL on error or an allocated char * on success. In the case of success, this memory
need to be freed after it is not useful anymore. 

- bonus/map_validate_2_bonus.c, map_check_ber

## Allocated memory not freed after read_map

read_map allocates and returns a t_list*. init_build calls read_map and pass the return
directly to store_map_info. Neither init_build nor store_map_info deallocates the t_list*
and the char* it carries.

If a function returns allocated memory, it is usually the caller function's responsability to
manage that memory or return that responsability to is own caller.

In this case, init_build(..) should manage the memory allocated by read_map. Therefore I suggest
init_build to call read_map and stores its resulting t_list* in a local variable, call 
store_map_info and then deallocate the t_list* and its c-strings.

- so_long_bonus.c init_build

## validate_map should check map row sizes before other more advanced checks

validate_map calls validate_map_border which assumes all rows have the same length as the first
row, which is map->width.

consider calling validate_char_size before any other validation, as validate_char_size confirms
map has a proper shape (all rows have the same size and have valid characters).

- map_validate_1_bonus.c

## validate_map returns MSG_CHAR instead of MSG_SIZE for rows smaller than first row

This happens because `ft_strchr("PEC01X", game->map->matrix[i][j])` returns false when 
j < map->width and points to a '\0'. This causes the code to print MSG_CHAR.

Consider doing a specific length test to check the row matches the width, like:
`if (game->map->width != ft_strlen(game->map->matrix[i]))...`, for all i. This makes the 
validation clear to whom is reading it. 

As a general rule, optimize code for readability over performance and writing.

## validate_char_size allows 0-width

validate_char_size should print error and exit if map has zero length rows.
zero-length rows are permitted at this point, and other validators assume there is at least
one character available per row, like validate_map_border, which may result in segfault when
map has zero characters.

## simplify validate_map_path parameter removing t_map

The t_map passed to validate_map_path is obtained from the t_game passed as well.
This aligns better with other validators.

# (OPTIONAL) Allocations that can't fail should be immediately followed by error message and EXIT_FAILURE

There are allocations that can't fail. Examples are any t_game or t_map allocations will 
cause the game to crash or exit. Like the validate_* functions, guard these allocations with an
if statement that when failed print a standard error message and exit with failure.

