/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pathfind.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 03:38:59 by lboulang          #+#    #+#             */
/*   Updated: 2023/03/08 03:14:38 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
/*
check count of C, E and P in map (only 1 P, only 1 E, 1 or more C accepted)
Return number of collectibles
On error return -1
*/
int	ft_count_assets(int P_count, int E_count, int C_count)
{
	if (!P_count)
		return (ft_error("Map (Assets)", "No 'P' in map"), -1);
	if (!C_count)
		return (ft_error("Map (Assets)", "No 'C' in map"), -1);
	if (!E_count)
		return (ft_error("Map (Assets)", "No 'E' in map"), -1);
	if (P_count != 1)
		return (ft_error("Map (Assets)", "Too many 'P' in map"), -1);
	if (E_count != 1)
		return (ft_error("Map (Assets)", "Too many 'E' in map"), -1);
	return (C_count);
}

/*
Recursive function
Found Collec as static (set as 0 at start to avoid uninitialized)
If [x][y] is collec, increment
Set visited index as 'Z' (to know where we already checked)
Check every index (up, down, left, right) if it havn't been checked or is wall
return collectibles found
*/
int	ft_pathfind(char **map, int x, int y)
{
	static int	found_collectibles;

	if (!found_collectibles)
		found_collectibles = 0;
	if (map[x][y] == 'C')
		found_collectibles++;
	map[x][y] = 'Z';
	if (map[x][y +1] != '1' && map[x][y +1] != 'Z')
		ft_pathfind(map, x, y +1);
	if (map[x][y -1] != '1' && map[x][y -1] != 'Z')
		ft_pathfind(map, x, y -1);
	if (map[x +1][y] != '1' && map[x +1][y] != 'Z')
		ft_pathfind(map, x +1, y);
	if (map[x -1][y] != '1' && map[x -1][y] != 'Z')
		ft_pathfind(map, x -1, y);
	return (found_collectibles);
}
