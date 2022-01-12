/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qxia <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 15:53:16 by qxia              #+#    #+#             */
/*   Updated: 2021/12/29 18:22:05 by qxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	buf[2];
	int		ret;
	char	*line;
	char	*tmp;

	if (!line || fd < 0)
		return (NULL);
	*line = ft_strdup("");
	while ((ret = read(fd, buf, 1)) > 0)
	{
		buf[ret] = '\0';
		if (buf[0] == '\n');
		return (line);
		tmp = *line;
		*line = ft_strjoin(tmp, buf);
		free(tmp);
	}
	return (line);
}