/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrisari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 17:21:40 by mcrisari          #+#    #+#             */
/*   Updated: 2021/02/23 16:15:50 by mcrisari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_gnl_chain(char *tmp, char **line)
{
	char	*swap;

	swap = *line;
	*line = ft_gnl_strjoin(swap, tmp);
	if (!*line)
		return (0);
	free(swap);
	free(tmp);
	return (1);
}

static int	ft_gnl_engine(char *buf, char **line)
{
	static int	i;
	int			j;
	char		*tmp;

	j = 0;
	tmp = ft_gnl_calloc(BUFFER_SIZE + 1, sizeof(*tmp));
	if (!tmp)
		return (-1);
	while (i < BUFFER_SIZE)
	{
		if (buf[i] == '\n')
		{
			i++;
			if (!(ft_gnl_chain(tmp, line)))
				return (-1);
			return (0);
		}
		tmp[j++] = buf[i++];
	}
	if (!(ft_gnl_chain(tmp, line)))
		return (-1);
	i = 0;
	return (1);
}

static int	ft_gnl_v3(int fd, char **line, char *buf)
{
	int				read_size;
	int				status;

	read_size = 1;
	while (read_size >= 0)
	{
		if (read_size == 0)
			return (0);
		status = ft_gnl_engine(buf, line);
		if (status > 0)
		{
			ft_gnl_memset(buf, '\0', BUFFER_SIZE + 1);
			read_size = read(fd, buf, BUFFER_SIZE);
		}
		if (!status)
			return (1);
		if (status < 0)
			return (-1);
	}
	return (-1);
}

int	get_next_line(int fd, char **line)
{
	static char		buf[BUFFER_SIZE + 1];
	int				check;

	if (fd < 0 || fd > 256 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	*line = ft_gnl_calloc(1, sizeof(*line));
	if (!*line)
		return (-1);
	check = ft_gnl_v3(fd, line, buf);
	return (check);
}
