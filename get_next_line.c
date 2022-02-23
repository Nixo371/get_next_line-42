/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nucieda- <nucieda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:02:49 by nucieda-          #+#    #+#             */
/*   Updated: 2022/02/23 19:13:52 by nucieda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static int	position = 0;
	static char	*next_line;
	
	next_line = malloc(BUFFER_SIZE * sizeof(char));
	if (next_line == NULL)
		return (NULL);
	read(fd, next_line, BUFFER_SIZE);
	return (next_line);
}

int main(int argc, char **argv)
{
	int		fd;
	char	*gnl;

	fd = open("test.txt", O_RDONLY);
	gnl = get_next_line(fd);
	printf("%s\n", gnl);
}
