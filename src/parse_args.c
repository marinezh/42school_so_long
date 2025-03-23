/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:44:47 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/03/23 14:25:57 by mzhivoto         ###   ########.fr       */
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

int	map_lines(char *filename)
{
	int		fd;
	int		count;
	char	*line;

	count = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (error_msg("file openning error 1"), 0);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		count++;
		free(line);
	}
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
	int		j;

	if (name_validation(filename) < 0)
		return (error_msg("wrong file name"), NULL);
	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		return (NULL);
	map->size_y = map_lines(filename);
	if (map->size_y < 1)
		return (free_map(map), error_msg("error file reading"), NULL);
	printf("lines %d\n", map->size_y);
	map->area = ft_calloc(map->size_y + 1, sizeof(char *));
	if (!map->area)
		return (free(map), NULL);
	read_map(map, filename, map->size_y + 1);
	if (size_check(map) < 0)
		return (free(map), NULL); // need to free map area, LEAK IS HERE
	symbols_check(map);
	player_check(map);
	printf("map player position x %d and y %d\n", map->player_pos.x, map->player_pos.y);
	exit_check(map);
	collectables_check(map); 
	if(path_check(map) < 0)
		return (error_msg("path check failed"), NULL); // need to free map area, LEAK IS HERE
	
	j = 0;
	while (map->area[j])
		printf("map is %s\n", map->area[j++]);
	return (map);
}
