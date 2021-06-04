/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmahoro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 18:34:50 by dmahoro-          #+#    #+#             */
/*   Updated: 2021/06/04 18:34:54 by dmahoro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	if (!s)
		return (0);
	count = 0;
	while (s[count])
		count++;
	return (count);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = dest;
	s = src;
	while (n--)
		*d++ = *s++;
	return (dest);
}

char	*ft_strcat(char *dest, const char *src)
{
	char	*buff;

	buff = dest;
	while (*buff)
		buff++;
	while (*src)
		*buff++ = *src++;
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	n1;
	size_t	n2;
	size_t	pos;

	n1 = ft_strlen(s1);
	n2 = ft_strlen(s2);
	ret = (char *)malloc(n1 + n2 + 1);
	if (!ret)
		return (NULL);
	pos = 0;
	while (pos < (n1 + n2 + 1))
		ret[pos++] = '\0';
	ret = (char *)ft_memcpy(ret, s1, n1);
	ret = ft_strcat(ret, s2);
	free((char *)s1);
	return (ret);
}

int	ft_hasnewlinechar(const char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}
