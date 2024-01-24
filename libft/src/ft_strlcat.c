/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:53:30 by krocha-h          #+#    #+#             */
/*   Updated: 2023/11/09 12:25:31 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/* Appends the NUL-terminated string src to the end of dst. It will append
1 byte at most size strlen(dst), NUL-terminating the result. Return the
total length of the string it tried to create*/
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d;
	size_t	i;

	d = ft_strlen(dst);
	if (d >= size)
		return (size + ft_strlen(src));
	i = 0;
	if (d < size)
	{
		while (size > d + 1 && src[i] != '\0')
		{
			dst[d + i] = src[i];
			i++;
			size--;
		}
	}
	dst[d + i] = '\0';
	return (d + ft_strlen(src));
}
