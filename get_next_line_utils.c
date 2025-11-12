/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dievarga <dievarga@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 13:35:36 by dievarga          #+#    #+#             */
/*   Updated: 2025/11/12 02:06:09 by dievarga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joint;
	size_t	len1;
	size_t	len2;
	char	*ptr;

	if (!s1 && !s2)
		return (NULL);
	len1 = ft_strlen((char *)s1);
	len2 = ft_strlen((char *)s2);
	joint = malloc(len1 + len2 + 1);
	if (!joint)
		return (NULL);
	ptr = joint;
	if (s1)
		while (*s1)
			*ptr++ = *s1++;
	if (s2)
		while (*s2)
			*ptr++ = *s2++;
	*ptr = '\0';
	return (joint);
}

int	ft_strichr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return (i);
		i++;
	}
	if ((unsigned char)c == '\0')
		return (i);
	return (-1);
}

static void	ft_strcpy(const char *s, char *d, size_t len)
{
	while (len--)
		*d++ = *s++;
	*d = '\0';
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*d;
	char	*ret;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
	{
		d = malloc(1);
		if (!d)
			return (NULL);
		d[0] = '\0';
		return (d);
	}
	if (len > slen - start)
		len = slen - start;
	d = malloc (len + 1);
	if (!d)
		return (NULL);
	ret = d;
	s = s + start;
	ft_strcpy(s, d, len);
	return (ret);
}
