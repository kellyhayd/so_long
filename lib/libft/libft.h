/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:05:25 by krocha-h          #+#    #+#             */
/*   Updated: 2023/11/09 14:55:20 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_list
{
	char			*str;
	void			*content;
	struct s_list	*next;
}	t_list;

////----------------------------------------- Mandatory part

//------------------------------------------- Libc functions

char	*ft_itoa(int n);
int		ft_isascii(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
char	*ft_strchr(const char *s, int c);
char	**ft_split(const char *s, char c);
char	*ft_strrchr(const char *s, int c);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
char	*ft_strtrim(const char *s1, const char *set);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strnstr(const char *big, const char *little, size_t len);

//------------------------------------------- Additional functions

char	*ft_strdup(const char *s);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);

////----------------------------------------- Bonus part

int		ft_lstsize(t_list *lst);

/*
 * @brief Finds the last node of the linked list
 *
 * @param *lst The linked list with the content of the reading
 * @return A pointer to the last node of the list.
 */
t_list	*ft_lstlast(t_list *lst);

t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/*
 * @brief Reads `BUFFER_SIZE` characters at time, returning the next
 * line in file. The characters that was readen and exceed the line.
 * are storaged in a static variable.
 *
 * @param fd File Descriptor
 * @return The `next line` of the file.
 */
char	*get_next_line(int fd);

/*
 * @brief Allocates and creates the string that contains
 * the next line of the fd.
 *
 *  * Call `get_line_len` to calculate the length of line to allocate
 * and `create_str` to copy every character from the nodes.
 *
 * @param *lst The list created of the reading of the file
 * @return The next `line` of the file.
 * @return `NULL` in cases of list is NULL or allocation
 * of line fails.
 */
char	*create_line(t_list *lst);

/*
 * @brief Checks if there is a `\ n` in the list,
 * indicating the end of line.
 *
 * @param *lst The list of characters read
 * @return `True` or `False`
 */
int		has_nl(t_list *lst);

/*
 * @brief Reads the `fd` and allocates `buffer` in a new node of a linked list.
 *
 * @param fd file descriptor
 * @param **lst  a pointer to the list of nodes
 * @param **last_node - a pointer to the last node of the list
 * @return `True` or `False` to the success of the creation of the list.
 * It can fails if allocation of buffer or adding a new node fails.
 */
int		create_lst(int fd, t_list **lst, t_list **last_node);

/*
 * @brief Adds a new node at the end of the linked list with the
 * content of buffer from the last read.
 *
 * @param **lst The linked list with the results of reading
 * @param **last_node The last node of the linked list
 * @param *buffer The content storage from the last reading
 * @return `True` or `False` indicating the success of the function
 */
int		lstadd_node(t_list **lst, t_list **last_node, char *buffer);

/*
 * @brief It will `free` every node of the linked list, except the last one,
 * that could contains characters of the next line.
 *
 * @param **lst The linked list that contains the result of the reading
 */
void	lst_remake(t_list **lst);

/*
 * @brief Copies the characters of each node of the linked list
 * until it finds the `\ n` indicating the end of line.
 * It tests if list is not NULL and guarantee that string will
 * be terminated by a `\0`.
 *
 * @param *lst The linked list that storagem the content read
 * @param *line The char that will storage the characters
 */
void	create_str(t_list *lst, char *line);

/*
 * @brief Searches if there is anything after the `\ n` and storage it in
 * a node that will become the only one of static linked list.
 * After coping the remmant content, it calls `lst_remake` to
 * clean the leftover nodes.
 *
 * @param **lst The linked list with the content of the reading
 * @param *last_node The last node of the list
 */
void	clean_lst(t_list **lst, t_list *last_node);

/*
 * @brief Calculates the length of the string that will contains
 * the nest line of the file.
 *
 * @param *list The list with te content of the reading
 * @return The `size` of the string that will be created.
 */
size_t	get_line_len(t_list *list);


/**
 * @brief Display text according to a format string,
 reproducing printf's behavior.
 *
 * @param str The string 'str' should contain format specifiers,
 * each of  which  are replaced  with  successive arguments
 * according to the specifier.
 * @param arg The argument of any type
 *
 * @details
 * 	* %d: Argument will be used as decimal integer (signed or unsigned)
 * 	* %i: Argument will be used as a signed integer
 * 	* %u: An unsigned decimal integer
 * 	* %x or %X: An unsigned hexadecimal integer
 * 	* %p: The void * pointer argument has to be printed in
 * hexadecimal format
 * 	* %s: A string
 * 	* %c: A character
 * 	* %% signifies a literal "%"
 * @return The number of characters printed
 */
int	ft_printf(const char *str, ...);

/**
 * @brief Identify the type of the arguments acoording to
 the specifier in the string.
 *
 * @param c The specifier after '%' that determinates
 * the type of argument
 * @param ap The list of arguments specified after the string
 * @return The number of characters printed
 */
int	id_type(char c, va_list ap);

/**
 * @brief Prints a character
 *
 * @param c The argument (character)
 * @return The number of characters printed
 */
int	print_char(char c);

/**
 * @brief Prints a string
 *
 * @param str The argument (string)
 * @return The number of characters printed
 */
int	print_str(char *str);

/**
 * @brief Prints a unsigned hexadecimal integer
 *
 * @param num The argument (character)
 * @param c The specifier of type that determinates if
 * the alphabetical characters
 * will be printed in upper or lower case
 * @return The number of characters printed
 */
int	print_hex(unsigned long long num, char c);

/**
 * @brief Prints a void pointer in a hexadecimal format
 *
 * @param ptr The argument (void pointer)
 * @return The number of characters printed
 */
int	print_ptrhex(unsigned long long ptr);

/**
 * @brief Prints a decimal or signed integer
 *
 * @param num The argument (integer)
 * @return The number of characters printed
 */
int	print_dec_int(int num);

/**
 * @brief Prints a unsigned integer
 *
 * @param num The argument (unsigned integer)
 * @return The number of characters printed
 */
int	print_undec(unsigned int num);

/**
 * @brief Prints a character
 *
 * @param c The argument (character)
 * @return The number of characters printed
 */
int	ft_putchar(char c);

/**
 * @brief Prints a string
 *
 * @param str The argument (string)
 * @return The number of characters printed
 */
int	ft_putstr(char *s);


#endif
