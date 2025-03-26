/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 22:18:57 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/03/26 13:31:11 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	put_image_safe(t_game *game, mlx_image_t *img, int x, int y)
{
	if (mlx_image_to_window(game->mlx, img, x, y) < 0)
	{
		error_close_game(game);
		return (-1);
	}
	return (0);
}

int	render_background(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map->size_y)
	{
		x = 0;
		while (x < game->map->size_x)
		{
			if (game->map->area[y][x] == '1')
				if (put_image_safe(game, game->img_wall, x * TS, y * TS) < 0)
					return (-1);
			if (game->map->area[y][x] != '1')
				if (put_image_safe(game, game->img_floor, x * TS, y * TS) < 0)
					return (-1);
			x++;
		}
		y++;
	}
	return (0);
}

int	render_collectables(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map->size_y)
	{
		x = 0;
		while (x < game->map->size_x)
		{
			if (game->map->area[y][x] == 'C')
				if (put_image_safe(game, game->img_coll, x * TS, y * TS) < 0)
					return (-1);
			x++;
		}
		y++;
	}
	return (0);
}

int	render_enemies(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map->size_y)
	{
		x = 0;
		while (x < game->map->size_x)
		{
			if (game->map->area[y][x] == 'M')
				if (put_image_safe(game, game->img_enemy, x * TS, y * TS) < 0)
					return (-1);
			x++;
		}
		y++;
	}
	return (0);
}
