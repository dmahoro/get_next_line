/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmahoro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 18:34:02 by dmahoro-          #+#    #+#             */
/*   Updated: 2021/06/04 18:34:08 by dmahoro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	get_return(int nread)
{
	if (nread == 0)
		return (0);
	return (1);
}

char	*get_remaining_string(char *readstr)
{
	char	*ret;
	char	*ite;
	size_t	i;

	if (!readstr)
		return (NULL);
	i = 0;
	while (readstr[i] && readstr[i] != '\n')
		i++;
	if (!readstr[i])
	{
		free(readstr);
		return (NULL);
	}
	ret = (char *)malloc(sizeof(ret) * (ft_strlen(readstr) - i + 1));
	if (!ret)
		return (NULL);
	i++;
	ite = ret;
	while (readstr[i])
		*ite++ = readstr[i++];
	*ite = '\0';
	free(readstr);
	return (ret);
}

char	*ft_getline(char *readstr)
{
	char	*ret;
	size_t	i;

	if (!readstr)
		return (NULL);
	i = 0;
	while (readstr[i] && readstr[i] != '\n')
		i++;
	ret = (char *)malloc(sizeof(char) * (i + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (readstr[i] && readstr[i] != '\n')
	{
		ret[i] = readstr[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

int	get_next_line(int fd, char **line)
{
	char		*buff;
	static char	*readstr[N_FD];
	int			nread;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(buff));
	if (!buff)
		return (-1);
	nread = 1;
	while (!ft_hasnewlinechar(readstr[fd]) && nread)
	{
		nread = read(fd, buff, BUFFER_SIZE);
		if (nread == -1)
		{
			free(buff);
			return (-1);
		}
		buff[nread] = '\0';
		readstr[fd] = ft_strjoin(readstr[fd], buff);
	}
	free(buff);
	*line = ft_getline(readstr[fd]);
	readstr[fd] = get_remaining_string(readstr[fd]);
	return (get_return(nread));
}
