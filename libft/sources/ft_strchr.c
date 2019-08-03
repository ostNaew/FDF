/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efeeney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 15:23:40 by efeeney           #+#    #+#             */
/*   Updated: 2018/12/01 15:23:41 by efeeney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	s;

	s = (char)c;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == s)
		{
			return ((char *)&str[i]);
		}
		i++;
	}
	if (str[i] == s)
		return ((char *)&str[i]);
	else
		return (NULL);
}
