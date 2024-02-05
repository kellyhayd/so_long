/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:07:09 by krocha-h          #+#    #+#             */
/*   Updated: 2023/12/19 12:13:56 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	print_dec_int(int num)
{
	long int	lnb;
	int			n;

	lnb = (long int)num;
	n = 0;
	if (lnb < 0)
	{
		n += ft_putchar('-');
		lnb *= -1;
	}
	if (lnb < 10)
		n += ft_putchar(lnb + '0');
	else if (lnb >= 10)
	{
		n += print_dec_int(lnb / 10);
		n += print_dec_int(lnb % 10);
	}
	return (n);
}

int	print_undec(unsigned int num)
{
	int				n;
	unsigned long	lnum;

	lnum = num;
	n = 0;
	if (lnum < 10)
		n += ft_putchar(lnum + '0');
	else if (lnum >= 10)
	{
		n += print_undec(lnum / 10);
		n += print_undec(lnum % 10);
	}
	return (n);
}
