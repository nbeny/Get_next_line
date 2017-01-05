/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 08:10:41 by nbeny             #+#    #+#             */
/*   Updated: 2016/12/14 18:04:59 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static t_var	ft_init_tvar(t_var *var)
{
	i = 0;
	j = 0;
	k = 0;
	l = 0;
	m = 0;
	return (var);
}

static char	**ft_start()
{
	
}

static char   	**ft_save_gestion()
{

}

int		get_next_line(const int fd, char **line)
{
	t_var		*var;
	int		end;
	char		buff[BUFF_SIZE];
	static char	*save = NULL;
	char		*tmp;

	var = ft_init_tvar(var);
	while (read(fd, buff, BUFF_SIZE) != EOF)
	{
		buff[var->i]
	}
}
