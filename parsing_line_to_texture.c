/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_line_to_texture.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gichlee <gichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:10:48 by gichlee           #+#    #+#             */
/*   Updated: 2023/09/15 18:19:58 by gichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char *line_to_path(char *line, t_parse *p)
{
	if (access(line, F_OK) != -1)
		return line;  // 파일이 존재하면 경로 반환
	return (0);
}

int line_to_texture(char *line, t_parse *p, t_vars *var)
{
	char	*path;

	if (strncmp(line, "NO ", 2) == 0)
	{
		if (p->done_n_texture)
			return (1);
		path = line_to_path(line + 2, p);
		if (!path)
			return (1);
		var->n_texture = path;
		p->done_n_texture = 1;
	}
	return (0);
}