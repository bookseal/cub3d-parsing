/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_wall.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gichlee <gichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 19:56:20 by gichlee           #+#    #+#             */
/*   Updated: 2023/09/16 20:45:15 by gichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	get_width_of_map(t_parse *p)
{
	int len;
	t_parse_map *parse_map;

	len = 0;
	parse_map = p->map_lst;
	while (parse_map)
	{
		if (len < ft_len(parse_map->line))
			len = ft_len(parse_map->line);
		parse_map = parse_map->next;
	}
	return (len);
}

char **malloc_arrs(t_parse *p)
{
	int	width;
	int	height;
	int	n;
	int i;

	width = get_width_of_map(p);
	height = ft_lstsize(p->map_lst);
	n = width;
	if (width < height)
		n = height;
	p->map_arrs = ft_calloc(n + 1, sizeof(char *));
	i = 0;
	while (i < n)
	{
		(p->map_arrs)[i] = ft_calloc(n + 1, sizeof(char));
		i++;
	}
	p->map_size = n;
	return (p->map_arrs);
}

void	append_char_to_map_arrs(t_parse *p)
{
	t_parse_map *temp_map;
	char *line_arr;
	int	line_no;
	int	col_no;
	char	*slot;

	temp_map = p->map_lst;
	line_no = 0;
	while (line_no < p->map_size)
	{
		col_no = 0;
		while (col_no < p->map_size)
		{
			slot = &((p->map_arrs)[line_no][col_no]);
			if (!temp_map)
				*slot = ' ';
			else if (col_no < ft_len(temp_map->line))
				*slot = (temp_map->line)[col_no];
			else
				*slot = ' ';
			col_no++;
		}
		if (temp_map)
			temp_map = temp_map->next;
		line_no++;
	}
}

char **map_lst_to_map_arrs(t_parse *p)
{
	p->map_arrs = malloc_arrs(p);
	append_char_to_map_arrs(p);
	return (p->map_arrs);
}

int is_surrounded_with_wall(t_parse *p)
{
	p->map_arrs = map_lst_to_map_arrs(p);
	// TODO: check from the up
	// TODO: check from the bottom
	// TODO: check from the left
	// TODO: check from the right
	return (1);
}