/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:01:54 by krocha-h          #+#    #+#             */
/*   Updated: 2023/12/19 12:13:17 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putchar(char c)
{
	int	n;

	n = 0;
	while (n == 0)
		n = write(1, &c, 1);
	return (n);
}

int	ft_putstr(char *s)
{
	int	n;

	n = 0;
	while (s[n])
	{
		ft_putchar(s[n]);
		n++;
	}
	return (n);
}
