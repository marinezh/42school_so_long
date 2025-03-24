/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:20:09 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/03/24 18:26:37 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_msg(char *msg)
{
	ft_putendl_fd(msg, 2);
}
void	free_map(t_map *map)
{
	int i;

	i = 0;
	if (!map)
		return ;
	if (map->area)
	{
		while (map->area[i])
		{
			free(map->area[i]);
			i++;
		}
		free(map->area);
	}
	free(map);
}
// mlx_img_fail()

void close_game(void *parametr)
{
	t_game *game;
	game = (t_game *)parametr;
	if(game->mlx)
		mlx_terminate(game->mlx);
	if(game->map)
		free_map(game->map);
	ft_putendl_fd("Bye Bye", 1);
	exit(0);
}