/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:20:09 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/03/26 14:34:10 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_msg(char *msg)
{
	ft_putendl_fd(msg, 2);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	if (map->area)
	{
		while (map->area[i])
		{
			free(map->area[i]);
			i++;
		}
		free(map->area);
	}
	free(map);
}

void	close_game(void *parametr)
{
	t_game	*game;

	game = (t_game *)parametr;
	if (game->mlx)
		mlx_terminate(game->mlx);
	if (game->map)
		free_map(game->map);
	ft_putendl_fd("Bye Bye", 1);
	exit(0);
}

void	error_close_game(void *parametr)
{
	t_game	*game;

	game = (t_game *)parametr;
	if (game->mlx)
		mlx_terminate(game->mlx);
	if (game->map)
		free_map(game->map);
	ft_putendl_fd("error mlx", 1);
	exit(0);
}

char	*read_file(int fd)
{
	char	*buffer;
	char	temp_buffer[2];
	char	*temp;
	int		bytes_read;

	bytes_read = 1;
	buffer = NULL;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, temp_buffer, 1);
		if (bytes_read <= 0)
			break ;
		temp_buffer[bytes_read] = '\0';
		temp = ft_strjoin(buffer, temp_buffer);
		free(buffer);
		buffer = temp;
		if (!buffer)
			return (NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (buffer);
}
