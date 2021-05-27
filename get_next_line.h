/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmahoro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 20:16:52 by dmahoro-          #+#    #+#             */
/*   Updated: 2021/04/12 22:18:59 by dmahoro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(char const *str);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strjoin(const char *s1, const char *s2);
int		ft_hasnewlinechar(char const *str);

char	*get_remaining_string(char *readstr);
char	*ft_getline(char *readstr);
int		get_next_line(int fd, char **line);
int		get_return(int nread);

#endif
