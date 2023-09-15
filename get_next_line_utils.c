/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gichlee <gichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:34:17 by gichlee           #+#    #+#             */
/*   Updated: 2023/09/15 16:52:12 by gichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_len(char *s)
{
	int	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

int	ft_strchr_i(char *s, int c)
{
	char	*ptr_s;
	int		idx;	

	ptr_s = (char *)s;
	idx = 0;
	while (1)
	{
		if (ptr_s[idx] == (unsigned char)c)
			return (idx);
		else if (ptr_s[idx] == '\0')
			return (-1);
		else
			idx++;
	}
	return (-1);
}

char	*gnl_strjoin_free(char *s1, char *s2)
{
	int		len_total;
	char	*res;
	int		i;
	int		j;

	len_total = ft_len(s1) + ft_len(s2);
	res = calloc(sizeof(char), (len_total + 1));
	if (!res || !s1 || !s2)
		return (NULL);
	i = 0;
	while (s1[i] != 0)
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		res[i + j] = s2[j];
		j++;
	}
	res[len_total] = '\0';
	free(s1);
	return (res);
}

void	ft_bzero(void *s, int n)
{
	int	idx;

	if (n == 0)
		return ;
	else
	{
		idx = 0;
		while (idx < n)
		{
			((char *)s)[idx] = 0;
			idx++;
		}
	}
}

void	*ft_calloc(int count, int size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr == 0)
		return (0);
	ft_bzero(ptr, count * size);
	return (ptr);
}
