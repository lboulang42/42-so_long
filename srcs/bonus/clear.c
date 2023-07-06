/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 22:51:00 by lboulang          #+#    #+#             */
/*   Updated: 2023/04/03 18:59:48 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_destroy_image(t_game *my_game, int lim_pkmn, int lim_tile)
{
	int	i;
	int	j;
	int	facing;

	i = -1;
	j = 0;
	facing = 0;
	while (++i < lim_pkmn)
	{
		mlx_destroy_image(my_game->mlx, my_game->pkmn[j][facing]);
		facing++;
		if (facing == 4)
		{
			facing = 0;
			j++;
		}
	}
	i = -1;
	while (++i < lim_tile)
	{
		if (my_game->tile[i])
			mlx_destroy_image(my_game->mlx, my_game->tile[i]);
	}
}

/*Destroy every image initialized
Clear Window, Destroy Window, Delete Display, free mlx (was malloced at _init())
*/
void	ft_end_game(t_game *my_game, int pkms, int tiles)
{
	if (pkms == -1)
		pkms = 36;
	if (tiles == -1)
		tiles = 4;
	ft_destroy_image(my_game, pkms, tiles);
	mlx_clear_window(my_game->mlx, my_game->mlx_win);
	mlx_destroy_window(my_game->mlx, my_game->mlx_win);
	mlx_destroy_display(my_game->mlx);
	ft_free_tab(my_game->map);
	ft_free_tab(my_game->map_mint);
	free(my_game->mlx);
}
