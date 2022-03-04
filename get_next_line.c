/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nucieda- <nucieda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:02:49 by nucieda-          #+#    #+#             */
/*   Updated: 2022/03/04 20:29:51 by nucieda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*overflow = NULL;
	char		*buffer;
	char		*nl;
	char		*next_line;
	int			read_amount;

	buffer = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	if (overflow == NULL)
	{
		overflow = malloc(BUFFER_SIZE * sizeof(char));
		*overflow = '\0';
	}
	if (overflow && *overflow)
	{
		if(ft_strchr(overflow, 0) == -1 && ft_strlen(overflow) < BUFFER_SIZE)
		{
			read(fd, overflow + ft_strchr(overflow, 1), BUFFER_SIZE - ft_strchr(overflow, 1));
		}
		ft_strlcpy(buffer, overflow, ft_strlen(overflow));
	}
	else
	{
		read_amount = read(fd, buffer, BUFFER_SIZE);
		ft_memset(buffer + read_amount, '\0', BUFFER_SIZE - read_amount);
	}
	if (ft_strchr(buffer, 0) == -1)
	{
		nl = malloc(BUFFER_SIZE + 1 * sizeof(char));
		ft_strlcpy(nl, buffer, BUFFER_SIZE);
	}
	else
	{
		nl = malloc(ft_strchr(buffer, 0) + 1 * sizeof(char));
		ft_strlcpy(nl, buffer, ft_strchr(buffer, 0) + 1);
	}
	if (*overflow && ft_strchr(buffer, 2) != -1)
	{
		ft_strlcpy(overflow, overflow + ft_strchr(buffer, 2), BUFFER_SIZE - ft_strchr(buffer, 2));
		ft_memset(overflow + ft_strchr(buffer, 3), '\0', BUFFER_SIZE - ft_strchr(buffer, 3));
	}
	else if (*overflow && ft_strchr(buffer, 2) == -1)
	{
		*overflow = '\0';
	}
	else
	{
		ft_strlcpy(overflow, buffer + ft_strchr(buffer, 2), BUFFER_SIZE);
	}
	next_line = "";
	ft_strlcpy(next_line, nl, ft_strlen(nl));
	free(nl);
	free(buffer);
	return (next_line);
}

/*int main(int argc, char **argv)
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
	printf("%s%s\n", get_next_line(fd), oop);
	printf("%s%s\n", get_next_line(fd), oop);
	printf("%s%s\n", get_next_line(fd), oop);
}*/
