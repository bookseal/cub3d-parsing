/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gichlee <gichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 21:54:15 by gichlee           #+#    #+#             */
/*   Updated: 2023/09/15 21:58:03 by gichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int line_to_elements(char *line, t_parse *p, t_vars *var)
{
	if (line_to_texture(line, p, var))
		return (1);
	if (line_to_color(line, p, var))
		return (1);
	if (line_to_map(line, p, var))
		return (1);
	return (0);
}

t_vars *parsing(char *cub_str)
{
	int cub_fd;
	char	*line;
	t_parse *p;
	t_vars	*var;

	if (is_valid_cub(cub_str))
		cub_fd = open(cub_str, O_RDONLY);
	else
		return (0);
	p = ft_calloc(1, sizeof(t_parse));
	var = ft_calloc(1, sizeof(t_vars));
	line = get_next_line(cub_fd);
	printf("line = %s", line);
	if (line_to_elements(line, p, var))
		return (0);
	while (line)
	{
		line = get_next_line(cub_fd);
		printf("line = %s", line);
		if (line && line_to_elements(line, p, var))
			return (0);
	}
	// TODO: check every element is filled
	free(p);
	return (var);
}