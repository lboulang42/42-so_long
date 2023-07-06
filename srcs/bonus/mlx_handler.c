/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 20:04:16 by lboulang          #+#    #+#             */
/*   Updated: 2023/04/04 22:58:48 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/*
Only use the '0' position for pkmn xpm files (no animation for mandatory),
Get files path to Images in struct void * for pkmn and tileset
*/
void	ft_store_assets(t_game *game, char *path[36], int s)
{
	int	i;
	int	j;
	int	facing;

	i = -1;
	j = -1;
	while (++i < 9)
	{
		facing = -1;
		while (++facing < 4)
		{
			game->pkmn[i][facing] = mlx_xpm_file_to_image(game->mlx, path[++j],
					&s, &s);
			if (!game->pkmn[i][facing])
			{
				ft_error("MLX Set Image Missing / Corrupt :", path[j]);
				ft_end_game(game, j, 0);
				exit(0);
			}
		}
	}
}

void	ft_store_tile(t_game *game, char *path[4], int s)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		game->tile[i] = mlx_xpm_file_to_image(game->mlx, path[i], &s, &s);
		if (!game->tile[i])
		{
			ft_error("MLX Set Image Missing / Corrupt :", path[i]);
			ft_end_game(game, -1, i);
			exit(0);
		}
	}
}

/*
Store the paths and send in to set_tiles
*/
void	ft_get_tiles(t_game *my_game, int size)
{
	static char	*pkmn_path[36] = {
		"./assets/pkmn/1_0.xpm", "./assets/pkmn/1_1.xpm",
		"./assets/pkmn/1_2.xpm", "./assets/pkmn/2_2.xpm",
		"./assets/pkmn/2_3.xpm", "./assets/pkmn/3_0.xpm",
		"./assets/pkmn/3_1.xpm", "./assets/pkmn/3_2.xpm",
		"./assets/pkmn/3_3.xpm", "./assets/pkmn/1_3.xpm",
		"./assets/pkmn/2_0.xpm", "./assets/pkmn/2_1.xpm",
		"./assets/pkmn/4_0.xpm", "./assets/pkmn/4_1.xpm",
		"./assets/pkmn/4_2.xpm", "./assets/pkmn/4_3.xpm",
		"./assets/pkmn/5_0.xpm", "./assets/pkmn/5_1.xpm",
		"./assets/pkmn/5_2.xpm", "./assets/pkmn/5_3.xpm",
		"./assets/pkmn/6_0.xpm", "./assets/pkmn/6_1.xpm",
		"./assets/pkmn/6_2.xpm", "./assets/pkmn/6_3.xpm",
		"./assets/pkmn/7_0.xpm", "./assets/pkmn/7_1.xpm",
		"./assets/pkmn/7_2.xpm", "./assets/pkmn/7_3.xpm",
		"./assets/pkmn/8_0.xpm", "./assets/pkmn/8_1.xpm",
		"./assets/pkmn/8_2.xpm", "./assets/pkmn/8_3.xpm",
		"./assets/pkmn/9_0.xpm", "./assets/pkmn/9_1.xpm",
		"./assets/pkmn/9_2.xpm", "./assets/pkmn/9_3.xpm"};
	static char	*tile_path[4] = {
		"./assets/tileset/grass.xpm", "./assets/tileset/wall.xpm",
		"./assets/tileset/exit.xpm", "./assets/tileset/player.xpm"};

	ft_store_assets(my_game, pkmn_path, size);
	ft_store_tile(my_game, tile_path, size);
}

/*
Running through every char of map and set tile associated (static int is set)
to handle different pokemons
*/
void	ft_update_window(t_game *my_game, int moove_count)
{
	int	i;
	int	j;
	int	count_pkmn;

	i = -1;
	count_pkmn = 0;
	while (my_game->map[++i])
	{
		j = -1;
		while (my_game->map[i][++j])
		{
			if (count_pkmn >= 9)
				count_pkmn = 0;
			ft_set_tile(my_game, i, j, &count_pkmn);
		}
	}
	ft_write_move(my_game, moove_count);
}

/*
Setting up map for the game (init mlx, create window, get tiles, update window)
*/
void	ft_set_map(t_game *my_game, int size)
{
	my_game->mlx = mlx_init();
	if (!my_game->mlx)
	{
		ft_error("MLX", "MLX init failed");
		exit(0);
	}
	my_game->mlx_win = mlx_new_window(my_game->mlx, my_game->length * size,
			(my_game->width + 1) * size, "./so_long");
	if (!my_game->mlx_win)
	{
		ft_error("MLX", "MLX new_window failed");
		exit(0);
	}
	ft_get_tiles(my_game, size);
	ft_update_window(my_game, 0);
}
