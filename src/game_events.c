/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:27:26 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/03/24 18:44:46 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void click(mlx_key_data_t keydata, void *parametr)
{
    t_game *game;
    game = (t_game *)parametr;

    if(keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
        close_game(game);
    if(keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
        close_game(game);
    if(keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
        close_game(game);
    if(keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
        close_game(game);
    if(keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
        close_game(game);
}

// write a function which will taking new coordinates (games, nex x, nex y) , and check
// what do we have on the new coordinates...

// if this is colectables = col num - 1
// if wall - return
// if exit - check number of ccol if 0 = > write some msg and close_game(),
//if i step to 0 , render hero again. 