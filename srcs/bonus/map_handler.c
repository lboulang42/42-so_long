/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 19:24:20 by lboulang          #+#    #+#             */
/*   Updated: 2023/03/29 23:40:15 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/*
Take two strings, create another, join 1 & 2 in the new one (null terminate)
Free the first string (used for gnl/read_fd), the 2nd string is a temp we need
to reuse it
*/
char	*ft_join_free(char *str1, char *str2)
{
	char	*new_str;
	int		i;
	int		j;

	i = -1;
	j = -1;
	new_str = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!new_str)
		return (NULL);
	while (str1[++i])
		new_str[i] = str1[i];
	while (str2[++j])
		new_str[i + j] = str2[j];
	new_str[i + j] = '\0';
	free(str1);
	return (new_str);
}

/*
simplified version of GNL (buffer size of 1)
check for read error (return -1, need to free everything)
same for join_free error (malloc error can happen)
free temp buffer, return string for everything readed in fd.
*/
char	*ft_read_fd(int fd)
{
	char	*buffer;
	char	*temp_buffer;
	int		bytes_readed;

	bytes_readed = 1;
	buffer = ft_calloc(1, sizeof(char));
	if (!buffer)
		return (NULL);
	temp_buffer = malloc(sizeof(char) * 2);
	if (!temp_buffer)
		return (free(buffer), NULL);
	while (bytes_readed > 0)
	{
		bytes_readed = read(fd, temp_buffer, 1);
		if (bytes_readed == -1)
			return (free(buffer), free(temp_buffer), NULL);
		temp_buffer[bytes_readed] = '\0';
		buffer = ft_join_free(buffer, temp_buffer);
		if (!buffer)
			return (free (temp_buffer), free(buffer), NULL);
	}
	free(temp_buffer);
	return (buffer);
}

/*
check if map not empty,
check if a line is empty
*/
int	ft_check_buffer(char *buffer)
{
	if (!buffer || !ft_strlen(buffer))
		return (ft_error("Map", "Map Empty"), 0);
	if (buffer[0] == '\n')
		return (ft_error("Map", "Map First Line Is Empty"), 0);
	if (ft_find_str("\n\n", buffer) != -1)
		return (ft_error("Map", "Map Have An Empty Line"), 0);
	if (buffer[ft_strlen(buffer) -1] == '\n')
		return (ft_error("Map", "Map Last Line Is Empty"), 0);
	return (1);
}

/*
Not really interesting, just check the buffer (and free it if error) before
splitting it with '\n' as separator. Need to check it before because after the 
split we can't check if there is an empty line.
*/
char	**ft_split_map(char *buffer)
{
	char	**map;

	if (!ft_check_buffer(buffer))
		return (free(buffer), NULL);
	map = ft_split(buffer, '\n');
	return (free(buffer), map);
}

/*
Handle Map :
-	Check .ber,
-	Read the file
-	Check the file itself
-	Check if the map is valid
Result is checked to know if we start the game or not.
*/
int	ft_map_handler(char *path, t_game *my_game)
{
	int		fd;
	char	*map_buffer;

	if (!ft_check_ber(path))
		return (ft_error("Map Path", "Path is not a .ber file"), 0);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (ft_error("Map Path", "Path Invalid"), 0);
	map_buffer = ft_read_fd(fd);
	close(fd);
	if (!map_buffer)
		return (ft_error("Map Reading", "Error Reading Map"), 0);
	my_game->map = ft_split_map(map_buffer);
	if (!my_game->map)
		return (0);
	if (!ft_check_map(my_game))
		return (ft_free_tab(my_game->map), 0);
	my_game->map_mint = ft_array_cpy(my_game->map);
	if (!my_game->map_mint)
		return (ft_free_tab(my_game->map), 0);
	return (1);
}
