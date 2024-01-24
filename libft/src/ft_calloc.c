/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:03:17 by krocha-h          #+#    #+#             */
/*   Updated: 2023/11/08 13:11:10 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/* Reserves storage space for an array of nmemb elements of size bytes each,
and initializes the values of all elements to 0 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*dst;
	size_t	total_size;

	total_size = (nmemb * size);
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (total_size / size != nmemb)
		return (NULL);
	dst = malloc(total_size);
	if (!dst)
		return (NULL);
	ft_bzero(dst, total_size);
	return (dst);
}
