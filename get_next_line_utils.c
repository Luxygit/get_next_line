/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dievarga <dievarga@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 13:35:36 by dievarga          #+#    #+#             */
/*   Updated: 2025/10/30 18:29:26 by dievarga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	ft_strlen(char *s)
{
	size_t	count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

char *ft_strjoin(char const *s1, char const *s2)
{
	char	*joint;
	size_t	len1;
	size_t	len2;
	char	*ptr;

	if (!s1 && !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
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

//add one more trim??
