/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:20:43 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/03/24 18:38:36 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define TS 64
# define WALL "./textures/wall5.png"
# define FLOOR "./textures/back.png"
# define COL1 "./textures/collect2.png"
# define EXIT "./textures/exit.png"
# define PLAYER "./textures/bee3.png"

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct s_map
{
	char		**area;
	int			size_x;
	int			size_y;
	int			collectables;
	t_point		player_pos;
	t_point		exit_pos;
}				t_map;

typedef struct s_game
{
	mlx_t		*mlx;
	t_map		*map;
	mlx_image_t	*img_wall;
	mlx_image_t	*img_floor;
	mlx_image_t	*img_collect;
	mlx_image_t	*img_exit;
	mlx_image_t	*img_player;
	// Add map, player position, etc.
}				t_game;

t_map			*parsing_args(char *filename);
void			error_msg(char *msg);
void			free_map(t_map *map);
int				test(void);

int				game_init(t_game *game);
void			close_game(void *parametr);

int				symbols_check(t_map *map);
int				player_check(t_map *map);
int				exit_check(t_map *map);
int				collectables_check(t_map *map);
int				borders_check(t_map *map);

int				path_check(t_map *map);
void			click(mlx_key_data_t keydata, void *parametr);

#endif
