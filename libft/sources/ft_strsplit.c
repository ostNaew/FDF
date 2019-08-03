/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efeeney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 15:28:23 by efeeney           #+#    #+#             */
/*   Updated: 2018/12/01 15:28:24 by efeeney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int			ft_count_words(char const *s, char c)
{
	int		cnt;
	int		subs;

	subs = 0;
	cnt = 0;
	while (*s != '\0')
	{
		if (subs == 1 && *s == c)
			subs = 0;
		if (subs == 0 && *s != c)
		{
			subs = 1;
			cnt++;
		}
		s++;
	}
	return (cnt);
}

static	int			ft_strclen(char const *s, char c)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (i);
}

char				**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	char	**dest;

	i = 0;
	if (!s)
		return (NULL);
	j = ft_count_words((const char *)s, c);
	dest = (char **)malloc(sizeof(*dest) * (j) + 1);
	if (dest == NULL)
		return (NULL);
	while (j--)
	{
		while (*s == c && *s != '\0')
			s++;
		dest[i] = ft_strsub((const char *)s, 0, ft_strclen((const char *)s, c));
		if (dest[i] == NULL)
			return (NULL);
		s = s + ft_strclen((const char *)s, c);
		i++;
	}
	dest[i] = NULL;
	return (dest);
}
