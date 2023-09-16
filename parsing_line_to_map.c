/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_line_to_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gichlee <gichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 21:44:45 by gichlee           #+#    #+#             */
/*   Updated: 2023/09/16 17:38:22 by gichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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

int line_to_map(char *line, t_parse *p, t_vars *var)
{
	t_parse_map *parse_map;
	if (p->done_world_map)
		return (0);
	if (is_first_row_of_map(line))
	{
		parse_map = ft_lstnew(line);
		// TODO: loop for append the last of the map
		while (line)
		{
			line = get_next_line(p->cub_fd);
			ft_lstadd_back(&parse_map, ft_lstnew(line));
		}
		// TODO: composed of only 6 possible characters
		
		// TODO: composed of only 6 possible characters	
		
		// TODO: check NSEW
		// TODO: check wall surrounded
		// TODO: check first and last row surrounded by wall
	}
	return (0);
}