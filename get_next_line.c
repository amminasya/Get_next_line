/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminasya <aminasya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:00:30 by aminasya          #+#    #+#             */
/*   Updated: 2022/03/28 16:49:38 by aminasya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

static char	*checkslash(char **backup)
{
	size_t	i;
	char	*line;
	char	*newbackup;

	if (!(*backup))
		return (NULL);
	line = NULL;
	if (ft_strchr (*backup, '\n'))
	{
		i = ft_strchr(*backup, '\n') - *backup + 1;
		line = ft_substr(*backup, 0, i);
		newbackup = ft_strdup(*backup + i);
		if (*newbackup == '\0')
		{
			free (newbackup);
			newbackup = NULL;
		}
		free (*backup);
		*backup = newbackup;
	}
	return (line);
}

static char	*ft_zero(char **backup)
{
	char	*line;

	line = ft_strdup(*backup);
	free(*backup);
	*backup = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	char		temp[BUFFER_SIZE + 1];
	static char	*backup = NULL;
	char		*line;
	ssize_t		bites;

	if (fd < 0 || fd > 65536 || BUFFER_SIZE <= 0)
		return (NULL);
	line = checkslash(&backup);
	if (line != NULL)
		return (line);
	bites = 1;
	while (bites != 0)
	{
		bites = read(fd, temp, BUFFER_SIZE);
		if (bites == -1)
			return (NULL);
		temp[bites] = '\0';
		if (bites > 0)
			backup = ft_strjoin(backup, temp);
		line = checkslash(&backup);
		if (line != NULL)
			return (line);
	}
	line = ft_zero(&backup);
	return (line);
}


int    main(void)
{
    char    *a;
    int        fd;

    fd = open("get_next_line.h", O_RDONLY);
    printf("fd = %d\n", fd);
    if (fd == -1)
    {
        printf("Program Error");
    }
    a = get_next_line(fd);
    printf("my line1:%s\n", a); // 1
    if (a != NULL)
        free(a);
    a = get_next_line(fd);
    printf("my line2:%s\n", a);
    if (a != NULL)
        free(a);
    a = get_next_line(fd);
    printf("my line3:%s\n", a);
    if (a != NULL)
        free(a);
    a = get_next_line(fd);
    printf("my line4:%s\n", a);
    if (a != NULL)
        free(a);
    a = get_next_line(fd);
    printf("my line5:%s\n", a);
    if (a != NULL)
        free(a);
    a = get_next_line(fd);
    printf("my line6:%s\n", a);
    if (a != NULL)
        free(a);
    if (close(fd) < 0)
    {
        perror("c1");
        exit(1);
    }
    return (0);
}
