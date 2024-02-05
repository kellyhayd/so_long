/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:02:00 by krocha-h          #+#    #+#             */
/*   Updated: 2023/12/19 14:22:06 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

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
