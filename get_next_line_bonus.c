/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvidon-n <joanavidon@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:54:15 by jvidon-n          #+#    #+#             */
/*   Updated: 2022/05/12 18:10:23 by jvidon-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	read_file(int fd, char *buffer, char **str)
{
	char	*temp;
	int		i;

	if (!*str || !ft_strchr(*str, '\n'))
	{
		i = read(fd, buffer, BUFFER_SIZE);
		while (i > 0)
		{
			buffer[i] = '\0';
			if (!*str)
				*str = ft_substr(buffer, 0, i);
			else
			{
				temp = *str;
				*str = ft_join(*str, buffer);
				free(temp);
			}
			if (ft_strchr(buffer, '\n'))
				break ;
			i = read(fd, buffer, BUFFER_SIZE);
		}
	}
	free(buffer);
}

static char	*get_line(char **str)
{
	char	*line;
	char	*temp;
	int		after_n;

	if (!*str)
		return (NULL);
	if (!ft_strchr(*str, '\n'))
	{
		line = ft_substr(*str, 0, ft_strlen(*str));
		free(*str);
		*str = '\0';
		if (!*line)
		{
			free(line);
			return (NULL);
		}
		return (line);
	}
	after_n = ft_strlen(ft_strchr(*str, '\n'));
	line = ft_substr(*str, 0, ft_strlen(*str) - after_n +1);
	temp = *str;
	*str = ft_substr(ft_strchr(*str, '\n'), 1, after_n -1);
	free(temp);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*str[255];
	char		*buffer;
	char		*line;

	buffer = malloc(sizeof (char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (fd == -1 || BUFFER_SIZE <= 0 || read(fd, buffer, 0) == -1)
	{
		free(buffer);
		return (NULL);
	}
	read_file(fd, buffer, &str[fd]);
	line = (get_line(&str[fd]));
	return (line);
}
