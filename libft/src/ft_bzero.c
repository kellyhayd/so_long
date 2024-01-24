/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:13:32 by krocha-h          #+#    #+#             */
/*   Updated: 2023/10/13 12:39:06 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/* Erases the data in n bytes of the memory starting at the location
pointed to by s, by writing zeros to that area */
void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*cast;

	cast = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		cast[i] = 0;
		i++;
	}
	s = (void *)cast;
}
