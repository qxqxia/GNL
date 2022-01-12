/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qxia <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 15:53:58 by qxia              #+#    #+#             */
/*   Updated: 2021/12/29 18:22:24 by qxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*s;
	size_t	i;

	i = 0;
	s = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!s)
	return (NULL);
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}	

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	len;
	size_t	i;
	size_t	j;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	len = i + j + 1;
	if (!s1 && !s2)
		return (NULL);
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && s2)
		return (ft_strdup(s2));
	s = malloc(sizeof(char) * (i + j + 1));
	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && i < len && s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	while (s2 && i < len && s2[j])
	s[i++] = s2[j++];
	s[i] = 0;
	return (s);
}	