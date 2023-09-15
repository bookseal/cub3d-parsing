#include "main.h"

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	int			**textures;
	int			floor_rgb[3];
	int			ceiling_rgb[3];
	char		*e_texture;
	char		*w_texture;
	char		*n_texture;
	char		*s_texture;
	int			**world_map;
} t_vars;

typedef struct s_parse
{
	int done_floor_rgb;
	int	done_ceiling_rgb;
	int	done_e_texture;
	int	done_w_texture;
	int	done_n_texture;
	int	done_s_texture;
	int	done_world_map;
} t_parse;

void	rgb_to_var(int *rgb, char is_f_c, t_vars *var)
{
	int i;
	int	*rgb_arr;

	if (is_f_c = 'F')
		rgb_arr = var->floor_rgb;
	else
		rgb_arr = var->ceiling_rgb;
	i = 0;
	while (i < 3)
	{
		rgb_arr[i] = rgb[i];
		i++;
	}
}

int *line_to_rgb(char *line, t_parse *p, t_vars *var)
{
	int *rgb;

	
	return (rgb);
}

int line_to_color(char *line, t_parse *p, t_vars *var)
{
	int i = 2;
	int comma_count = 0;
	int	*rgb;

	if (strncmp(line, "F ", 2) == 0)
	{
		if (p->done_floor_rgb)
			return (1);
		rgb = line_to_rgb(line + 2, p, var);
		if (!rgb)
			return (1);
		rgb_to_var(rgb, 'F', var);
		p->done_floor_rgb = 1;
	}
	else if (strncmp(line, "C ", 2) == 0)
	{
		if (p->done_ceiling_rgb)
			return (1);
		rgb = line_to_rgb(line + 2, p, var);
		if (!rgb)
			return (1);
		rgb_to_var(rgb, 'C', var);
		p->done_ceiling_rgb = 1;
	}
	return (0);
}

int line_to_elements(char *line, t_parse *p, t_vars *var)
{
	// TODO: texture part
	// if (line_to_texture(line, p))
	// 	return (1);
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
	p = malloc(sizeof(t_parse) * 1);
	var = malloc(sizeof(t_vars) * 1);
	line = get_next_line(cub_fd);
	printf("line = %s\n", line);
	if (!line_to_elements(line, p, var))
		return (1);
	while (line)
	{
		line = get_next_line(cub_fd);
		printf("line = %s\n", line);
		if (!line_to_elements(line, p, var))
			return (1);
	}
	return (0);
}