/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrisari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 16:14:29 by mcrisari          #+#    #+#             */
/*   Updated: 2021/02/23 16:21:45 by mcrisari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

typedef unsigned char	t_byte;

int			get_next_line(int fd, char **line);
void		*ft_gnl_calloc(size_t count, size_t size);
void		*ft_gnl_memset(void *b, int c, size_t len);
char		*ft_gnl_strjoin(char *s1, char *s2);
void		*ft_gnl_memcpy(void *dst, const void *src, size_t n);
size_t		ft_gnl_strlen(const char *str);

#endif
