/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:22:34 by krocha-h          #+#    #+#             */
/*   Updated: 2023/11/08 15:01:09 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/* Allocates and returns a copy of ’s1’ with the characters specified in ’set’
removed from the beginning and the end of the string */
static int	run_set(const char *set_search, const char src)
{
	int	i;

	i = 0;
	while (set_search[i] != '\0')
	{
		if (set_search[i] == src)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*new;
	int		start;
	int		end;
	int		i;

	start = 0;
	end = ft_strlen(s1);
	while (run_set(set, s1[start]) && s1[start])
		start++;
	while (run_set(set, s1[end - 1]) && end > start)
		end--;
	new = malloc ((end - start + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	while (start < end)
	{
		new[i] = s1[start];
		i++;
		start++;
	}
	new[i] = '\0';
	return (new);
}
