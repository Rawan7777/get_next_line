/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouane <brouane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:41:08 by brouane          #+#    #+#             */
/*   Updated: 2025/12/04 17:53:35 by brouane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_strchr(char *working_line)
{
	int	i;

	i = 0;
	while (working_line && working_line[i])
	{
		if (working_line[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strjoin_copy(char *joined, char *working_line, char *buffer)
{
	int	i;
	int	j;

	i = 0;
	while (working_line[i])
	{
		joined[i] = working_line[i];
		i++;
	}
	j = 0;
	while (buffer[j])
		joined[i++] = buffer[j++];
	joined[i] = '\0';
	return (joined);
}

char	*ft_strjoin(char *working_line, char *buffer)
{
	char	*joined;

	if (!buffer)
		return (NULL);
	if (!working_line)
	{
		working_line = malloc(sizeof(char));
		if (!working_line)
			return (NULL);
		working_line[0] = '\0';
	}
	joined = malloc((ft_strlen(working_line) + ft_strlen(buffer) + 1));
	if (!joined)
		return (free(working_line), NULL);
	ft_strjoin_copy(joined, working_line, buffer);
	return (free(working_line), joined);
}
