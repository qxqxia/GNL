/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qxia <qxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 15:53:16 by qxia              #+#    #+#             */
/*   Updated: 2022/01/17 12:14:36 by qxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*line1(char *str)
{
	char	*line;
	int		i;

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

static char	*new_buf(char *save)
{
	char	*s;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!save)
		return (0);
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (0);
	}
	s = (char *)malloc(sizeof(char) * ft_strlen(save) - i + 1);
	if (!s)
		return (NULL);
	i++;
	while (save[i])
		s[j++] = save[i++];
	free(save);
	s[j] = '\0';
	return (s);
}

static int	ft_newline(char	*save)
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
	char		buf[BUFFER_SIZE + 1];
	int			read_n;
	char		*line;
	char		*save;

	read_n = 1;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	while (read_n != 0 && !ft_newline(save))
	{
		read_n = read(fd, buf, BUFFER_SIZE);
		if (read_n == -1)
			return (NULL);
		buf[read_n] = '\0';
		save = ft_strjoin(save, buf);
	}
	line = line1(save);
	save = new_buf(save);
	if (read_n == 0)
		return (0);
	return (line);
}
