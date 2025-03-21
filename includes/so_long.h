/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:20:43 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/03/21 18:22:27 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H


# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_point
{
	int x;
	int y;
} t_point;

typedef struct s_map
{
	char	**area;
	int		size_x;
	int		size_y;
	int		collectables;
	t_point	player_pos;
	t_point	exit_pos;
} t_map;

t_map *parsing_args(char *filename);
void error_msg(char *msg);

#endif
