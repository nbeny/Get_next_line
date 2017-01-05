/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 08:10:41 by nbeny             #+#    #+#             */
/*   Updated: 2016/12/14 18:04:59 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		get_next_line(const int fd, char **line)
{
	int		k;
	int		j;
	int		i;
	int		end;
	char		buff[BUFF_SIZE];
	static char	*save = NULL;
	char		*tmp;
	char		*strjoin;

	end = 0;
	*line = (char *)malloc(sizeof(char) * 20);
	printf("1\n");fflush(stdout);
	while (read(fd, buff, BUFF_SIZE) != 0)
	{
		i = 0;
	printf("2\n");fflush(stdout);
		if (save)
		{
			i = 0;
			j = 0;
	printf("25\n");fflush(stdout);
			while (save[j] && save[j] != '\n')
				(*line)[i++] = save[j++];
			tmp = ft_strdup(save);
		}
	printf("3\n");fflush(stdout);
		j = 0;
		while (j < BUFF_SIZE && buff[j] && buff[j] != '\n')
		{
			(*line)[i] = buff[j];
			j++;
			i++;
		}
	printf("4\n");fflush(stdout);
		if (j < BUFF_SIZE)
		{
			k = 0;
			save = (char *)malloc(sizeof(char) * (BUFF_SIZE - j + 1));
			while (j < BUFF_SIZE)
				save[k++] = buff[j++];
			save[k] = '\0';
	printf("5\n");fflush(stdout);
			if (tmp)
			{
				strjoin = ft_strjoin(tmp, save);
	printf("6\n");fflush(stdout);
				save = ft_strncpy(save, strjoin, ft_strlen(strjoin));
			}
	printf("7\n");fflush(stdout);
		}
		if (ft_strchr(buff, '\n'))
			return(1);
	}
	return (-1);
}

int		main(int ac, char **av)
{
	int fd;
	char *line;

	fd = open(av[1], O_RDONLY);
	get_next_line(fd, &line);
	ft_putstr(line);
	ft_putchar('\n');
	get_next_line(fd, &line);
	ft_putstr(line);
	ft_putchar('\n');
	get_next_line(fd, &line);
	ft_putstr(line);
	ft_putchar('\n');
	return (0);
}
