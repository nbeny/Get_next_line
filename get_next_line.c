#include "get_next_line.h"
#include <stdio.h>
static int	ft_stock(char **save, int fd)
{
	int		ret;
	char		*buff;
	char		*stop;

	stop = NULL;
	buff = ft_strnew(BUFF_SIZE);
	if (*save == NULL)
		*save = ft_strdup("");
	while (stop == NULL && (ret = read(fd, buff, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		*save = ft_strjoin(*save, buff);
		stop = ft_strchr(buff, '\n');
	}
	free(buff);
	buff = NULL;
	return (0);
}

static int	ft_get_line(char **line, char **save)
{
	char	*tmp;

	//printf("savestart = %s\n", *save);
	if ((tmp = ft_strchr(*save, '\n')))
	{
		*tmp = '\0';
		*line = ft_strdup(*save);
		//printf("save1 = %s\n", *save);fflush(stdout);
		free(*save);
		*save = ft_strdup(tmp + 1);
		//printf("save2 = %s\n", *save);
		tmp = NULL;
		return (1);
	}
	else
	{
		*line = ft_strdup(*save);
		return (0);
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char	*save = NULL;

	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	if (ft_stock(&save, fd) == -1)
		return (-1);
	if (ft_get_line(line, &save) == 0)
		return (0);
	return (1);
}
