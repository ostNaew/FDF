/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efeeney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 15:23:31 by efeeney           #+#    #+#             */
/*   Updated: 2018/12/01 15:23:32 by efeeney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *str1, const char *str2)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(str1);
	while (str2[i] != '\0')
	{
		str1[i + len] = str2[i];
		i++;
	}
	str1[i + len] = '\0';
	return (str1);
}
