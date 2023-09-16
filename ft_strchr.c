/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gichlee <gichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 18:21:10 by gichlee           #+#    #+#             */
/*   Updated: 2023/09/16 18:21:38 by gichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr_s;
	size_t	idx;

	ptr_s = (char *)s;
	idx = 0;
	while (1)
	{
		if (ptr_s[idx] == (unsigned char)c)
			return (&ptr_s[idx]);
		else if (ptr_s[idx] == '\0')
			return (0);
		else
			idx++;
	}
	return (0);
}