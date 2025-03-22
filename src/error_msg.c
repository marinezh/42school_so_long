/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:20:09 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/03/22 16:17:29 by mzhivoto         ###   ########.fr       */
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