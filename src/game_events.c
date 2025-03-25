/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:27:26 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/03/25 15:40:35 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collect_collectables(t_game *game, int new_x, int new_y)
{
	int	i;

	i = 0;
	if (game->map->area[new_y][new_x] == 'C')
	{
		game->map->area[new_y][new_x] = '0';
		game->to_collect--;
		while (i < game->map->collectables)
		{
			if (game->img_collect->instances[i].x == new_x * TS
				&& game->img_collect->instances[i].y == new_y * TS)
				game->img_collect->instances[i].enabled = false;
			i++;
		}
		game->map->area[new_y][new_x] = '0';
	}
}

void	handle_move(t_game *game, int new_x, int new_y)
{
	if (game->map->area[new_y][new_x] == '1')
		return ;
	game->count_step++;
	ft_putstr_fd("you did: ", 1);
	ft_putnbr_fd(game->count_step, 1);
	ft_putstr_fd("\n", 1);
	game->map->player_pos.x = new_x;
	game->map->player_pos.y = new_y;
	game->img_player->instances->x = new_x * TS; // drawing new pos of hero
	game->img_player->instances->y = new_y * TS;
	printf("number of collectables %d\n", game->to_collect);
	if (game->map->area[new_y][new_x] == 'E' && game->to_collect <= 0)
	{
		ft_putstr_fd("you win\n", 1);
		close_game(game);
	}
	if (game->map->area[new_y][new_x] == 'M')
	{
		ft_putstr_fd("you have been eaten\n", 1);
		close_game(game);
	}
	collect_collectables(game, new_x, new_y);
}

void	click(mlx_key_data_t keydata, void *parametr)
{
	t_game	*game;
	int		x;
	int		y;

	game = (t_game *)parametr;
	x = game->map->player_pos.x;
	y = game->map->player_pos.y;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		close_game(game);
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		handle_move(game, x + 1, y);
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		handle_move(game, x - 1, y);
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		handle_move(game, x, y + 1);
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		handle_move(game, x, y - 1);
}
