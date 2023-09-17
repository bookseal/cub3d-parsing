/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_wall.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gichlee <gichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 19:56:20 by gichlee           #+#    #+#             */
/*   Updated: 2023/09/17 16:08:11 by gichlee          ###   ########.fr       */
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

int	is_all_wall_from_west(t_parse *p)
{
	int i;
	int	j;
	
	i = 0;
	while (i < p->map_size)
	{
		j = 0;
		while (j < p->map_size)
		{
			if ((p->map_arrs)[i][j] == ' ')
				j++;
			else if ((p->map_arrs)[i][j] == '1')
				break ;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	is_all_wall_from_east(t_parse *p)
{
	int i;
	int	j;
	
	i = 0;
	while (i < p->map_size)
	{
		j = p->map_size - 1;
		while (j >= 0)
		{
			if ((p->map_arrs)[i][j] == ' ')
				j--;
			else if ((p->map_arrs)[i][j] == '1')
				break ;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	is_all_wall_from_north(t_parse *p)
{
	int i;
	int	j;
	
	i = 0;
	while (i < p->map_size)
	{
		j = 0;
		while (j < p->map_size)
		{
			if ((p->map_arrs)[j][i] == ' ')
				j++;
			else if ((p->map_arrs)[j][i] == '1')
				break ;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	is_all_wall_from_south(t_parse *p)
{
	int i;
	int	j;
	
	i = 0;
	while (i < p->map_size)
	{
		j = p->map_size - 1;
		while (j >= 0)
		{
			if ((p->map_arrs)[j][i] == ' ')
				j--;
			else if ((p->map_arrs)[j][i] == '1')
				break ;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int is_surrounded_with_wall(t_parse *p)
{
	p->map_arrs = map_lst_to_map_arrs(p);
	if (!is_all_wall_from_west(p))
		return (0);
	if (!is_all_wall_from_east(p))
		return (0);
	if (!is_all_wall_from_north(p))
		return (0);
	if (!is_all_wall_from_south(p))
		return (0);
	return (1);
}

int is_valid_space(t_parse *p, int i, int j)
{
	char c;

	c = (p->map_arrs)[i][j + 1];
	if (!(c == ' ' || c == '1'))
		return (0);
	c = (p->map_arrs)[i][j - 1];
	if (!(c == ' ' || c == '1'))
		return (0);
	c = (p->map_arrs)[i + 1][j];
	if (!(c == ' ' || c == '1'))
		return (0);
	c = (p->map_arrs)[i - 1][j];
	if (!(c == ' ' || c == '1'))
		return (0);
	
	return (1);
}

int is_space_surrounded_with_wall(t_parse *p)
{
	int 	i;
	int		j;
	char	c;
	
	i = 1;
	while (i < p->map_size - 1)
	{
		j = 1;
		while (j < p->map_size - 1)
		{
			c = (p->map_arrs)[i][j];
			if (c == ' ')
			{
				if (!is_valid_space(p, i, j))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}