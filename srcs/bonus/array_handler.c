/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 20:13:07 by lboulang          #+#    #+#             */
/*   Updated: 2023/03/08 03:14:26 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/*
Free an array (every ptr in the array then the array itself)
*/
void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free (tab[i]);
		i++;
	}
	free(tab);
}

/*
Printf every row of array with \n at end
*/
void	ft_print_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		ft_printf("%s\n", array[i]);
		i++;
	}
}

/*
Get the number of row in array;
*/
int	ft_array_size(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

/*
Create a new array and copy the one in parameter in the new one
Free if malloc error on one of the string of the array, NULL terminate every
string and the array.
*/
char	**ft_array_cpy(char **array)
{
	char	**array_copy;
	int		tab_count;
	int		i;
	int		j;

	tab_count = 0;
	while (array[tab_count])
		tab_count++;
	array_copy = malloc(sizeof(char *) * (tab_count +1));
	if (!array_copy)
		return (NULL);
	i = -1;
	while (array[++i])
	{
		j = -1;
		array_copy[i] = malloc(sizeof(char) * (ft_strlen(array[i]) + 1));
		if (!array_copy)
			return (ft_free_tab(array_copy), NULL);
		while (array[i][++j] != '\0')
			array_copy[i][j] = array[i][j];
		array_copy[i][j] = '\0';
	}
	array_copy[tab_count] = NULL;
	return (array_copy);
}
