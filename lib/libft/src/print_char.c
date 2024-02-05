/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:06:32 by krocha-h          #+#    #+#             */
/*   Updated: 2023/12/19 12:15:10 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	print_char(char c)
{
	int		n;

	n = 1;
	ft_putchar(c);
	return (n);
}

int	print_str(char *str)
{
	int		n;

	n = 0;
	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (str[n])
		n++;
	ft_putstr(str);
	return (n);
}
