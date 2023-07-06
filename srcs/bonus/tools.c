/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:57:40 by lboulang          #+#    #+#             */
/*   Updated: 2023/03/08 03:14:43 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/*
Call error with specified type & reason
*/
void	ft_error(char *type, char *reason)
{
	ft_printf("Error\nType : %s\nReason : %s\n", type, reason);
}

/*
basic function to set x & y coord on t_coo struct
*/
int	ft_set_coord(t_coo *asset, int x_coo, int y_coo)
{
	asset->x = x_coo;
	asset->y = y_coo;
	return (1);
}

/*
Find str in str
*/
int	ft_find_str(char *to_find, char *str)
{
	int	i;
	int	j;

	i = 0;
	if (!to_find || !str)
		return (-1);
	while (str[i])
	{
		j = 0;
		while (to_find[j] && str[i + j] == to_find[j])
			j++;
		if (to_find[j] == '\0')
			return (i);
		i++;
	}
	return (-1);
}

/*
Find char in str
*/
int	ft_find_char(char *str, char c)
{
	int	i;

	i = 0;
	if (!str || !c)
		return (-1);
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
