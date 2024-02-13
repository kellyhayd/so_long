# Prints error message to stdout instead of stderr

Either prints all errors to stdout or all to stderr.

- bonus/main_bonus.c:24
- so_long_bonus.c:37
- so_long_bonus.c:56

# Uses local variable instead of constant in .h for error message

Prefer to organize and document all error messages in one place, the .h file.

- bonus/main_bonus.c:24
- so_long_bonus.c:37
- so_long_bonus.c:56

# Segfault if map filename length is less than 4 characters

When doing math, like subtracting a value, ensure that value can't has unexpected results.

- bonus/map_validate_2_bonus.c, map_check_ber, size may be less than 4 characters resulting in segfault

# Potential segfault if ft_substr can't allocate

ft_substr may return NULL if it can't allocate memory, but the result is passed directly to
ft_strnstr. Although ft_strnstr does `big[i] != '\0'` starting at i = 0, effectively if big is NULL
big[0] is also NULL, and NULL is 0 which is '\0'. As a good practise, though, ensure result of functions
that return char * isn't NULL before using the return.

- bonus/map_validate_2_bonus.c, map_check_ber

# Allocated memory not freed after ft_substr

ft_substr returns NULL on error or an allocated char * on success. In the case of success, this memory
need to be freed after it is not useful anymore. 

- bonus/map_validate_2_bonus.c, map_check_ber

# Allocated memory not freed after read_map

read_map allocates and returns a t_list*. init_build calls read_map and pass the return
directly to store_map_info. Neither init_build nor store_map_info deallocates the t_list*
and the char* it carries.

If a function returns allocated memory, it is usually the caller function's responsability to
manage that memory or return that responsability to is own caller.

In this case, init_build(..) should manage the memory allocated by read_map. Therefore I suggest
init_build to call read_map and stores its resulting t_list* in a local variable, call 
store_map_info and then deallocate the t_list* and its c-strings.

- so_long_bonus.c init_build
