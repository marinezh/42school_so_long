/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 13:59:30 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/03/26 12:56:12 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*get_next_line(int fd)
// {
// 	static char	*buffer;
// 	char		*line;

// 	if (fd == -1)
// 	{
// 		free(buffer);
// 		buffer = NULL;
// 		return (NULL);
// 	}
// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	buffer = read_to_buffer(fd, buffer);
// 	if (!buffer)
// 		return (NULL);
// 	if (*buffer)
// 	{
// 		line = extract_line(&buffer);
// 		if (!line)
// 		{
// 			free(buffer);
// 			buffer = NULL;
// 		}
// 		return (line);
// 	}
// 	return (NULL);
// }

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_to_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	if (*buffer)
		line = extract_line(&buffer);
	else
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	return (line);
}



