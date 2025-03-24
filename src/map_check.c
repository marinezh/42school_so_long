/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 18:44:35 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/03/24 18:05:42 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	symbols_check(t_map *map)
{
	int		x;
	int		y;
	char	c;

	x = 0;
	while (map->area[x])
	{
		y = 0;
		while (map->area[x][y])
		{
			c = map->area[x][y];
			if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P')
				return (error_msg("wrong symbol found"), -1);
			y++;
		}
		x++;
	}
	return (1);
}

int	player_check(t_map *map)
{
	int	row;
	int	col;
	int	player_count;

	row = 0;
	player_count = 0;
	while (map->area[row])
	{
		col = 0;
		while (map->area[row][col++])
		{
			if (map->area[row][col] == 'P')
			{
				player_count++;
				map->player_pos.x = col;
				map->player_pos.y = row;
			}
		}
		row++;
	}
	if (player_count != 1)
		return (error_msg("There must be exactly one player (P)"), -1);
	return (1);
}
int	exit_check(t_map *map)
{
	int	row;
	int	col;
	int	exit_count;

	row = 0;
	exit_count = 0;
	while (map->area[row])
	{
		col = 0;
		while (map->area[row][col++])
		{
			if (map->area[row][col] == 'E')
			{
				exit_count++;
				map->exit_pos.x = col;
				map->exit_pos.y = row;
			}
		}
		row++;
	}
	if (exit_count != 1)
		return (error_msg("There must be exactly one exit (E)"), -1);
	return (1);
}
int	collectables_check(t_map *map)
{
	int	row;
	int	col;
	int	collectables_count;

	row = 0;
	collectables_count = 0;
	while (map->area[row])
	{
		col = 0;
		while (map->area[row][col])
		{
			if (map->area[row][col] == 'C')
				collectables_count++;
			col++;
		}
		row++;
	}
	if (collectables_count < 1)
		return (error_msg("There must be at least 1 colectable (C)"), -1);
	map->collectables = collectables_count;
	// printf("collectable-2 %d\n", map->collectables);
	return (1);
}

int	borders_check(t_map *map)
{
	int row;
	int col;

	col = 0;
	while (map->area[0][col])
	{
		if (map->area[0][col] != '1')
			return (error_msg("Top border is not closed"), -1);
		col++;
	}
	col = 0;
	while (map->area[map->size_y - 1][col])
	{
		if (map->area[map->size_y - 1][col] != '1')
			return (error_msg("Bottom border is not closed"), 1);
		col++;
	}
	row = 0;
	while (map->area[row])
	{
		if (map->area[row][0] != '1' || map->area[row][map->size_x - 1] != '1')
			return (error_msg("Side borders are not closed"), -1);
		row++;
	}
	return (1);
}