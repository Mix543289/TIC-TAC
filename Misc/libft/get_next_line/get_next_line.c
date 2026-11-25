/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 03:01:15 by dcharbon          #+#    #+#             */
/*   Updated: 2026/11/25 05:02:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*read_and_grab(int fd, ssize_t *read_count)
{
	char	*grabbing_buffer;

	grabbing_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (grabbing_buffer == NULL)
	{
		*read_count = -1;
		return (NULL);
	}
	*read_count = read(fd, grabbing_buffer, BUFFER_SIZE);
	if (*read_count < 0)
		return (free(grabbing_buffer), NULL);
	if (*read_count == 0)
		return (free(grabbing_buffer), NULL);
	return (grabbing_buffer);
}

char	*update_stash(char *stash, int fd)
{
	char	*grabbed_buffer;
	char	*append_buffer;
	ssize_t	read_count;

	if (!stash)
	{
		stash = ft_calloc(1, sizeof(char));
		if (!stash)
			return (NULL);
	}
	while (!ft_strchr(stash, '\n'))
	{
		grabbed_buffer = read_and_grab(fd, &read_count);
		if (read_count < 0 || (read_count == 0 && !*stash))
			return (free(stash), NULL);
		if (read_count == 0)
			break ;
		append_buffer = ft_strjoin(stash, grabbed_buffer);
		free(stash);
		free(grabbed_buffer);
		if (!append_buffer)
			return (NULL);
		stash = append_buffer;
	}
	return (stash);
}

static char	*extract_and_update_stash(char **stash)
{
	char	*line;
	char	*new_stash;
	int		start;

	start = 0;
	while ((*stash)[start] && (*stash)[start] != '\n')
		start++;
	if (!(*stash)[start])
	{
		line = *stash;
		return ((*stash = NULL), line);
	}
	line = ft_substr(*stash, 0, start + 1);
	if (!line)
		return (free(*stash), (*stash = NULL), NULL);
	new_stash = ft_substr(*stash, start + 1, ft_strlen(*stash) - start - 1);
	if (!new_stash)
		return ((free(*stash)), (*stash = NULL), free(line), NULL);
	free(*stash);
	*stash = new_stash;
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash[1024];

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = update_stash(stash[fd], fd);
	if (!stash[fd])
		return (NULL);
	if (!*stash[fd])
	{
		free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	line = extract_and_update_stash(&stash[fd]);
	return (line);
}
