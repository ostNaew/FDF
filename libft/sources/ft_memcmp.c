/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efeeney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 15:32:01 by efeeney           #+#    #+#             */
/*   Updated: 2018/12/01 15:32:06 by efeeney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*src;

	i = 0;
	dest = (unsigned char *)s1;
	src = (unsigned char *)s2;
	if (s1 == s2 || n == 0)
		return (0);
	while (n--)
	{
		if (dest[i] != src[i])
			return (dest[i] - src[i]);
		if (n)
			i++;
	}
	return (0);
}
