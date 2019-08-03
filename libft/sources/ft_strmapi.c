/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efeeney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 15:26:03 by efeeney           #+#    #+#             */
/*   Updated: 2018/12/01 15:26:04 by efeeney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*str;

	i = 0;
	if (!s && !f)
		return (NULL);
	str = ft_strnew(ft_strlen(s));
	if (!str)
	{
		return (NULL);
	}
	if (s && f)
	{
		while (s[i] != '\0')
		{
			str[i] = f(i, s[i]);
			i++;
		}
	}
	else
	{
		return (NULL);
	}
	str[i] = '\0';
	return (str);
}
