/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:33:14 by krocha-h          #+#    #+#             */
/*   Updated: 2023/12/19 12:14:40 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	print_hex(unsigned long long lnum, char c)
{
	char	*base;
	int		n;

	if (c == 'x')
		base = "0123456789abcdef";
	else if (c == 'X')
		base = "0123456789ABCDEF";
	n = 0;
	if (lnum < 16)
		n += ft_putchar(base[lnum]);
	else if (lnum >= 16)
	{
		n += print_hex(lnum / 16, c);
		n += print_hex(lnum % 16, c);
	}
	return (n);
}

int	print_ptrhex(unsigned long long ptr)
{
	int	n;

	if (!ptr)
	{
		n = ft_putstr("(nil)");
		return (n);
	}
	n = ft_putstr("0x");
	n += print_hex(ptr, 'x');
	return (n);
}
