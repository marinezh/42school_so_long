/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:46:11 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/03/21 18:16:29 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
# include "../includes/libft.h"

int main(int ac, char **av)
{
    t_map *map;
   
    if(ac != 2)
        return (1);
   map = parsing_args(av[1]);
   if(!map)
    return (1);
}
