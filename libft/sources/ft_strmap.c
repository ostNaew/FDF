/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efeeney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 15:25:53 by efeeney           #+#    #+#             */
/*   Updated: 2018/12/01 15:25:54 by efeeney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*str;

	i = 0;
	if (!s && !f)
		return (NULL);
	str = ft_strnew(ft_strlen(s));
	if (!str)
		return (NULL);
	if (s && f)
	{
		while (s[i] != '\0')
		{
			str[i] = f(s[i]);
			i++;
		}
	}
	else
		return (NULL);
	str[i] = '\0';
	return (str);
}
