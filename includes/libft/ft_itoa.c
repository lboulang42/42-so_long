/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 01:22:35 by lboulang          #+#    #+#             */
/*   Updated: 2022/11/12 02:43:55 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digit(long int n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n >= 10)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static void	ft_nbr_to_str(long n, char *str, int *i)
{
	if (n > 9)
	{
		ft_nbr_to_str(n / 10, str, i);
		ft_nbr_to_str(n % 10, str, i);
	}
	else
		str[(*i)++] = n + 48;
}

char	*ft_itoa(int n)
{
	long int	number;
	char		*str;
	int			i;

	number = n;
	str = malloc (ft_count_digit(number) + 1);
	if (!str)
		return (NULL);
	i = 0;
	if (number < 0)
	{
		str[i] = '-';
		i++;
		number *= -1;
	}
	ft_nbr_to_str(number, str, &i);
	str[i] = '\0';
	return (str);
}
