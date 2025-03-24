/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:44:47 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/03/24 14:21:38 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	size_check(t_map *map)
{
	int	i;

	i = 0;
	if (!map || !map->area || !map->area[0])
		return (error_msg("Invalid map structure"), -1);
	map->size_x = ft_strlen(map->area[0]);
	while (i < map->size_y)
	{
		if ((int)ft_strlen(map->area[i]) != map->size_x)
			return (error_msg("map is not reqtangular"), -1);
		i++;
	}
	return (1);
}

int	lines_count(char *filename)
{
	int		fd;
	int		count;
	char	*line;

	count = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (error_msg("file openning error 1"), -1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		count++;
		free(line);
	}
	printf("lines count %d\n", count);
	close(fd);
	return (count);
}

int	read_map(t_map *map, char *filename, int max_lines)
{
	int		fd;
	int		i;
	char	*line;
	char	*new_line;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (error_msg("file openning error"), -1);
	while (i < max_lines)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		new_line = ft_strchr(line, '\n');
		if (new_line)
			*new_line = '\0';
		map->area[i] = ft_strdup(line);
		//ft_printf("line is %s\n", map->area[i]);
		free(line);
		i++;
	}
	map->area[i] = NULL;
	
	return (1);
}

int	name_validation(char *filename)
{
	char	*extension;
	int		len;

	len = ft_strlen(filename);
	if (len < 5)
		return (-1);
	extension = ft_strchr(filename, '.');
	if (!extension || ft_strncmp(extension, ".ber", len) != 0)
		return (-1);
	return (1);
}



t_map	*parsing_args(char *filename)
{
	t_map	*map;

	if (name_validation(filename) < 0)
		return (error_msg("wrong file name"), NULL);
	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		return (free_map(map), error_msg("memory error"), NULL);
	map->size_y = lines_count(filename);
	if (map->size_y < 1)
		return (free_map(map), error_msg("error file reading"), NULL);
	map->area = ft_calloc(map->size_y + 1, sizeof(char *));
	if (!map->area)
		return (free_map(map), error_msg("memory error"), NULL);

	if (read_map(map, filename, map->size_y + 1) < 0)
		return (free_map(map),error_msg("read map failed"), NULL);
	if (size_check(map) < 0 || symbols_check(map) < 0 
		|| player_check(map) < 0 || exit_check(map) < 0 
		|| collectables_check(map) < 0 )
		return (free_map(map), NULL); 
	if(path_check(map) < 0)
		return (free_map(map), error_msg("path check failed"), NULL); 
	// Print for debugging DELETE LATER!!!
	int j = 0;
	while (map->area[j])
		printf("map is %s\n", map->area[j++]);
	return (map);
}
