/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efeeney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 15:24:40 by efeeney           #+#    #+#             */
/*   Updated: 2018/12/01 15:24:42 by efeeney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;

	dest = (char *)malloc(sizeof(*dest) * (ft_strlen(src) + 1));
	if (dest == NULL)
		return (NULL);
	return (ft_strcpy(dest, src));
}
