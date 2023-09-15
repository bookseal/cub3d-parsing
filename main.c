#include "main.h"

int line_to_elements(char *line, t_parse *p, t_vars *var)
{
	if (line_to_texture(line, p, var))
		return (1);
	if (line_to_color(line, p, var))
		return (1);
	// TODO: map part
	// if (line_to_map(line, p))
	// 	return (1);
	return (0);
}

int	is_valid_cub(char *cub_str)
{	
	int len = strlen(cub_str);

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

int main(void)
{
	int cub_fd;
	char	*line;
	t_parse *p;
	t_vars	*var;

	char *cub_str = "./test.cub";
	if (is_valid_cub(cub_str))
		cub_fd = open(cub_str, O_RDONLY);
	else
		return (1);
	p = ft_calloc(1, sizeof(t_parse));
	var = ft_calloc(1, sizeof(t_vars));
	line = get_next_line(cub_fd);
	printf("line = %s", line);
	if (line_to_elements(line, p, var))
		return (1);
	while (line)
	{
		line = get_next_line(cub_fd);
		printf("line = %s", line);
		if (line && line_to_elements(line, p, var))
			return (1);
	}
	free(p);
	// TODO: check every element is filled
	return (0);
}