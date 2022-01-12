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

char	*first_line(char *str)
{
	char	*line;
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * i + 1);
	if (!line)
		return (NULL);
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

int	ft_newline(char	*save)
{
	int	i;
	
	i = 0;
	if (!save)
		return (0);
	while (save[i])
	{
		if (save[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char	buf[BUFFER_SIZE + 1];
	int	read_n;
	char	*line;
	char	*save;

	read_n = 1;
	if (fd < 0)
		return (NULL);
	while ((read_n = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_n] = '\0';
		save = ft_strjoin(save, buf);
	}
	line = first_line(save);
	return (line);
}
