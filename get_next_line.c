/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dievarga <dievarga@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:43:28 by dievarga          #+#    #+#             */
/*   Updated: 2025/10/30 18:29:31 by dievarga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



char	*get_next_line(int fd)
{
	fptr = 
}

#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#ifdef
	 

int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	printf("fd = %d\n", fd);
	if (fd == -1)
	{
		printf("Error number % d\n", errno);
		perror("Program");
	}
	while (fd == 1)
		get_next_line(1);
	close(fd);
	return (0);
}
