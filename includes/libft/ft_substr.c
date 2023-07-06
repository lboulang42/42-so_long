/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:40:42 by lboulang          #+#    #+#             */
/*   Updated: 2022/11/14 01:00:17 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	sub_len;
	size_t	i;
	char	*sub;

	if (!s)
		return (NULL);
	i = 0;
	sub_len = ft_strlen(s) - start;
	if (sub_len > len)
		sub_len = len;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	sub = malloc(sub_len + 1);
	if (!sub)
		return (NULL);
	while (s[start + i] && i < sub_len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
