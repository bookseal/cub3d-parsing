#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
# include <stdlib.h>


typedef struct s_vars
{
	void		*mlx;
	void		*win;
	int			**textures;
	int			*floor_rgb;
	int			*ceiling_rgb;
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

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
char	*ft_strtrim(char *s1, char *set);
int line_to_texture(char *line, t_parse *p, t_vars *var);
int line_to_color(char *line, t_parse *p, t_vars *var);
int	ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
char	*get_next_line(int fd);
char	*read_all(int fd, char *res);
char	*ft_cutbuf(char *buf);
char	*ft_popline(char *buf);
int		ft_len(char *s);
char	*gnl_strjoin_free(char *s1, char *s2);
void	ft_bzero(void *s, int n);
void	*ft_calloc(int count, int size);
int		ft_strchr_i(char *s, int c);