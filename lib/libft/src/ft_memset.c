/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 09:15:41 by krocha-h          #+#    #+#             */
/*   Updated: 2023/11/09 14:38:02 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/* Sets n bytes of dest to a value c */
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*cast;

	cast = (unsigned char *)s;
	while (n--)
	{
		cast[n] = (unsigned char)c;
	}
	return (s);
}
