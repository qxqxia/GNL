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

char	*line1(const char *str)
{
	size_t		i;
	char		*s;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	s = (char *)malloc(sizeof(char) * i + 1);
	if (!s)
		return (NULL);
	while (str[i])
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*rest_lines(const char *lines)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	if (!lines)
		return (0);
	while (lines[i])
		i++;
	str = (char *)malloc(sizeof(char) * ft_strlen(lines) - i + 1);
	if (!str)
		return (NULL);
	while (lines[i])
	{
		str[i] = line[i]
	}
}


char	*get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	int	rd_n;
	char	*line;
	static char	*save;

	rd_n = 1;
	if (fd < 0 )


}
