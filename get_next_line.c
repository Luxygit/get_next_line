/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dievarga <dievarga@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:43:28 by dievarga          #+#    #+#             */
/*   Updated: 2025/11/12 16:06:24 by dievarga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_find(char **heap)
{
	int		nl;
	char	*line;
	char	*rest;

	nl = ft_strichr(*heap, '\n');
	if (nl < 0)
	{
		line = ft_substr(*heap, 0, ft_strlen(*heap));
		free(*heap);
		*heap = NULL;
		return (line);
	}
	line = ft_substr(*heap, 0, nl + 1);
	rest = ft_substr(*heap, nl + 1, ft_strlen(*heap) - nl - 1);
	free(*heap);
	*heap = rest;
	return (line);
}

static int	ft_readfile(int fd, char **heap)
{
	char	buf[BUFFER_SIZE + 1];
	char	*tmp;
	ssize_t	r;

	r = 1;
	while (r > 0 && (*heap == NULL || ft_strichr(*heap, '\n') < 0))
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r <= 0)
			break ;
		buf[r] = '\0';
		tmp = *heap;
		if (!*heap)
			*heap = ft_substr(buf, 0, r);
		else
			*heap = ft_strjoin(*heap, buf);
		free(tmp);
	}
	return ((int)r);
}

char	*get_next_line(int fd)
{
	static char	*heap;
	int			r;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	r = ft_readfile(fd, &heap);
	if (!heap || r < 0 || *heap == '\0')
	{
		free(heap);
		heap = NULL;
		return (NULL);
	}
	return (ft_find(&heap));
}

/*
getnextline function gets file decriptor and calls
 ft_readfile to try to read the file an amount of 
 buffersize bytes. 
 
 *Read() remembers the last buffer read.
 *Read returns the amount of bytes read in ssize_t.
 -1 would mean an error when reading. permission
 or bad fd.

ft_readfile function takes the fd and the heap mem 
address(double pointer) so it can modify the value.
It declares a buffer to store all to be read, a 
tmp string 

ft_build_line


*/
#include <fcntl.h>
#include <stdio.h>
int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
//	fd = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}

/*
this main opens test.txt file and calls getnextline
in a loop for every line of the file until the end.
fd 0 or 1 (stdin stdout) should be read.
*/
