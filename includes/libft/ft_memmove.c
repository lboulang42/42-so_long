/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:41:59 by lboulang          #+#    #+#             */
/*   Updated: 2022/11/14 01:16:22 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*s1;
	char	*s2;

	if (!dest && !src)
		return (NULL);
	s1 = (char *)dest;
	s2 = (char *)src;
	if (s1 < s2)
		ft_memcpy(s1, s2, n);
	else
	{
		while (n)
		{
			s1[n -1] = s2[n -1];
			n--;
		}
	}
	return (dest);
}
