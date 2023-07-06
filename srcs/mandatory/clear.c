/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 22:48:34 by lboulang          #+#    #+#             */
/*   Updated: 2023/03/31 22:57:40 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
Destroy every image initialized
*/
void	ft_destroy_image(t_game *my_game, int lim_pkmn, int lim_tile)
{
	int	i;

	i = -1;
	if (lim_pkmn == -1)
		lim_pkmn = 9;
	if (lim_tile == -1)
		lim_tile = 4;
	while (++i < lim_pkmn)
	{
		if (my_game->pkmn[i])
			mlx_destroy_image(my_game->mlx, my_game->pkmn[i]);
	}
	i = -1;
	while (++i < lim_tile)
	{
		if (my_game->tile[i])
			mlx_destroy_image(my_game->mlx, my_game->tile[i]);
	}		
}

/*
Clear Window, Destroy Window, Delete Display, free mlx (was malloced at _init())
*/
void	ft_end_game(t_game *my_game, int pkms, int tiles)
{
	ft_destroy_image(my_game, pkms, tiles);
	mlx_clear_window(my_game->mlx, my_game->mlx_win);
	mlx_destroy_window(my_game->mlx, my_game->mlx_win);
	mlx_destroy_display(my_game->mlx);
	ft_free_tab(my_game->map);
	ft_free_tab(my_game->map_mint);
	free(my_game->mlx);
}
