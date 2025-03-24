/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:55:37 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/03/24 16:21:35 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include <stdlib.h>
#include <stdio.h>
#include <so_long.h>

#define WIDTH 800
#define HEIGHT 600

int test(void)
{
    mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "MLX42 Test", true);
    if (!mlx)
    {
        printf("MLX42 initialization failed\n");
        return EXIT_FAILURE;
    }

    //mlx_set_background_color(mlx, 0xFF00FFFF); // Purple background
    mlx_loop(mlx);
    mlx_terminate(mlx);
    return EXIT_SUCCESS;
}

