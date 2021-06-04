/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmahoro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 18:32:02 by dmahoro-          #+#    #+#             */
/*   Updated: 2021/06/04 18:33:35 by dmahoro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef N_FD
#  define N_FD 65535
# endif

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
