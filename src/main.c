/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:46:11 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/03/24 18:29:26 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_map	*map;
	t_game	game;

	if (ac != 2)
		return (1);
	map = parsing_args(av[1]);
	if (!map)
		return (1);
	printf("EXIT x -  %d, y - %d\n", map->exit_pos.x , map->exit_pos.y);
	game.map = map;
	game_init(&game);
	mlx_close_hook(game.mlx, close_game, &game);
	mlx_key_hook(game.mlx, click, &game);
	mlx_loop(game.mlx);
	
	
	return (0);
}
