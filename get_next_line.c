#include "get_next_line.h"
#include <stdio.h>
static int	ft_stock(char **save, int fd)
{
	int		ret;
	char		buff[BUFF_SIZE + 1];
	char		*stop;

	stop = NULL;
	if (*save == NULL)
		*save = ft_strdup("");
	while (stop == NULL && (ret = read(fd, buff, BUFF_SIZE)) != 0)
	{
		buff[BUFF_SIZE] = '\0';
		if (ret == -1)
			return (-1);
		*save = ft_strjoin(*save, buff);
		stop = ft_strchr(buff, '\n');
	}
	return (0);
}

static int	ft_get_line(char **line, char **save)
{
	char*tmp;

	if ((tmp = ft_strchr(*save, '\n')))
	{
		*tmp = '\0';
		*line = ft_strdup(*save);
		free(*save);
		*save = ft_strdup(tmp + 1);
		tmp = NULL;
		return (1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char	*save;

	if ((ft_stock(&save, fd)) == -1)
		return (-1);
	if (ft_get_line(line, &save) == 1)
		return (1);
	return (0);
}

int		main(int ac, char **av)
{
	int		fd;
	char		*line;

	fd = open(av[1], O_RDONLY);
	get_next_line(fd, &line);
	printf("%s\n", line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	return (0);
}
