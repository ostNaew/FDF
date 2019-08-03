/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efeeney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 15:28:13 by efeeney           #+#    #+#             */
/*   Updated: 2018/12/01 15:28:14 by efeeney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	s;
	int		len;

	s = (char)c;
	len = ft_strlen(str);
	while (len != (-1))
	{
		if (str[len] == s)
			return ((char *)&str[len]);
		len--;
	}
	return (NULL);
}
