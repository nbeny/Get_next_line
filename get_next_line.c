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
	int			m;
	int			l;
	int			k;
	int			j;
	int			i;
	int			endl;
	char		buff[BUFF_SIZE];
	static char	*save = NULL;
	char		*tmp;

	i = 0;
	*line = (char *)malloc(sizeof(char) * 20);
	while (read(fd, buff, BUFF_SIZE) != 0)
	{
		if (save)
		{
			i = 0;
			j = 0;
			while (save[j] && save[j] != '\n')
				(*line)[i++] = save[j++];
			if (save[j] != '\0')
			{
				l = 0;
				tmp = (char *)malloc(sizeof(char) * (ft_strlen(&save[j]) + 1));
				while (save[j])
					tmp[l++] = save[j++];
				tmp[l] = '\0';
				free(save);
				l = 0;
				m = 0;
				save = (char *)malloc(sizeof(char) * (l + 1));
				while (tmp[l])
					save[l++] = tmp[m++];
				save[l] = '\0';
				free(tmp);
			}
			l = 0;
			endl = 0;
			while (save[l])
			{
				if (save[l] == '\n')
					endl = 1;
				l++;
			}
			if (endl == 0)
			{
				free(save);
				save = NULL;
			}
		}
		if (!save)
		{
			j = 0;
			while (j < BUFF_SIZE && buff[j] != '\n' && save == NULL)
			{
				(*line)[i] = buff[j];
				j++;
				i++;
			}
			if (j < BUFF_SIZE)
			{
				k = 0;
				save = (char *)malloc(sizeof(char) * (BUFF_SIZE - j + 1));
				while (j < BUFF_SIZE)
					save[k++] = buff[j++];
				save[k] = '\0';
			}
		}
		if (buff[j] == '\n' && !save)
		{
			(*line)[i] = '\0';
			return (0);
		}
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
