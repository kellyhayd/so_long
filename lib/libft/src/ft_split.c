/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:58:11 by krocha-h          #+#    #+#             */
/*   Updated: 2023/11/09 12:24:24 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/* Allocates and returns an array of strings obtained by splitting ’s’ using
the character ’c’ as a delimiter. The array must end with a NULL pointer */
static size_t	word_count(const char *s, char c)
{
	size_t	count;

	count = 0;
	if (*s == '\0' || !s)
		return (0);
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s != c && *s)
				s++;
		}
		else if (*s == c)
			s++;
	}
	return (count);
}

static size_t	word_len(const char *src, char sep)
{
	size_t	i;

	i = 0;
	while (src[i] != sep && src[i])
		i++;
	return (i);
}

static void	free_array(size_t i, char **array)
{
	while (i > 0)
	{
		i--;
		free(*(array + i));
	}
	free(array);
}

char	**ft_split(const char *s, char c)
{
	char	**array;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	array = malloc (sizeof(char *) * (word_count(s, c) + 1));
	if (!array || !s)
		return (NULL);
	while (i < word_count(s, c))
	{
		while (s[j] && s[j] == c)
			j++;
		array[i] = ft_substr(s, j, word_len(&s[j], c));
		if (!array[i])
		{
			free_array(i, array);
			return (NULL);
		}
		while (s[j] && s[j] != c)
			j++;
		i++;
	}
	array[i] = NULL;
	return (array);
}
