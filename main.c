#include <stdio.h>
#include <fcntl.h>

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

	printf("hello");
	cub_fd = open("./test.cub", O_RDONLY);
	

	return (0);
}