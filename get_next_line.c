/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nucieda- <nucieda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:02:49 by nucieda-          #+#    #+#             */
/*   Updated: 2022/02/24 19:44:42 by nucieda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*manage_overflow(const char *dest, const char *src, int len)
{
	char	*d;
	char	*s;

	d = (char *)dest;
	s = (char *)src + len;
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
	static int	position = 0;
	int			old_pos;
	static char	*overflow = NULL;
	char		*buffer;
	char		*nl;

	old_pos = position;
	buffer = malloc(BUFFER_SIZE * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	if (overflow == NULL)
		overflow = malloc(BUFFER_SIZE * sizeof(char));
	if (overflow && ft_strlen(overflow))
	{
		ft_strlcpy(buffer, overflow, ft_strlen(overflow));
	}
	else
		read(fd, buffer, BUFFER_SIZE);
	position = position + ft_strchr(buffer, '\n');
	nl = malloc((position - old_pos + 1) * sizeof(char));
	ft_strlcpy(nl, buffer, (position - old_pos));
	if (position - old_pos < BUFFER_SIZE)
	{
		overflow = manage_overflow(overflow, buffer, position - old_pos);
	}
	printf("%c\n", *(buffer + position - old_pos));
	free(buffer);
	return (nl);
}

int main(int argc, char **argv)
{
	int		fd;

	fd = open("test.txt", O_RDONLY);
	printf("%s\n\n", get_next_line(fd));
	printf("%s\n\n", get_next_line(fd));
	printf("%s\n\n", get_next_line(fd));
	printf("%s\n\n", get_next_line(fd));
	printf("%s\n\n", get_next_line(fd));
	printf("%s\n\n", get_next_line(fd));
}
