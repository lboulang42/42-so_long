/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 20:09:15 by lboulang          #+#    #+#             */
/*   Updated: 2023/03/07 03:39:58 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
check file extension (exclude less than 4 char names (file named '.ber' 
could work))
compare last 4 char with static char *".ber"
*/
int	ft_check_ber(char	*str)
{
	size_t		i;
	size_t		j;
	static char	*file = {".ber"};

	if (ft_strlen(str) < 5)
		return (0);
	i = ft_strlen(str) - 4;
	j = 0;
	while (str[i + j])
	{
		if (str[i + j] != file[j])
			return (0);
		j++;
	}
	return (1);
}

/*
set first row len as reference
if another line have a different len : map is not a square
*/
int	ft_check_square(char **map)
{
	int		i;
	size_t	row_len;

	i = 0;
	row_len = ft_strlen(map[0]);
	while (map[i])
	{
		if (row_len != ft_strlen(map[i]))
			return (ft_error("Map", "Map Is Not A Square"), 0);
		i++;
	}
	return (row_len);
}

/*
check first and last line full of 1
for other lines check index 0 && index len -1
if not there is a wall missing
*/
int	ft_check_walls(char **map, int row_count, int row_len)
{
	int	i;
	int	j;

	i = 0;
	while (i < row_count)
	{
		if (i == 0 || i == row_count -1)
		{
			j = -1;
			while (++j < row_len -1)
				if (map[i][j] != '1')
					return (ft_error("Map", "Map Is Not Closed By Walls"), 0);
		}
		if (map[i][0] != '1')
			return (ft_error("Map", "Map Is Not Closed By Walls"), 0);
		if (map[i][row_len -1] != '1')
			return (ft_error("Map", "Map Is Not Closed By Walls"), 0);
		i++;
	}
	return (i);
}

/*
Check every char in map, 01CEP only allowed (else return -1);
Set Coo for start & exit
Send the number of CEP to ft_count_assets
*/
int	ft_check_charset(t_game *my_game, int c, int e, int p)
{
	int	i;
	int	j;

	i = 0;
	while (my_game->map[i])
	{
		j = 0;
		while (my_game->map[i][j])
		{
			if (ft_find_char("01CEP", my_game->map[i][j]) == -1)
				return (ft_error("Map (Charset)", "Wrong char in map"), -1);
			if (my_game->map[i][j] == 'P')
				p += ft_set_coord(&my_game->start, i, j);
			if (my_game->map[i][j] == 'C')
				c++;
			if (my_game->map[i][j] == 'E')
				e += ft_set_coord(&my_game->exit, i, j);
			j++;
		}
		i++;
	}
	return (ft_count_assets(p, e, c));
}

/*
Check Map is a square, set map length (required after in the process)
Check Map is closed by walls, set map width (required after in the process)
Check Map Charset, set map count of collectibles (required after)
*/
int	ft_check_map(t_game *my_game)
{
	char	**map_copy;
	int		array_size;

	my_game->length = ft_check_square(my_game->map);
	if (!my_game->length)
		return (0);
	array_size = ft_array_size(my_game->map);
	my_game->width = ft_check_walls(my_game->map, array_size, my_game->length);
	if (!my_game->width)
		return (0);
	my_game->collectibles = ft_check_charset(my_game, 0, 0, 0);
	if (my_game->collectibles == -1)
		return (0);
	map_copy = ft_array_cpy(my_game->map);
	if (!map_copy)
		return (0);
	if (ft_pathfind(map_copy, my_game->start.x, my_game->start.y)
		!= my_game->collectibles)
		return (ft_error("Pathfinding", "Some Collectibles Not Reachables"), 0);
	if (map_copy[my_game->exit.x][my_game->exit.y] != 'Z')
		return (ft_error("Pathfinding", "Exit Not Reachable"), 0);
	return (ft_free_tab(map_copy), 1);
}
