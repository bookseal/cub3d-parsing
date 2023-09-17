/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gichlee <gichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 21:54:15 by gichlee           #+#    #+#             */
/*   Updated: 2023/09/17 16:12:53 by gichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	is_texture_and_color_set(t_parse *p)
{
	if (!p->done_floor_rgb)
		return (0);
	if (!p->done_ceiling_rgb)
		return (0);
	if (!p->done_e_texture)
		return (0);	
	if (!p->done_w_texture)
		return (0);
	if (!p->done_n_texture)
		return (0);
	if (!p->done_s_texture)
		return (0);
	return (1);
}

int line_to_elements(char *line, t_parse *p, t_vars *var)
{
	if (line_to_texture(line, p, var))
		return (1);
	if (line_to_color(line, p, var))
		return (1);
	if (is_texture_and_color_set(p) && line_to_map(line, p, var))
		return (1);
	return (0);
}

int	is_every_element_done(t_parse *p)
{
	int result;

	result = 1;
	result *= p->done_floor_rgb;
	result *= p->done_ceiling_rgb;
	result *= p->done_e_texture;
	result *= p->done_w_texture;
	result *= p->done_n_texture;
	result *= p->done_s_texture;
	result *= p->done_world_map;
	result *= p->done_map_start_direction;
	return (result);
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
	p->cub_fd = cub_fd;
	var = ft_calloc(1, sizeof(t_vars));
	line = get_next_line(cub_fd);
	if (line_to_elements(line, p, var))
		return (0);
	while (line)
	{
		line = get_next_line(cub_fd);
		if (line && line_to_elements(line, p, var))
			return (0);
	}
	if (is_every_element_done(p))
	{
		free(p);
		return (var);
	}
	else
	{
		free(p);
		return (0);
	}
	return (var);
}