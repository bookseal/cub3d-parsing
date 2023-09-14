#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
			len++;
	return (len);
}

char *ft_next(char *buffer)
{
	int	i;
	int	j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

char	*ft_line(char *buffer)
{
	char	*buffer2;
	char *end_point;
	char *line;

	buffer2 = strdup(buffer);
	end_point = strchr(buffer2, '\n');
	if (end_point)
		*end_point = '\0';
	return (strdup(buffer2));
}

char	*read_file(int fd, char *res)
{
	char *buffer;
	int	byte_read;

	if (!res)
		res = calloc(500, sizeof(char));
	buffer = calloc(1 + 1, sizeof(char));
	byte_read = 1;
	while (byte_read > 0)
		{
			byte_read = read(fd, buffer, 1);
			if (byte_read == -1)
			{
				free(buffer);
				return (NULL);
			}
			buffer[byte_read] = 0;
			strcat(res, buffer);
			if (strchr(buffer, '\n'))
				break ;
		}
	free(buffer);
	return (res);
}

char	*get_next_line(int fd)
{
	static char *buffer;
	char		*line;

	if (fd<0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	buffer = ft_next(buffer);
	return (line);
}
