/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gichlee <gichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 21:40:21 by gichlee           #+#    #+#             */
/*   Updated: 2023/09/15 21:41:34 by gichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	idx;

	if (dstsize != 0)
	{
		idx = 0;
		while (src[idx] != '\0' && idx + 1 < dstsize)
		{
			dst[idx] = src[idx];
			idx++;
		}
		dst[idx] = '\0';
	}
	return (ft_len(src));
}