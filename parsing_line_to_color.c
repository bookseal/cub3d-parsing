/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_line_to_color.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gichlee <gichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:08:45 by gichlee           #+#    #+#             */
/*   Updated: 2023/09/15 21:50:43 by gichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	rgb_to_var(int *rgb, char is_f_c, t_vars *var)
{
	if (is_f_c == 'F')
		var->floor_rgb = rgb;
	else if (is_f_c == 'C')
		var->ceiling_rgb = rgb;
	else
		return ;
}

int *line_to_rgb(char *line, t_parse *p)
{
	char	**strs;
	int *rgb;
	int	i;
	strs = ft_split(ft_strtrim(line, " "), ',');

	rgb = malloc(3 * sizeof(int));
	i = 0;
	while (strs[i])
	{
		if (i > 2)
		{
			// TODO: invalid format
			exit(0);
		}
		rgb[i] = ft_atoi(strs[i]);
		i++;
	}
	// TODO: free strs
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