/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dick.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nucieda- <nucieda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:02:49 by nucieda-          #+#    #+#             */
/*   Updated: 2022/03/03 21:51:36 by nucieda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*nl;

	if (buffer == NULL)
		buffer = malloc(BUFFER_SIZE * sizeof(char));
	if (*buffer == '\0')
		read(fd, buffer, BUFFER_SIZE);
	ft_strlcpy(nl, buffer + ft_strchr(buffer, 1), ft_strchr(buffer, 0));
	ft_strlcpy(buffer, buffer + ft_strchr(buffer, 0), BUFFER_SIZE - ft_strchr(buffer, 0));
	ft_memset(buffer + ft_strchr(buffer, 0), '\0', BUFFER_SIZE - ft_strchr(buffer, 0));
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
}*/
