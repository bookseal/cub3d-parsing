/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_line_to_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gichlee <gichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 21:44:45 by gichlee           #+#    #+#             */
/*   Updated: 2023/09/16 19:54:35 by gichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int is_valid_with_6_characters(t_parse_map *parse_map)
{
	t_parse_map *map_line;
	const char six_chars[8] = {' ', '0', '1', 'N', 'S', 'E', 'W' , 0};
	int	i;
	int is_other;
	
	map_line = parse_map;
	while (map_line)
	{
		i = 0;
		while ((map_line->line)[i])
		{
			is_other = 1;
			if (ft_strchr(six_chars, (map_line->line)[i]))
				is_other = 0;
			if (is_other)
				return (0);
			i++;
		}
		map_line = map_line->next;
	}
	return (1);
}

int is_first_row_of_map(char *line)
{
	char *trimmed_line;
	
	trimmed_line = ft_strtrim(line, " ");
	if (*trimmed_line == '1')
	{
		free(trimmed_line);
		return (1);
	}
	free(trimmed_line);
	return (0);
}

int is_only_one_NSEW(t_parse *p, t_parse_map *parse_map)
{
	const char nsew[5] = {'N', 'S', 'E', 'W'};
	t_parse_map *map_line;
	int	i;
	
	p->done_map_start_direction = 0;
	map_line = parse_map;
	while (map_line)
	{
		i = 0;
		while ((map_line->line)[i])
		{
			if (ft_strchr(nsew, (map_line->line)[i]))
			{
				if (p->done_map_start_direction)
					return (0);
				p->done_map_start_direction = *(ft_strchr(nsew, (map_line->line)[i]));
			}
			i++;
		}
		map_line = map_line->next;
	}
	return (0);
}

int line_to_map(char *line, t_parse *p, t_vars *var)
{
	t_parse_map *parse_map;
	
	if (p->done_world_map)
		return (0);
	if (is_first_row_of_map(line))
	{
		parse_map = ft_lstnew(line);
		while (line)
		{
			line = get_next_line(p->cub_fd);
			if (line && *line == '\n')
				 break ;
			ft_lstadd_back(&parse_map, ft_lstnew(line));
		}
		if (!is_valid_with_6_characters(parse_map))
			return (1);
		if (!is_only_one_NSEW(p, parse_map))
			return (1);
		// TODO: check wall surrounded 위, 오른, 아래, 왼쪽이 전부 1인가
		// TODO: space
		p->done_world_map = 1;
	}
	return (0);
}

/*

//가장 위, 아래, 오른쪽, 왼쪽은 1아니면 빈칸이어야한다

line_num = 1;
col_num = 1;
while (line_num < Height - 1)
{
	col_num = 1;
	while (col_num < Width - 1)
	{
		if ( == 빈칸)
		{
			//자기의 주변 (동서남북))이 빈칸 혹은 1이어야하만 한다
		}
	}
}


*/