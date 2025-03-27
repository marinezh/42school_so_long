/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 12:22:08 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/03/26 14:45:19 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	flood_fill(t_map *copy, int x, int y)
{
	if (copy->area[y][x] == 'C')
		copy->collectables--;
	if (copy->area[y][x] == 'E')
		copy->exit_pos.x = -1;
	copy->area[y][x] = '1';
	if (x > 0 && copy->area[y][x - 1] != '1' && copy->area[y][x - 1] != 'M')
		flood_fill(copy, x - 1, y);
	if (x + 1 < copy->size_x && copy->area[y][x + 1] != '1' &&
		copy->area[y][x + 1] != 'M')
		flood_fill(copy, x + 1, y);
	if (y > 0 && copy->area[y - 1][x] != '1' && copy->area[y - 1][x] != 'M')
		flood_fill(copy, x, y - 1);
	if (y + 1 < copy->size_y && copy->area[y + 1][x] != '1' &&
		copy->area[y + 1][x] != 'M')
		flood_fill(copy, x, y + 1);
}

static void	map_copying(t_map *map, t_map *copy_map)
{
	copy_map->collectables = map->collectables;
	copy_map->size_x = map->size_x;
	copy_map->size_y = map->size_y;
	copy_map->player_pos.x = map->player_pos.x;
	copy_map->player_pos.y = map->player_pos.y;
	copy_map->exit_pos.x = map->exit_pos.x;
	copy_map->enemy = map->enemy;
}

int	path_check(t_map *map)
{
	t_map	*copy_map;
	int		i;

	i = 0;
	copy_map = ft_calloc(1, sizeof(t_map));
	if (!copy_map)
		return (free_map(map), error_msg("memory error"), -1);
	map_copying(map, copy_map);
	copy_map->area = ft_calloc(copy_map->size_y + 1, sizeof(char *));
	if (!copy_map->area)
		return (free_map(copy_map), error_msg("memory error"), -1);
	while (i < copy_map->size_y)
	{
		copy_map->area[i] = ft_strdup(map->area[i]);
		if (!copy_map->area[i])
			return (free_map(copy_map), error_msg("memory error"), -1);
		i++;
	}
	flood_fill(copy_map, copy_map->player_pos.x, copy_map->player_pos.y);
	if (copy_map->collectables > 0 || copy_map->exit_pos.x != -1)
		return (free_map(copy_map), error_msg("Error: no valid path"), -1);
	free_map(copy_map);
	return (1);
}
