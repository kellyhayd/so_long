/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:49:44 by krocha-h          #+#    #+#             */
/*   Updated: 2023/11/09 14:50:26 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/* Allocates and returns a new node. The member variable ’content’ is
initialized with the value of the parameter ’content’.
The variable ’next’ is initialized to NULL */
t_list	*ft_lstnew(void *content)
{
	t_list	*newlst;

	newlst = malloc(sizeof(t_list));
	if (!newlst)
		return (0);
	newlst->content = content;
	newlst->next = 0;
	return (newlst);
}
