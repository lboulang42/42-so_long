/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 03:46:19 by lboulang          #+#    #+#             */
/*   Updated: 2023/03/31 18:17:00 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
Hide Exit till every pokemon have been catched
*/
void	ft_handle_exit(t_game *my_game, int i, int j, int size)
{
	if (my_game->gotcha != my_game->collectibles)
		mlx_put_image_to_window(my_game->mlx, my_game->mlx_win,
			my_game->tile[0], j * size, i * size);
	else
		mlx_put_image_to_window(my_game->mlx, my_game->mlx_win,
			my_game->tile[2], j * size, i * size);
}

/*
Put Image to window
*/
void	ft_set_tile(t_game *my_game, int i, int j, int *count_pkmn)
{
	if (my_game->map[i][j] == '0')
		mlx_put_image_to_window(my_game->mlx, my_game->mlx_win,
			my_game->tile[0], j * 64, i * 64);
	if (my_game->map[i][j] == '1')
		mlx_put_image_to_window(my_game->mlx, my_game->mlx_win,
			my_game->tile[1], j * 64, i * 64);
	if (my_game->map[i][j] == 'P')
		mlx_put_image_to_window(my_game->mlx, my_game->mlx_win,
			my_game->tile[3], j * 64, i * 64);
	if (my_game->map_mint[i][j] == 'C')
	{
		if (my_game->map[i][j] == 'C')
			mlx_put_image_to_window(my_game->mlx, my_game->mlx_win,
				my_game->pkmn[*count_pkmn], j * 64, i * 64);
		*count_pkmn += 1;
	}
	if (my_game->exit.x == i && my_game->exit.y == j)
	{
		if (my_game->map[i][j] != 'P')
			ft_handle_exit(my_game, i, j, 64);
	}
}

/*
Called when player click on the cross / tap esc.
*/
int	ft_close(t_game *my_game)
{
	ft_error("MLX CLOSED", "You Closed The Window.");
	if (my_game->gotcha == my_game->collectibles)
		ft_printf("You Catched Every Pokemon :) !\n");
	else
		ft_printf("You Missed %d Pokemon :( !\n",
			my_game->collectibles - my_game->gotcha);
	if (my_game->start.x == my_game->exit.x
		&& my_game->start.y == my_game->exit.y)
		ft_printf("Sortie found, WIN :) !\n");
	else
		ft_printf("Sortie not found, LOOSE :( !\n");
	mlx_loop_end(my_game->mlx);
	return (0);
}

/*
Check If Every Pokemon Have Been Catched
Check If position is exit
*/
int	ft_check_win(t_game *my_game)
{
	if (my_game->gotcha != my_game->collectibles)
		return (0);
	if (my_game->start.x != my_game->exit.x)
		return (0);
	if (my_game->start.y != my_game->exit.y)
		return (0);
	ft_printf("You Catched Every Pokemon And Find The Exit !!\nYou Won !\n");
	mlx_loop_end(my_game->mlx);
	return (1);
}

/*
Set Collected (gotcha) as 0;
*/
int	ft_play(t_game *my_game)
{
	my_game->gotcha = 0;
	ft_set_map(my_game, 64);
	mlx_hook(my_game->mlx_win, KeyPress, KeyPressMask, &ft_keypress, my_game);
	mlx_hook(my_game->mlx_win, 17, (1L << 17), &ft_close, my_game);
	mlx_loop(my_game->mlx);
	ft_end_game(my_game, -1, -1);
	return (0);
}
