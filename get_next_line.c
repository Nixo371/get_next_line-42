/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nucieda- <nucieda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:02:49 by nucieda-          #+#    #+#             */
/*   Updated: 2022/03/03 22:58:03 by nucieda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*manage_overflow(const char *dest, const char *src, int len)
{
	char	*d;
	char	*s;

	d = (char *)dest;
	s = (char *)src;
	while (len--)
		s++;
	while(*s)
	{
		*d = *s;
		d++;
		s++;
	}
	return ((char *)dest);
	
}

char	*get_next_line(int fd)
{
	static char	*overflow = NULL;
	char		*buffer;
	char		*nl;

	buffer = malloc(BUFFER_SIZE * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	if (overflow == NULL)
	{
		overflow = malloc(BUFFER_SIZE * sizeof(char));
	}
	if (overflow && *overflow)
	{	
		ft_strlcpy(buffer, overflow, ft_strlen(overflow));
	}
	else
		read(fd, buffer, BUFFER_SIZE);
	if (buffer == 0)
		return ("nothing here for you...\n");
	nl = malloc((ft_strchr(buffer, 0) + 1) * sizeof(char));
	ft_strlcpy(nl, buffer, ft_strchr(buffer, 0));
	if (ft_strlen(overflow) == ft_strlen(nl))
	{
		read(fd, (buffer + ft_strlen(buffer)), BUFFER_SIZE - ft_strlen(buffer));
	}
	printf("strlen: %d\n", ft_strlen(nl));
	if (ft_strlen(nl) < BUFFER_SIZE + 1)
	{
		overflow = manage_overflow(overflow, buffer, ft_strlen(nl));
	}
	else if (ft_strlen(nl) == BUFFER_SIZE + 1  )
	{
		*overflow = '\0';
		printf("%d\n", ft_strlen(overflow));
	}
	free(buffer);
	return (nl);
}

int main(int argc, char **argv)
{
	int		fd;
	char 	*oop = "------------------------------------------------------------------------";

	fd = open("test.txt", O_RDONLY);
	printf("%s\n", oop);
	printf("%s%s\n", get_next_line(fd), oop);
	printf("%s%s\n", get_next_line(fd), oop);
	printf("%s%s\n", get_next_line(fd), oop);
	printf("%s%s\n", get_next_line(fd), oop);
	printf("%s%s\n", get_next_line(fd), oop);
	printf("%s%s\n", get_next_line(fd), oop);
	printf("%s%s\n", get_next_line(fd), oop);
	printf("%s%s\n", get_next_line(fd), oop);
	printf("%s%s\n", get_next_line(fd), oop);
	printf("%s%s\n", get_next_line(fd), oop);
	printf("%s%s\n", get_next_line(fd), oop);
	printf("%s%s\n", get_next_line(fd), oop);
}
