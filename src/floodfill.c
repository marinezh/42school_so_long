/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 12:22:08 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/03/23 22:46:27 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_map *copy, int x, int y)
{
	//printf("copy collet BEFORE x is %d\n", copy->collectables);
	// printf("map size y is %d and y is %d\n", copy->size_y, y);
	// printf("player position x %d and y %d\n", copy->player_pos.x, copy->player_pos.y);
	// int i = 0 ;
	// while (i < copy->size_y)
	// {
	// 	printf(" copy map area i %s\n", copy->area[i++]);
	// }
	// printf("***************************\n");
	if (copy->area[y][x] == 'C')
	{
		copy->collectables--;
		//printf("copy collect AFTER x is %d\n", copy->collectables);
	}
		
	if (copy->area[y][x] == 'E')
		copy->exit_pos.x = -1;
	copy->area[y][x] = '1';
	if (x > 0 && copy->area[y][x - 1] != '1')
	{
		flood_fill(copy, x - 1, y);
	}
	if (x + 1 < copy->size_x && copy->area[y][x + 1] != '1')
	{
		flood_fill(copy, x + 1, y);
	}
	if (y > 0 && copy->area[y - 1][x] != '1')
	{
		flood_fill(copy, x, y - 1);
	}
	if (y + 1 < copy->size_y && copy->area[y + 1][x] != '1')
	{
		flood_fill(copy, x, y + 1);
	}
}

int	path_check(t_map *map)
{
	t_map	*copy_map;
	int		i;

	i = 0;
	copy_map = ft_calloc(1, sizeof(t_map));
	if (!copy_map)
		return (free_map(map), error_msg("memory error"), -1);
	copy_map->collectables = map->collectables;
	copy_map->size_x = map->size_x;
	copy_map->size_y = map->size_y;
	copy_map->player_pos.x = map->player_pos.x;
	copy_map->player_pos.y = map->player_pos.y;
	copy_map->exit_pos.x = map->exit_pos.x;
	printf("copy map player position x %d and y %d\n", copy_map->player_pos.x, copy_map->player_pos.y);
	copy_map->area = ft_calloc(copy_map->size_y + 1, sizeof(char *)); 
	if (!copy_map->area)
		return (free_map(map), error_msg("memory error"), -1);
	while (i < copy_map->size_y)
	{
		copy_map->area[i] = ft_strdup(map->area[i]);
		 if (!copy_map->area[i])
            return (free_map(copy_map), error_msg("memory error"), -1);
		i++;
	}
	flood_fill(copy_map, copy_map->player_pos.x, copy_map->player_pos.y);
	printf("copy collet FINAL x is %d\n", copy_map->collectables);
	if (copy_map->collectables > 0 || copy_map->exit_pos.x != -1)
		return (free_map(copy_map), error_msg("no valid path found"), -1);
	free_map(copy_map);
	return (1);
}
// if (x > 0 && copy->area[y][x - 1] != '1')
// 	{
// 		flood_fill(copy, x - 1, y);
// 	}
// 	if (x < copy->size_x && copy->area[y][x + 1] != '1')
// 	x + 1 < (int)ft_strlen(copy->area[y]) && copy->area[y][x + 1] != '1'
// 	{
// 		flood_fill(copy, x + 1, y);
// 	}
// 	if (y > 0 && copy->area[y - 1][x] != '1')
// 	{
// 		flood_fill(copy, x, y - 1);
// 	}
// 	if (y < copy->size_y && copy->area[y + 1][x] != '1')
// 	y + 1 < copy->size_y && copy->area[y + 1][x] != '1'
// 	{
// 		flood_fill(copy, x, y + 1);
// 	}