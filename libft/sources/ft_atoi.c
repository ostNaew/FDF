/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efeeney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 15:19:09 by efeeney           #+#    #+#             */
/*   Updated: 2018/12/01 15:19:15 by efeeney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int i;
	int result;
	int sign;

	i = 0;
	sign = 1;
	result = 0;
	if (ft_strlen(str) > 19 && ft_strlen(str) == 0)
		return (-1);
	while ((str[i] >= 8 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		while ((str[i] >= 48 && str[i] <= 57))
			result = (result * 10) + str[i++] - '0';
		break ;
	}
	return (result * sign);
}
