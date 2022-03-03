/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nucieda- <nucieda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:20:45 by nucieda-          #+#    #+#             */
/*   Updated: 2022/03/03 21:49:11 by nucieda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *str, int c, size_t n)
{
	char	*strr;
	
	strr = str;
	while (*strr)
		strr++;
	while (n > 0)
	{
		*strr = c;
		strr++;
		n--;
	}
	return (str);
}


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
	int	i;

	i = 0;
	if (len == 0)
		return ;
	while (len-- && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (len-- > 0)
		dest[i] = '\0';
}

int	ft_strchr(const char *str, int c)
{
	const char	*s;
	int			nl_overflow;

	nl_overflow = 0;
	s = str;
	if (c == 1)
	{
		while(*str == '\n')
		{
			str++;
			nl_overflow++;
		}
		return (nl_overflow);
	}
	while (*str)
	{
		if (*str == '\n')
			break;
		str++;
	}
	while(*str == '\n')
	{
		str++;
		nl_overflow++;
	}
	return ((str - s + 1) - nl_overflow);
}
