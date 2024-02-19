/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:29:56 by krocha-h          #+#    #+#             */
/*   Updated: 2024/02/19 10:20:35 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*current;
	void	*tmp;

	if (!lst || !f || !del)
		return (0);
	newlst = 0;
	while (lst)
	{
		tmp = f(lst->content);
		current = ft_lstnew(tmp);
		if (!current)
		{
			del(tmp);
			ft_lstclear(&newlst, (*del));
			return (newlst);
		}
		ft_lstadd_back(&newlst, current);
		lst = lst->next;
	}
	return (newlst);
}
