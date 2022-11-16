/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrisari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 16:14:21 by mcrisari          #+#    #+#             */
/*   Updated: 2021/02/23 16:25:56 by mcrisari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_gnl_bufreset(char *dst, char *src, size_t len)
{
	if (dst || src)
	{
		if (dst < src)
			ft_gnl_memcpy(dst, src, len);
		ft_gnl_memset(&dst[len], '\0', BUFFER_SIZE - len);
	}
	return (dst);
}

int	ft_gnl_chain(char *tmp, char **line)
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

int	ft_gnl_engine(char *buf, char **line)
{
	int			i;
	char		*tmp;

	i = 0;
	tmp = ft_gnl_calloc(BUFFER_SIZE + 1, sizeof(*tmp));
	if (!tmp)
		return (-1);
	while (i < BUFFER_SIZE && buf[i] && buf[i] != '\n')
	{
		tmp[i] = buf[i];
		i++;
	}
	if (!(ft_gnl_chain(tmp, line)))
		return (0);
	ft_gnl_bufreset(&buf[0], &buf[i], BUFFER_SIZE - i);
	return (1);
}

int	ft_gnl_init(int fd, char **buf, char **line)
{
	if (fd < 0 || fd > 256 || BUFFER_SIZE <= 0 || !line)
		return (0);
	if (!buf[fd])
	{
		buf[fd] = ft_gnl_calloc(BUFFER_SIZE + 1, sizeof(**buf));
		if (!buf[fd])
			return (0);
	}
	*line = ft_gnl_calloc(1, sizeof(*line));
	if (!*line)
		return (0);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char		*buf[256];
	int				read_size;

	read_size = 1;
	if (!(ft_gnl_init(fd, buf, line)))
		return (-1);
	while (read_size >= 0 && buf[fd])
	{
		if (!(ft_gnl_engine(buf[fd], line)))
			return (-1);
		if (buf[fd][0] == '\n' &&
			ft_gnl_bufreset(buf[fd], &buf[fd][1], BUFFER_SIZE))
			return (1);
		if (read_size == 0)
		{
			free(buf[fd]);
			buf[fd] = NULL;
			return (0);
		}
		ft_gnl_memset(buf[fd], '\0', BUFFER_SIZE + 1);
		read_size = read(fd, buf[fd], BUFFER_SIZE);
	}
	return (-1);
}
