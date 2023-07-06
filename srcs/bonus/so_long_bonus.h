/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 04:32:06 by lboulang          #+#    #+#             */
/*   Updated: 2023/04/03 18:57:03 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include <stdio.h>
# include <fcntl.h>
# include "./includes/libft/libft.h"
# include "./includes/ft_printf/ft_printf.h"
# include "./includes/mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100

typedef struct s_coordinate
{
	int	x;
	int	y;
}	t_coo;

typedef struct s_game
{
	t_coo	start;
	t_coo	exit;
	char	**map;
	char	**map_mint;
	int		length;
	int		width;
	int		collectibles;
	int		gotcha;
	void	*pkmn[9][4];
	void	*tile[4];
	void	*mlx;
	void	*mlx_win;
	void	*font_ptr;
}	t_game;

/*array_handler.c*/
char	**ft_array_cpy(char **array);
void	ft_free_tab(char **tab);
void	ft_print_array(char **array);
int		ft_array_size(char **array);
/*game_handler.c*/
int		ft_play(t_game *my_game);
int		ft_close(t_game *my_game);
int		ft_check_win(t_game *my_game);
void	ft_handle_exit(t_game *my_game, int i, int j, int size);
void	ft_set_tile(t_game *my_game, int i, int j, int *count_pkmn);
/*map_checker.c*/
int		ft_check_ber(char	*str);
int		ft_check_square(char **map);
int		ft_check_walls(char **map, int row_count, int row_len);
int		ft_check_charset(t_game *my_game, int c, int e, int p);
int		ft_check_map(t_game *my_game);
/*map_handler.c*/
char	**ft_split_map(char *buffer);
char	*ft_join_free(char *str1, char *str2);
char	*ft_read_fd(int fd);
int		ft_check_buffer(char *buffer);
int		ft_map_handler(char *path, t_game *my_game);
/*map_pathfind.c*/
int		ft_count_assets(int P_count, int E_count, int C_count);
int		ft_pathfind(char **map, int x, int y);
/*mlx_handler.c*/
void	ft_store_assets(t_game *game, char *path[36], int s);
void	ft_store_tile(t_game *game, char *path[4], int s);
void	ft_get_tiles(t_game *my_game, int size);
void	ft_update_window(t_game *my_game, int moove_count);
void	ft_set_map(t_game *my_game, int size);
/*moove_handler.c*/
int		ft_move(t_game *my_game, int x, int y);
int		ft_keypress(int signal, t_game *my_game);
/*tools.c*/
void	ft_error(char *type, char *reason);
int		ft_set_coord(t_coo *asset, int x_coo, int y_coo);
int		ft_find_str(char *to_find, char *str);
int		ft_find_char(char *str, char c);
/*bonus_shit_handler.c*/
int		ft_put_pkmn(t_game *my_game, int count_pkmn, int i, int j);
int		ft_write_move(t_game *my_game, int moove_count);
void	ft_destroy_image(t_game *my_game, int lim_pkmn, int lim_tile);
void	ft_end_game(t_game *my_game, int pkms, int tiles);
#endif