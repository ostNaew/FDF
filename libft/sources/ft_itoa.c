/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efeeney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 15:20:53 by efeeney           #+#    #+#             */
/*   Updated: 2018/12/01 15:20:54 by efeeney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_intlen(int n, int min)
{
	int		i;

	i = 1;
	while (n /= 10)
		i++;
	return (i + min);
}

char			*ft_itoa(int n)
{
	char	*dest;
	int		l;
	int		min;
	int		digit;

	min = (n < 0) ? 1 : 0;
	l = ft_intlen(n, min);
	if ((dest = ft_strnew(l)))
	{
		dest[l--] = '\0';
		while (l >= min)
		{
			digit = n % 10;
			digit = (digit < 0) ? (-digit) : (digit);
			dest[l] = digit + 48;
			l--;
			n = n / 10;
		}
		if (min)
			dest[0] = '-';
	}
	return (dest);
}
