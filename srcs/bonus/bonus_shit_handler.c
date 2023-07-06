/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_shit_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 03:15:41 by lboulang          #+#    #+#             */
/*   Updated: 2023/03/08 05:33:31 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_put_pkmn(t_game *my_game, int count_pkmn, int i, int j)
{
	static int	facing;

	if (!facing || facing > 3)
		facing = 0;
	mlx_put_image_to_window(my_game->mlx, my_game->mlx_win,
		my_game->pkmn[count_pkmn][facing], j * 64, i * 64);
	facing++;
	return (0);
}

int	ft_write_move(t_game *my_game, int moove_count)
{
	char	*tmp1;
	char	*tmp2;
	char	*prev_move;
	char	*curr_move;

	if (moove_count != 0)
	{
		tmp1 = ft_itoa(moove_count - 1);
		tmp2 = ft_itoa(moove_count);
		prev_move = ft_strjoin("Movement counter : ", tmp1);
		curr_move = ft_strjoin("Movement counter : ", tmp2);
		mlx_string_put(my_game ->mlx, my_game ->mlx_win, 0, my_game->width
			* 64 + 32, 0x000000, prev_move);
		mlx_string_put(my_game ->mlx, my_game ->mlx_win, 0, my_game->width
			* 64 + 32, 0xFFFFFF, curr_move);
		free(prev_move);
		free(curr_move);
		free(tmp1);
		free(tmp2);
	}
	return (0);
}
