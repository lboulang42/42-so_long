/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 02:47:59 by lboulang          #+#    #+#             */
/*   Updated: 2023/03/08 02:56:54 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
Avoid Mooving outside the map / in a wall
If Gonna Walk on a collectible, increment gotcha
Set Previous Position as '0'
Update Current Position
Set Current Position As 'P'.
Update Window
Check if win condition
*/
int	ft_move(t_game *my_game, int x, int y)
{
	static int	moove_count;

	if (!moove_count)
		moove_count = 0;
	if (!my_game->map[my_game->start.x + x][my_game->start.y + y])
		return (0);
	if (my_game->map[my_game->start.x + x][my_game->start.y + y] == '1')
		return (0);
	moove_count++;
	ft_printf("You Mooved %d times !\n", moove_count);
	if (my_game->map[my_game->start.x + x][my_game->start.y + y] == 'C')
		my_game->gotcha++;
	my_game->map[my_game->start.x][my_game->start.y] = '0';
	ft_set_coord(&my_game->start, my_game->start.x + x, my_game->start.y + y);
	my_game->map[my_game->start.x][my_game->start.y] = 'P';
	ft_update_window(my_game);
	ft_check_win(my_game);
	return (0);
}

/*
Handle Key Press
*/
int	ft_keypress(int signal, t_game *my_game)
{
	if (signal == W)
		ft_move(my_game, -1, 0);
	if (signal == A)
		ft_move(my_game, 0, -1);
	if (signal == S)
		ft_move(my_game, 1, 0);
	if (signal == D)
		ft_move(my_game, 0, 1);
	if (signal == ESC)
		ft_close(my_game);
	return (0);
}
