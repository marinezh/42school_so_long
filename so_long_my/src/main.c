/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:59:55 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/03/27 19:00:27 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Written by Bruh

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "MLX42/MLX42.h"
#include "so_long.h"
#define WIDTH 800
#define HEIGHT 600


void my_keyhook(mlx_key_data_t keydata, void* param)
{
	// If we PRESS the 'J' key, print "Hello".
	if (keydata.key == MLX_KEY_J && keydata.action == MLX_PRESS)
		puts("Hello ");

	// If we RELEASE the 'K' key, print "World".
	if (keydata.key == MLX_KEY_K && keydata.action == MLX_RELEASE)
		puts("World");

	// If we HOLD the 'L' key, print "!".
	if (keydata.key == MLX_KEY_L && keydata.action == MLX_REPEAT)
		puts("!");
}
void	click(mlx_key_data_t keydata, void *parametr)
{
	// t_game	*game;
	// int		x;
	// int		y;

	// game = (t_game *)parametr;
	// x = game->map->player_pos.x;
	// y = game->map->player_pos.y;
	// if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	// 	close_game(game);
	// if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
	// 	handle_move(game, x + 1, y);
	// if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
	// 	handle_move(game, x - 1, y);
	// if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
	// 	handle_move(game, x, y + 1);
	// if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
	// 	handle_move(game, x, y - 1);

    // If we PRESS the 'J' key, print "Hello".
	if (keydata.key == MLX_KEY_J && keydata.action == MLX_PRESS)
		puts("Hello ");

	// If we RELEASE the 'K' key, print "World".
	if (keydata.key == MLX_KEY_K && keydata.action == MLX_RELEASE)
		puts("World");

	// If we HOLD the 'L' key, print "!".
	if (keydata.key == MLX_KEY_L && keydata.action == MLX_REPEAT)
		puts("!");
}
void	close_game(void *parametr)
{
	t_game	*game;

	game = (t_game *)parametr;
	if (game->mlx)
		mlx_terminate(game->mlx);
	if (game->map)
		free_map(game->map);
	ft_putendl_fd("Bye Bye", 1);
	exit(0);
}

// Exit the program as failure.
static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

// Print the window width and height.
// static void ft_hook(void* param)
// {
// 	const mlx_t* mlx = param;

// 	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
// }

int32_t	main(int ac, char **av)
{
    (void)ac;
    (void)av;
	// MLX allows you to define its core behaviour before startup.
	//mlx_set_setting(MLX_MAXIMIZED, true);
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "42Balls", false);
	if (!mlx)
		ft_error();

	/* Do stuff */

	// Create and display the image.
	mlx_image_t* img = mlx_new_image(mlx, 256, 256);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();

	// Even after the image is being displayed, we can still modify the buffer.
	mlx_put_pixel(img, 0, 0, 0xFF000FFF);

	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	//mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
    //mlx_key_hook();
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
// int	test(int ac, char **av)
// {
// 	t_map	*map;
// 	t_game	game;

// 	if (ac != 2)
// 		return (1);
// 	map = parsing_args(av[1]);
// 	if (!map)
// 		return (1);
// 	game.map = map;
// 	if (game_init(&game) == -1)
// 		error_close_game(&game);
// 	mlx_close_hook(game.mlx, close_game, &game);
// 	mlx_key_hook(game.mlx, click, &game);
// 	mlx_loop(game.mlx);
// }