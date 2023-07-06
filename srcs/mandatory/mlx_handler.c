/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 20:04:16 by lboulang          #+#    #+#             */
/*   Updated: 2023/04/03 18:10:01 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Only use the '0' position for pkmn xpm files (no animation for mandatory),
Get files path to Images in struct void * for pkmn and tileset*/
void	ft_store_tile(t_game *game, char *pth_p[9], char *pth_t[4], int s)
{
	int	i;

	i = -1;
	while (++i < 9)
	{
		game->pkmn[i] = mlx_xpm_file_to_image(game->mlx, pth_p[i], &s, &s);
		if (!game->pkmn[i])
		{
			ft_error("MLX Set Image Missing / Corrupt :", pth_p[i]);
			ft_end_game(game, i, 0);
			exit(0);
		}
	}
	i = -1;
	while (++i < 4)
	{
		game->tile[i] = mlx_xpm_file_to_image(game->mlx, pth_t[i], &s, &s);
		if (!game->tile[i])
		{
			ft_error("MLX Set Image Missing / Corrupt :", pth_t[i]);
			ft_end_game(game, -1, i);
			exit(0);
		}
	}
}

int	ft_check_image_path(char *path[9])
{
	int	i;
	int	fd;

	i = -1;
	while (path[++i])
	{
		fd = open(path[i], O_RDONLY);
		if (fd == -1)
			return (0);
	}
	return (1);
}

/*
Store the paths and send in to set_tiles
*/
void	ft_get_tiles(t_game *my_game, int size)
{
	static char	*pkmn_path[9] = {
		"./assets/pkmn/1_0.xpm", "./assets/pkmn/2_0.xpm",
		"./assets/pkmn/3_0.xpm", "./assets/pkmn/4_0.xpm",
		"./assets/pkmn/5_0.xpm", "./assets/pkmn/6_0.xpm",
		"./assets/pkmn/7_0.xpm", "./assets/pkmn/8_0.xpm",
		"./assets/pkmn/9_0.xpm"
	};
	static char	*tile_path[4] = {
		"./assets/tileset/grass.xpm", "./assets/tileset/wall.xpm",
		"./assets/tileset/exit.xpm", "./assets/tileset/player.xpm"
	};

	ft_store_tile(my_game, pkmn_path, tile_path, size);
}

/*
Running through every char of map and set tile associated (static int is set)
to handle different pokemons
*/
void	ft_update_window(t_game *my_game)
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
		exit (0);
	}
	my_game->mlx_win = mlx_new_window(my_game->mlx, my_game->length * size,
			my_game->width * size, "./so_long");
	if (!my_game->mlx_win)
	{
		ft_error("MLX", "MLX new_window failed");
		exit (0);
	}
	ft_get_tiles(my_game, size);
	ft_update_window(my_game);
}
