/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aregragu <aregragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:03:28 by aregragu          #+#    #+#             */
/*   Updated: 2025/01/04 23:01:02 by aregragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>

static char	*read_join(int fd, char *lib9a)
{
	char	*buffer;
	ssize_t	i;

	if (BUFFER_SIZE < 0)
		return (NULL);
	while (1)
	{
		if (ft_strchr(lib9a, '\n'))
			break ;
		buffer = (char *)malloc((size_t)BUFFER_SIZE + 1);
		if (!buffer)
			return (free(lib9a), NULL);
		i = read(fd, buffer, BUFFER_SIZE);
		if (i < 0)
			return (free(lib9a), free(buffer), NULL);
		if (i == 0)
			return (free(buffer), lib9a);
		buffer[i] = '\0';
		lib9a = ft_strjoin(lib9a, buffer);
		free(buffer);
	}
	return (lib9a);
}

static char	*line_extra(char **lib9a)
{
	char	*line_nadi;
	char	*new_line;
	char	*tmp;

	new_line = ft_strchr(*lib9a, '\n');
	if (!new_line)
		return (NULL);
	line_nadi = ft_substr(*lib9a, 0, new_line - *lib9a + 1);
	if (!line_nadi)
		return (NULL);
	tmp = ft_strdup(new_line + 1);
	if (!tmp)
	{
		free(line_nadi);
		return (NULL);
	}
	free(*lib9a);
	*lib9a = tmp;
	return (line_nadi);
}

char	*get_next_line(int fd)
{
	static char	*lib9a;
	char		*line_nadi;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!lib9a)
		lib9a = ft_strdup("");
	lib9a = read_join(fd, lib9a);
	if (!lib9a)
		return (NULL);
	line_nadi = line_extra(&lib9a);
	if (line_nadi)
		return (line_nadi);
	if (ft_strlen(lib9a) > 0)
	{
		line_nadi = ft_strdup(lib9a);
		free(lib9a);
		lib9a = NULL;
		return (line_nadi);
	}
	return (free(lib9a), lib9a = NULL, NULL);
}

// #include <stdio.h>
// int main()
// {
//     int fd;
//     char *line;

//     fd = open("test.txt", O_RDONLY);
//     if (fd == -1)
//     {
//         return (1);
//     }

//     while ((line = get_next_line(fd)) != NULL)
//     {
//         printf("%s", line);
//         free(line);
//     }

//     close(fd);

//     return (0);
// }