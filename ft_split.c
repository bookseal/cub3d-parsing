/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gichlee <gichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:11:12 by gichlee           #+#    #+#             */
/*   Updated: 2023/09/15 16:51:48 by gichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	free_all(char **strs, size_t *idx_strs)
{
	size_t	idx;

	idx = 0;
	while (idx < *idx_strs)
	{
		free(strs[idx]);
		idx++;
	}
	free(strs[idx]);
	free(strs);
}

static int	assign_str(char **strs, size_t *idx_strs, char *s, size_t *len)
{
	size_t	idx;

	if (*len != 0)
	{	
		strs[*idx_strs] = (char *)malloc(sizeof(char) * (*len + 1));
		if (strs[*idx_strs] == 0)
		{
			free_all(strs, idx_strs);
			return (0);
		}
		idx = 0;
		while (idx < *len)
		{
			strs[*idx_strs][idx] = *(s - *len + idx);
			idx++;
		}
		strs[*idx_strs][idx] = '\0';
		(*idx_strs)++;
	}
	*len = 0;
	return (1);
}

static size_t	get_size_of_strs(char *s, char c)
{
	size_t	idx;
	size_t	size_of_strs;
	size_t	len_new_str;

	size_of_strs = 1;
	len_new_str = 0;
	idx = 0;
	while (s[idx] != '\0')
	{
		if (s[idx] == c && len_new_str)
		{
			size_of_strs++;
			len_new_str = 0;
		}
		if (s[idx] != c)
			len_new_str++;
		idx++;
	}
	if (len_new_str)
		size_of_strs++;
	return (size_of_strs);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	idx_strs;
	size_t	len_new_str;
	size_t	size_of_strs;

	size_of_strs = get_size_of_strs((char *)s, c);
	strs = (char **)malloc(sizeof(char *) * (size_of_strs));
	if (strs == 0)
		return (0);
	len_new_str = 0;
	idx_strs = 0;
	while (*s != '\0')
	{		
		if (*s == c && !assign_str(strs, &idx_strs, (char *)s, &len_new_str))
			return (0);
		if (*s != c)
			len_new_str++;
		s++;
	}
	if (!assign_str(strs, &idx_strs, (char *)s, &len_new_str))
		return (0);
	strs[idx_strs] = 0;
	return (strs);
}