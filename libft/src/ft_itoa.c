/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:22:23 by krocha-h          #+#    #+#             */
/*   Updated: 2023/11/09 12:21:45 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/* The itoa() function coverts the integer n into a character string */
static size_t	ft_len(int n)
{
	size_t	count;

	count = 0;
	if (n < 1)
		count = 1;
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	size_t		size;
	char		*nbr;
	long int	num;

	num = n;
	if (n < 0)
		num *= -1;
	size = ft_len(n);
	nbr = ft_calloc((size + 1), sizeof(char));
	if (!nbr)
		return (0);
	while (size--)
	{
		nbr[size] = (num % 10) + '0';
		num = num / 10;
	}
	if (n < 0)
		nbr[0] = '-';
	return (nbr);
}
