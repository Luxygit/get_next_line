/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dievarga <dievarga@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:43:28 by dievarga          #+#    #+#             */
/*   Updated: 2025/11/04 01:15:58 by dievarga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

char	*get_next_line(int fd)
{
	char	*line;
	int		i;
	char	c;
	ssize_t	r;

	line = malloc(BUFFER_SIZE);
	if (!line)
		return (NULL);
	i = 0;
	r = read(fd, &c, 1);
	while (r > 0)
	{
		line[i] = c;
		i++;
		if (c == '\n')
			break ;
		r = read(fd, &c, 1);
	}
	if (r == 0 && i == 0)
	{
		free(line);
		return (NULL);
	}
	line[i] = '\0';
	return (line);
}

/*
getnextline function gets file decriptor and READS
one char  until the \0. Then remembers
the last buffer read.
read returns the amount of bytes read

ft_read_line function takes the line string and
measures length and allocates mem for it.

ft_build_line

*/

#include <fcntl.h>

int	main(void)
{
	int	fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}

/* 
this main opens test.txt file and calls getnextline
in a loop for every line of the file until the end.
fd 1 or 2 (stdin stdout) should be read.
*/
