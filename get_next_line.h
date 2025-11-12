/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dievarga <dievarga@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 13:36:28 by dievarga          #+#    #+#             */
/*   Updated: 2025/11/12 02:04:40 by dievarga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <errno.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(char *s);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strichr(const char *s, int c);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*get_net_line(int fd);

#endif
