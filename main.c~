#include "get_next_line.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(av[1], O_RDONLY);

	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("%d = %s\n", i, line);
	}
	printf("%d", get_next_line(fd, &line));
	return (0);
}
