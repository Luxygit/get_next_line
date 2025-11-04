/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dievarga <dievarga@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 13:36:28 by dievarga          #+#    #+#             */
/*   Updated: 2025/11/03 20:42:02 by dievarga         ###   ########.fr       */
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
char	*get_net_line(int fd);

#endif
