/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nucieda- <nucieda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:04:01 by nucieda-          #+#    #+#             */
/*   Updated: 2022/03/04 19:42:35 by nucieda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

char	*get_next_line(int fd);
int		ft_strchr(char *str, int c);
void	ft_strlcpy(char *dest, char *src, int len);
size_t	ft_strlen(const char *str);
void	*ft_memset(char *str, int c, size_t n);

#endif