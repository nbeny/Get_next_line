/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:34:56 by nbeny             #+#    #+#             */
/*   Updated: 2016/11/16 16:02:05 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*strsub;
	size_t	i;

	if (s)
	{
		i = 0;
		if (start > ft_strlen(s))
			return (NULL);
		strsub = (char *)malloc(sizeof(char) * (len + 1));
		if (strsub == NULL)
			return (NULL);
		while (i < len && s[start])
		{
			strsub[i] = s[start];
			start++;
			i++;
		}
		strsub[i] = '\0';
		return (strsub);
	}
	else
		return (NULL);
}
