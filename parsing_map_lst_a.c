/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_lst_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gichlee <gichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 15:47:37 by gichlee           #+#    #+#             */
/*   Updated: 2023/09/16 17:35:18 by gichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_parse_map	*ft_lstnew(char *line)
{
	t_parse_map	*new_lst;

	new_lst = (t_parse_map *)malloc(sizeof(t_parse_map) * 1);
	if (new_lst == 0)
		return (0);
	new_lst->line = line;
	new_lst->next = 0;
	return (new_lst);
}

void	ft_lstadd_front(t_parse_map **lst, t_parse_map *new)
{
	t_parse_map	*temp;

	if (lst == 0 || new == 0)
		return ;
	temp = *lst;
	*lst = new;
	(*lst)->next = temp;
}

int	ft_lstsize(t_parse_map *lst)
{
	size_t	len;
	t_parse_map	*temp_lst;

	temp_lst = lst;
	len = 0;
	while (temp_lst != 0)
	{
		len++;
		temp_lst = temp_lst->next;
	}
	return (len);
}

t_parse_map	*ft_lstlast(t_parse_map *lst)
{
	t_parse_map	*temp_lst;

	temp_lst = lst;
	if (temp_lst)
	{
		while (temp_lst->next != 0)
			temp_lst = temp_lst->next;
	}
	return (temp_lst);
}

void	ft_lstadd_back(t_parse_map **lst, t_parse_map *new)
{
	t_parse_map	*head;
	t_parse_map	*temp_lst;

	head = *lst;
	if (head == 0)
		*lst = new;
	else
	{
		temp_lst = head;
		while (temp_lst->next != 0)
			temp_lst = temp_lst->next;
		temp_lst->next = new;
	}
}


void	ft_lstdelone(t_parse_map *lst, void (*del)(void *))
{
	if (lst == 0 || del == 0)
		return ;
	del(lst->line);
	free(lst);
}

void	ft_lstclear(t_parse_map **lst, void (*del)(void *))
{
	t_parse_map	*next_lst;

	if (*lst == 0 || del == 0)
		return ;
	while (*lst != 0)
	{
		next_lst = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = next_lst;
	}	
}

void	ft_lstiter(t_parse_map *lst, void (*f)(void *))
{
	t_parse_map	*temp_lst;

	if (lst == 0 || f == 0)
		return ;
	temp_lst = lst;
	while (temp_lst != 0)
	{
		f(temp_lst->line);
		temp_lst = temp_lst->next;
	}
}

t_parse_map	*ft_lstmap(t_parse_map *lst, void *(*f)(void *), void (*del)(void *))
{
	t_parse_map	*old_lst;
	t_parse_map	*new_lst;
	t_parse_map	*head;

	if (lst == 0 || f == 0 || del == 0)
		return (0);
	old_lst = lst;
	new_lst = ft_lstnew(f(old_lst->line));
	if (new_lst == 0)
		return (0);
	head = new_lst;
	old_lst = old_lst->next;
	while (old_lst != 0)
	{
		new_lst->next = ft_lstnew(f(old_lst->line));
		if (new_lst->next == 0)
		{
			ft_lstclear(&head, del);
			return (0);
		}
		new_lst = new_lst->next;
		old_lst = old_lst->next;
	}
	return (head);
}