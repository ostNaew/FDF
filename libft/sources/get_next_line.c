/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efeeney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 16:00:05 by efeeney           #+#    #+#             */
/*   Updated: 2018/12/08 16:00:10 by efeeney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	swap_new(char **arr, int fd, int len)
{
	char *temp;

	temp = ft_strdup(&arr[fd][len + 1]);
	free(arr[fd]);
	arr[fd] = temp;
}

void	swap_next(char **arr, int fd, char *buf)
{
	char *temp;

	temp = ft_strjoin(arr[fd], buf);
	free(arr[fd]);
	arr[fd] = temp;
}

int		check_error(int ret, char **arr, int fd)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (arr[fd] == NULL || arr[fd][0] == '\0'))
		return (0);
	else
		return (1);
}

int		get_newline(char **arr, char **line, int fd)
{
	int		len;

	len = 0;
	while (arr[fd][len] != '\n' && arr[fd][len] != '\0')
		len++;
	if (arr[fd][len] == '\n')
	{
		*line = ft_strsub(arr[fd], 0, len);
		swap_new(arr, fd, len);
	}
	else if (arr[fd][len] == '\0')
	{
		*line = ft_strdup(arr[fd]);
		ft_strdel(&arr[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*arr[255];
	char		buf[BUFF_SIZE + 1];
	int			ret;
	int			err;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (arr[fd] == NULL)
			arr[fd] = ft_strnew(1);
		swap_next(arr, fd, buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	err = check_error(ret, arr, fd);
	if (err < 0)
		return (-1);
	else if (!err)
		return (0);
	return (get_newline(arr, line, fd));
}
