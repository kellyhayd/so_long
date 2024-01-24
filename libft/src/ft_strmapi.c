/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:44:23 by krocha-h          #+#    #+#             */
/*   Updated: 2023/11/09 12:26:15 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/* Applies the function ’f’ to each character of the string ’s’,
passing its index as first argument to create a new string resulting
from successive applications of ’f’ */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	idx;
	unsigned int	i;

	if (!s)
		return (NULL);
	str = malloc ((ft_strlen(s) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	idx = 0;
	while (*s)
	{
		*(str + i) = f(idx++, *s++);
		i++;
	}
	*(str + i) = '\0';
	return (str);
}
