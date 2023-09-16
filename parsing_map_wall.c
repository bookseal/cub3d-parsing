/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_wall.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gichlee <gichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 19:56:20 by gichlee           #+#    #+#             */
/*   Updated: 2023/09/16 20:18:17 by gichlee          ###   ########.fr       */
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
	width = get_width_of_map(p);
	// TODO: height

	return (p->map_arrs);
}

char **map_lst_to_map_arrs(t_parse *p)
{
	p->map_arrs = malloc_arrs(p);
	// TODO: append char

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