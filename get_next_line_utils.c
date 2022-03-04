/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nucieda- <nucieda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:20:45 by nucieda-          #+#    #+#             */
/*   Updated: 2022/03/04 20:30:49 by nucieda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(char *str, int c, size_t n)
{
	while (n)
	{
		*str = c;
		str++;
		n--;
	}
	return (NULL);
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
	dest[i] = '\0';
}

int	ft_strchr(char *str, int c)
{
	int	chr_count;
	int	nl_count;

	chr_count = 0;
	nl_count = 0;
	if (c == 3)
	{
		while(*str)
		{
			str++;
			chr_count++;
		}
		return (chr_count);
	}
	while (*str)
	{
		if (*str == '\n')
		{
			nl_count++;
			break ;
		}
		chr_count++;
		str++;
	}
	if (nl_count == 0)
	{
		return (-1);
	}
	str++;
	while (*str == '\n')
	{
		str++;
		nl_count++;
	}
	if (c == 0)
	{
		return (chr_count);
	}
	else if (c == 1)
	{
		return (nl_count);
	}
	else
	{
		return (chr_count + nl_count);
	}
}
