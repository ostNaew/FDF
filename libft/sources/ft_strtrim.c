/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efeeney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 15:29:03 by efeeney           #+#    #+#             */
/*   Updated: 2018/12/01 15:29:04 by efeeney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*dest;
	int		a;

	a = 0;
	i = 0;
	if (!s)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	j = ft_strlen(s) - 1;
	while (j >= i && (s[j] == ' ' || s[j] == '\n' || s[j] == '\t'))
		j--;
	dest = ft_strnew(j - i);
	if (dest == NULL)
		return (NULL);
	while (i <= j)
		dest[a++] = s[i++];
	dest[a] = '\0';
	return (dest);
}
