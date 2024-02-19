/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:00:16 by haydkelly         #+#    #+#             */
/*   Updated: 2024/02/19 10:18:00 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdlib.h>

void	clean_lst(t_list **lst, t_list *last_node)
{
	size_t	i;
	size_t	j;

	if (!last_node)
		return ;
	j = 0;
	while (last_node->str[j] && last_node->str[j] != '\n')
		j++;
	if (last_node->str[j] == '\n')
		j++;
	i = 0;
	while (last_node->str[j])
	{
		last_node->str[i] = last_node->str[j];
		i++;
		j++;
	}
	last_node->str[i] = '\0';
	lst_remake(lst);
}

void	create_str(t_list *lst, char *line)
{
	size_t	i;
	size_t	j;

	if (!lst)
		return ;
	i = 0;
	while (lst)
	{
		j = 0;
		while (lst->str[j])
		{
			if (lst->str[j] == '\n')
			{
				line[i] = '\n';
				line[i + 1] = '\0';
				return ;
			}
			line[i] = lst->str[j];
			j++;
			i++;
		}
		lst = lst->next;
	}
	line[i] = '\0';
}

char	*create_line(t_list *lst)
{
	char	*line;
	size_t	len;

	if (!lst)
		return (NULL);
	len = get_line_len(lst);
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	create_str(lst, line);
	return (line);
}

int	create_lst(int fd, t_list **lst, t_list **last_node)
{
	char	*buffer;
	int		nbytes;

	while (!has_nl(*last_node))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (0);
		nbytes = read(fd, buffer, BUFFER_SIZE);
		if (nbytes <= 0)
		{
			free(buffer);
			return (nbytes == 0);
		}
		buffer[nbytes] = '\0';
		if (!lstadd_node(lst, last_node, buffer))
		{
			free(buffer);
			return (0);
		}
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static t_list	*lst[1024];
	t_list			*last_node;
	char			*new_line;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	last_node = ft_lstlast(lst[fd]);
	if (!create_lst(fd, &lst[fd], &last_node))
	{
		clean_lst(&lst[fd], last_node);
		return (NULL);
	}
	new_line = create_line(lst[fd]);
	clean_lst(&lst[fd], last_node);
	return (new_line);
}
