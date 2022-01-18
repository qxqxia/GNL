/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qxia <qxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 15:53:16 by qxia              #+#    #+#             */
/*   Updated: 2022/01/18 16:57:46 by qxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*line_lue(char *str)
{
	char	*res;
	int		i;

	i = 0;
	if (!str[0])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	res = (char *)malloc(sizeof(char) * (i + 2));
	if (!res)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		res[i] = str[i];
		i++;
	}
	if (str[i] && str[i] == '\n')
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*new_buf(char *save)
{
	char	*s;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!save)
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!s)
		return (NULL);
	i++;
	while (save[i])
		s[j++] = save[i++];
	free(save);
	s[j] = '\0';
	return (s);
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
	char			buf[BUFFER_SIZE + 1];
	int				read_n;
	char			*line;
	static char		*save;

	read_n = 1;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	while (read_n != 0 && !ft_newline(save))
	{
		read_n = read(fd, buf, BUFFER_SIZE);
		if (read_n < 0)
			return (NULL);
		buf[read_n] = '\0';
		save = ft_strjoin(save, buf);
	}
	line = line_lue(save);
	save = new_buf(save);
	return (line);
}
