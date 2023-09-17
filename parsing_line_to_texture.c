/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_line_to_texture.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gichlee <gichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:10:48 by gichlee           #+#    #+#             */
/*   Updated: 2023/09/17 16:13:57 by gichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char *line_to_path(char *line, t_parse *p)
{
	char *path;

	path = ft_strtrim(line, " ");
	if (access(path, F_OK) != -1)
		return path;  // 파일이 존재하면 경로 반환
	return (0);
}

int line_to_texture(char *line, t_parse *p, t_vars *var)
{
	char	*path;

	if (strncmp(line, "NO ", 2) == 0)
	{
		if (p->done_n_texture)
			return (1);
		path = line_to_path(line + 3, p);
		if (!path)
			return (1);
		var->n_texture = path;
		p->done_n_texture = 1;
	} else if (strncmp(line, "SO ", 2) == 0)
	{
		if (p->done_s_texture)
			return (1);
		path = line_to_path(line + 3, p);
		if (!path)
			return (1);
		var->s_texture = path;
		p->done_s_texture = 1;
	} else if (strncmp(line, "WE ", 2) == 0)
	{
		if (p->done_w_texture)
			return (1);
		path = line_to_path(line + 3, p);
		if (!path)
			return (1);
		var->w_texture = path;
		p->done_w_texture = 1;
	} else if (strncmp(line, "EA ", 2) == 0)
	{
		if (p->done_e_texture)
			return (1);
		path = line_to_path(line + 3, p);
		if (!path)
			return (1);
		var->e_texture = path;
		p->done_e_texture = 1;
	} 
	return (0);
}