#include <stdio.h>
#include <fcntl.h>
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

int main(void)
{
	int cub_fd;
	char	*line;

	// TODO: check file extension is cub
	char *cub_str = "./test.cub";
	cub_fd = open(cub_str, O_RDONLY);
	line = get_next_line(cub_fd);
	printf("line = %s\n", line);

	return (0);
}