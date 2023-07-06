/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:53:16 by lboulang          #+#    #+#             */
/*   Updated: 2023/03/31 22:23:58 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char **argv, char **env)
{
	t_game	my_game;

	if (!env || !*env)
		return (0);
	if (argc != 2)
		return (ft_error("Map", "Missing Path"), 0);
	if (!ft_map_handler(argv[1], &my_game))
		return (0);
	ft_play(&my_game);
	return (0);
}
