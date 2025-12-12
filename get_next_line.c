/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouane <brouane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:39:09 by brouane          #+#    #+#             */
/*   Updated: 2025/12/07 16:19:26 by brouane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*next_line(char *working_line)
{
	char	*line;
	int		i;
	int		add;

	i = 0;
	add = 1;
	if (!working_line || working_line[i] == '\0')
		return (NULL);
	while (working_line[i] && working_line[i] != '\n')
		i++;
	if (working_line[i] == '\n')
		add = 2;
	line = (char *)malloc(sizeof(char) * (i + add));
	if (!line)
		return (NULL);
	i = -1;
	while (working_line[++i] && working_line[i] != '\n')
		line[i] = working_line[i];
	if (working_line[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*read_line(char *working_line, int fd)
{
	char		*buffer;
	ssize_t		readen;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	readen = 1;
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (readen > 0 && ft_strchr(working_line))
	{
		readen = read(fd, buffer, BUFFER_SIZE);
		if (readen == -1)
			return (free(buffer), NULL);
		buffer[readen] = '\0';
		working_line = ft_strjoin(working_line, buffer);
	}
	free(buffer);
	return (working_line);
}

char	*new_line(char *working_line)
{
	int		i;
	int		j;
	char	*new_working_line;

	i = 0;
	while (working_line[i] && working_line[i] != '\n')
		i++;
	if (!working_line[i])
		return (free(working_line), NULL);
	new_working_line = (char *)malloc((ft_strlen(working_line) - i++));
	if (!new_working_line)
		return (NULL);
	j = 0;
	while (working_line[i])
		new_working_line[j++] = working_line[i++];
	new_working_line[j] = '\0';
	free(working_line);
	return (new_working_line);
}

char	*get_next_line(int fd)
{
	static char	*working_line;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	working_line = read_line(working_line, fd);
	if (!working_line)
		return (NULL);
	line = next_line(working_line);
	working_line = new_line(working_line);
	if (working_line && !*working_line)
	{
		free(working_line);
		working_line = NULL;
	}
	return (line);
}
