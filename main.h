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

typedef struct s_parse_map
{
	char 				*line;
	struct s_parse_map	*next;
} t_parse_map;

typedef struct s_parse
{
	int		cub_fd;
	int 	done_floor_rgb;
	int		done_ceiling_rgb;
	int		done_e_texture;
	int		done_w_texture;
	int		done_n_texture;
	int		done_s_texture;
	int		done_world_map;
	char	done_map_start_direction;
	t_parse_map *map_lst;
	char	**map_arrs;
} t_parse;

int is_surrounded_with_wall(t_parse *p);
char	*ft_strchr(const char *s, int c);
t_parse_map	*ft_lstnew(char *line);
void	ft_lstadd_front(t_parse_map **lst, t_parse_map *new);
int	ft_lstsize(t_parse_map *lst);
t_parse_map	*ft_lstlast(t_parse_map *lst);
void	ft_lstadd_back(t_parse_map **lst, t_parse_map *new);
void	ft_lstdelone(t_parse_map *lst, void (*del)(void *));
void	ft_lstclear(t_parse_map **lst, void (*del)(void *));
int line_to_map(char *line, t_parse *p, t_vars *var);
void	ft_lstiter(t_parse_map *lst, void (*f)(void *));
t_parse_map	*ft_lstmap(t_parse_map *lst, void *(*f)(void *), void (*del)(void *));

t_vars *parsing(char *cub_str);
int	is_valid_cub(char *cub_str);
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