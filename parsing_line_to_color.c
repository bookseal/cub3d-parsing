/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_line_to_color.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gichlee <gichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:08:45 by gichlee           #+#    #+#             */
/*   Updated: 2023/09/17 16:29:38 by gichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	free_strs(char **strs)
{
	int i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

void	rgb_to_var(int *rgb, char is_f_c, t_vars *var)
{
	if (is_f_c == 'F')
	{
		(var->floor_rgb)[0] = rgb[0];
		(var->floor_rgb)[1] = rgb[1];
		(var->floor_rgb)[2] = rgb[2];
	}
	else if (is_f_c == 'C')
	{
		(var->ceiling_rgb)[0] = rgb[0];
		(var->ceiling_rgb)[1] = rgb[1];
		(var->ceiling_rgb)[2] = rgb[2];
	}
	else
		return ;
}

int *free_all_and_return_null(char **strs, int *rgb)
{
	free_strs(strs);
	free(rgb);
	return (NULL);
}

int *line_to_rgb(char *line, t_parse *p)
{
	char	**strs;
	int 	*rgb;
	int		i;
	int		error;
	
	strs = ft_split(ft_strtrim(line, " "), ',');
	rgb = malloc(3 * sizeof(int));
	error = 0;
	i = 0;
	while (strs[i])
	{
		if (i > 2)
			return (free_all_and_return_null(strs, rgb));
		rgb[i] = ft_atoi(strs[i], &error);
		if (error || rgb[i] < 0 || 255 < rgb[i])
			return (free_all_and_return_null(strs, rgb));
		i++;
	}
	free_strs(strs);
	return (rgb);
}

int line_to_color(char *line, t_parse *p, t_vars *var)
{
	int	*rgb;

	if (strncmp(line, "F ", 2) == 0)
	{
		if (p->done_floor_rgb)
			return (1);
		rgb = line_to_rgb(line + 2, p);
		if (!rgb)
			return (1);
		rgb_to_var(rgb, 'F', var);
		p->done_floor_rgb = 1;
	}
	else if (strncmp(line, "C ", 2) == 0)
	{
		if (p->done_ceiling_rgb)
			return (1);
		rgb = line_to_rgb(line + 2, p);
		if (!rgb)
			return (1);
		rgb_to_var(rgb, 'C', var);
		p->done_ceiling_rgb = 1;
	}
	return (0);
}