/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nucieda- <nucieda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:20:45 by nucieda-          #+#    #+#             */
/*   Updated: 2022/02/24 19:45:59 by nucieda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	const char	*s;

	s = str;
	while (*s)
		s++;
	return (s - str);
}

void	ft_strlcpy(char *dest, char *src, int len)
{
	if (len == 0)
		return ;
	while (len--)
		*dest++ = *src++;
	*dest = '\0';
}

int	ft_strchr(const char *str, int c)
{
	char		*pointer;
	const char	*s;

	s = str;
	while(*str == c)
		str++;
	str--;
	if (*str == c)
		pointer = (char *)str;
	while (*str)
	{
		if (*str == c)
			return (str - s);
		str++;
	}
	return (BUFFER_SIZE);
}
