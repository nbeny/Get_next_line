/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 04:10:49 by nbeny             #+#    #+#             */
/*   Updated: 2017/01/19 04:10:59 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_stock_buffer(int fd, char **save)
{
	int		ret;
	char	buff[BUFF_SIZE + 1];

	if (*save != NULL && ft_strchr(*save, '\n'))
		return (1);
	ft_bzero(buff, sizeof(buff));
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		if (*save == NULL)
		{
			*save = ft_strnew(1);
			*save = "";
		}
		*save = ft_strjoin(*save, buff);
		if (*save == NULL)
			return (-1);
		if (ft_strchr(*save, '\n') != NULL)
			break ;
		ft_bzero(buff, ft_strlen(buff));
	}
	return (ret <= 0 ? ret : 1);
}

static void	ft_make_line(char **line, char **save, int *ret)
{
	char	*ptr;

	if (*save != NULL && ft_strlen(*save) > 0)
	{
		*ret = 1;
		ptr = ft_strchr(*save, '\n');
		if (ptr == NULL)
		{
			*line = *save;
			*save = NULL;
		}
		else
		{
			*line = *save;
			*ptr = '\0';
			*save = ft_strdup(ptr + 1);
		}
	}
	return ;
}

int			get_next_line(const int fd, char **line)
{
	int			ret;
	static char	*save = NULL;

	if (line == NULL)
		return (-1);
	*line = NULL;
	ret = ft_stock_buffer(fd, &save);
	if (ret < 0)
		return (-1);
	ft_make_line(line, &save, &ret);
	return (ret);
}
