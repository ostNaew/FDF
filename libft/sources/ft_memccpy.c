/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efeeney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 15:21:22 by efeeney           #+#    #+#             */
/*   Updated: 2018/12/01 15:21:23 by efeeney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	char	*dest;
	char	*source;
	char	symbol;

	dest = (char *)dst;
	source = (char *)src;
	symbol = (char)c;
	i = 0;
	while (i < n && (i == 0 || source[i - 1] != symbol))
	{
		dest[i] = source[i];
		i++;
		if (c == 0 && dest[i] == '\0')
			return (&dest[i]);
	}
	if (i > 0 && source[i - 1] == symbol)
		return (&dest[i]);
	else
		return (NULL);
}
