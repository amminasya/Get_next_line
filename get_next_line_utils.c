/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminasya <aminasya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:30:30 by aminasya          #+#    #+#             */
/*   Updated: 2022/03/28 14:04:26 by aminasya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char	*new;
	size_t	i;

	if (!s1)
		return (NULL);
	i = 0;
	new = (char *)malloc(ft_strlen(s1) + 1);
	if (!new)
		return (NULL);
	while (i < ft_strlen(s1) && *s1)
	{
		*(new + i) = *(s1 + i);
		i++;
	}
	*(new + i) = '\0';
	return (new);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*strjoin;
	size_t	i;
	size_t	j;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	strjoin = (char *)malloc(s1_len + s2_len + 1);
	if (!strjoin)
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		strjoin[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < s2_len)
		strjoin[i++] = s2[j++];
	strjoin[i] = '\0';
	if (s1)
		free(s1);
	return (strjoin);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ptr;
	size_t			i;
	unsigned int	l;

	if (!s)
		return (NULL);
	l = ft_strlen(s);
	if (l < start)
		len = 0;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	if (!ptr)
		return (NULL);
	while (i < len)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
