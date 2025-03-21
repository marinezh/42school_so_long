/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:44:47 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/03/21 19:39:24 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/libft.h"

int size_check(t_map *map)
{
	int i;
	unsigned int size_x = map->size_x;
	i = 0;
	map->size_x = ft_strlen(map->area[0]);
	while(map->area[i])
	{
		if (ft_strlen(map->area[i]) != size_x)
			return (error_msg("map is not req"), -1);
		i++;
	}
	return (1);
}

int map_lines(char *filename)
{
	int fd;
	int count;
	char *line;

	count = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (error_msg("file openning error"), 0);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		count++;
		free(line);
	}
	close(fd);
	return count;
}

int read_map(t_map *map, char *filename, int size)
{
	int fd;
	char *line;
	int i;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (error_msg("file openning error"), -1);
	while (i < size)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		map->area[i] = ft_strdup(line);
		free(line);
		i++;
	}
	map->area[i] = NULL;
	return 1;
}

int name_validation(char *filename)
{
	char *resolution;
	int len;

	len = ft_strlen(filename);
	if (len < 5)
		return (-1);
	resolution = ft_strchr(filename, '.');
	if (ft_strncmp(resolution, ".ber", len) != 0)
		return (-1);
	return (1);
}

t_map *parsing_args(char *filename)
{
	t_map *map;

	if (name_validation(filename) < 0)
		return (error_msg("wrong file name"), NULL);
	
	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		return NULL;
	map->size_y = map_lines(filename);
	if (map->size_y < 1)
		return (error_msg("error file reading"), NULL);
	printf("lines %d\n", map->size_y);
	map->area = ft_calloc(map->size_y + 1, sizeof(char *));
	if(!map->area)
		return (free(map), NULL);
	read_map(map, filename, map->size_y + 1);
	if (size_check(map) < 0)
		return (free(map), NULL); // need to free map area, LEAK IS HERE
	// symbols_check(); // TO DO 0 1 C P E
	// players_check(); // TO DO should be 1;
	// exit_check(); // TO DO should be 1;
	// col_check(); // should be more than 0
	// map->area[0] should be only 1
	// map->area[map->size_y] should be only 1
	// map-area[i][0] == 1, map-area[i][map->size_x - 1] == 1
	// flood_fill -> P all C and E are reachable
	int j = 0;
	while (map->area[j])
		printf("map is %s", map->area[j++]);
	return map;
}
