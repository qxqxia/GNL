/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qxia <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 15:54:16 by qxia              #+#    #+#             */
/*   Updated: 2021/12/29 18:14:51 by qxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

size_t	ft_strlen(const char *s);

char	*ft_strdup(const char *s1);

char	*ft_strjoin(char const *s1, char const *s2);

char	*get_next_line(int fd);

#endif