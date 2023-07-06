/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:43:38 by lboulang          #+#    #+#             */
/*   Updated: 2022/11/14 01:18:57 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char	*big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*s_big;

	s_big = (char *)big;
	if ((!big || !little) && len == 0)
		return (NULL);
	if (big == little)
		return (s_big);
	if (!*little)
		return (s_big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && i + j < len && \
			big[i + j] && little[j])
			j++;
		if (j == ft_strlen (little))
			return (&s_big[i]);
		i++;
	}
	return (NULL);
}
