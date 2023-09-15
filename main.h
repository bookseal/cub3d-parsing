#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

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