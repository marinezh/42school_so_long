/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:35:39 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/03/24 18:19:27 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t	*load(t_game *game, char *path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png(path);
	if (!texture)
		return (NULL); // nedd to handle exit
	img = mlx_texture_to_image(game->mlx, texture);
	if (!img)
		return (mlx_delete_texture(texture), NULL);
	mlx_delete_texture(texture);
	return (img);
}

int	image_init(t_game *game)
{
	game->img_wall = load(game, WALL);
	if (!game->img_wall)
		return (-1);
	game->img_collect = load(game, COL1);
	if (!game->img_collect)
		return (-1);
	game->img_exit = load(game, EXIT);
	if (!game->img_exit)
		return (-1);
	game->img_floor = load(game, FLOOR);
	if (!game->img_floor)
		return (-1);
	game->img_player = load(game, PLAYER);
	if (!game->img_player)
		return (-1);
	return (0);
}
void	render_background(t_game *game)
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
				mlx_image_to_window(game->mlx, game->img_wall, x * 64, y * 64);
			if (game->map->area[y][x] != '1')
				mlx_image_to_window(game->mlx, game->img_floor, x * 64, y * 64);
			x++;
		}
		y++;
	}
}
void	render_collectables(t_game *game)
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
				mlx_image_to_window(game->mlx, game->img_collect, x * 64, y
					* 64);
			x++;
		}
		y++;
	}
}
int	game_init(t_game *game)
{
	game->mlx = mlx_init(64 * game->map->size_x, 64 * game->map->size_y,
			"So_long Test", true);
	if (!game->mlx)
	{
		printf("MLX42 initialization failed\n");
		return (-1);
	}
	if (image_init(game) < 0)
		return (-1); // error msg image loading fail;
	render_background(game);
	render_collectables(game);
	mlx_image_to_window(game->mlx, game->img_player, game->map->player_pos.x
		* 64, game->map->player_pos.y * 64);
	mlx_image_to_window(game->mlx, game->img_exit, game->map->exit_pos.x * 64,
		game->map->exit_pos.y * 64);
	return (1);
}