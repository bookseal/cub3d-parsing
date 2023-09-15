/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_valid_cub.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gichlee <gichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 21:53:28 by gichlee           #+#    #+#             */
/*   Updated: 2023/09/15 21:53:36 by gichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	is_valid_cub(char *cub_str)
{	
	int len = ft_len(cub_str);

	// 문자열 길이가 4보다 작으면 ".cub"로 끝날 수 없다
	if (len < 4)
	{
		return (0);
	}

	// 마지막 4글자가 ".cub"인지 확인
	if (strncmp(&cub_str[len - 4], ".cub", 4) == 0)
	{
		// cub_str의 경로에 실제로 파일이 있는지 체크
		if (access(cub_str, F_OK) != -1)
		{
			return (1);
		}
	}

	// TODO: cub_str의 경로에 실제로 파일이 있는지 체
	return (0);
}
