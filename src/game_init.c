/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:35:39 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/03/26 13:13:25 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t	*load(t_game *game, char *path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	//(void)path;
	texture = mlx_load_png(path);
	if (!texture)
	{
		error_close_game(game);
		return NULL;	
	}
	img = mlx_texture_to_image(game->mlx, texture);
	if (!img)
	{
		mlx_delete_texture(texture);
		error_close_game(game); // handle image conversion failure
		return (NULL);
	}
	mlx_delete_texture(texture);
	return (img);
}

// void	init_images(t_game *game)
// {
// 	game->mlx = NULL;
// 	game->img_wall = NULL;
// 	game->img_coll = NULL;
// 	game->img_exit = NULL;
// 	game->img_floor = NULL;
// 	game->img_player = NULL;
// 	game->img_enemy = NULL;
// }

// int	image_init(t_game *game)
// {
// 	game->img_wall = load(game, WALL);
// 	game->img_coll = load(game, COL1);
// 	game->img_exit = load(game, EXIT);
// 	game->img_floor = load(game, FLOOR);
// 	game->img_player = load(game, PLAYER);
// 	game->img_enemy = load(game, ENEMY);
// 	if (!game->img_wall || !game->img_coll || !game->img_exit
// 		|| !game->img_floor || !game->img_player || !game->img_enemy)
// 	{
// 		free_images(game);
// 		return (-1);
// 	}
// 	return (0);
// }
int	image_init(t_game *game)
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
	//init_images(game);
	if (image_init(game) < 0)
		return (-1); // error msg image loading fail;
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
