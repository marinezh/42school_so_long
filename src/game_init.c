/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:35:39 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/03/26 14:31:32 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static mlx_image_t	*load(t_game *game, char *path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png(path);
	if (!texture)
	{
		error_close_game(game);
		return (NULL);
	}
	img = mlx_texture_to_image(game->mlx, texture);
	if (!img)
	{
		mlx_delete_texture(texture);
		error_close_game(game);
		return (NULL);
	}
	mlx_delete_texture(texture);
	return (img);
}

static int	image_init(t_game *game)
{
	game->img_wall = load(game, WALL);
	if (!game->img_wall)
		return (-1);
	game->img_coll = load(game, COL1);
	if (!game->img_coll)
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
	game->img_enemy = load(game, ENEMY);
	if (!game->img_enemy)
		return (-1);
	return (0);
}

int	game_init(t_game *game)
{
	game->mlx = mlx_init(TS * game->map->size_x, TS * game->map->size_y,
			"So_long", false);
	if (!game->mlx)
	{
		error_close_game(game);
		return (-1);
	}
	if (image_init(game) < 0)
		return (-1);
	game->count_step = 0;
	game->to_collect = game->map->collectables;
	if (render_background(game) == -1)
		error_close_game(game);
	if (render_collectables(game) == -1)
		error_close_game(game);
	if (render_enemies(game) == -1)
		error_close_game(game);
	put_image_safe(game, game->img_exit, game->map->exit_pos.x * TS,
		game->map->exit_pos.y * TS);
	put_image_safe(game, game->img_player, game->map->player_pos.x * TS,
		game->map->player_pos.y * TS);
	return (0);
}
