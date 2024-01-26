/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:29:56 by krocha-h          #+#    #+#             */
/*   Updated: 2023/10/13 13:04:49 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/* Iterates the list ’lst’ and applies the function ’f’ on the content of each node.
Creates a new list resulting of the successive applications of the function ’f’.
The ’del’ function is used to delete the content of a node if needed */
t_list  *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list  *newlst;
    t_list  *current;
    void    *tmp;

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
