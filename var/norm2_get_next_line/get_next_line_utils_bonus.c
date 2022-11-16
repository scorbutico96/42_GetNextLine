/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrisari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 16:15:02 by mcrisari          #+#    #+#             */
/*   Updated: 2021/02/23 16:25:05 by mcrisari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t it;

	it = 0;
	while (str[it])
		it++;
	return (it);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	t_byte			*a;
	const t_byte	*b;

	a = dst;
	b = src;
	if (!dst && !src)
		return (0);
	while (n)
	{
		*a++ = *b++;
		n--;
	}
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char *ptr;

	if (!s1 || !s2)
		return (0);
	if (!(ptr = malloc(sizeof(*ptr) * (ft_strlen(s1) + ft_strlen(s2)) + 1)))
		return (0);
	ft_memcpy(ptr, s1, ft_strlen(s1));
	ft_memcpy(&ptr[ft_strlen(s1)], s2, ft_strlen(s2));
	ptr[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	return (ptr);
}

void	*ft_memset(void *b, int c, size_t len)
{
	t_byte *ptr;

	ptr = b;
	while (len)
	{
		*ptr = (t_byte)c;
		ptr++;
		len--;
	}
	return (b);
}

void	*ft_calloc(size_t count, size_t size)
{
	void *ptr;

	if (!size)
	{
		ptr = malloc(size);
		return (ptr);
	}
	if (!(ptr = malloc(size * count)))
		return (0);
	ft_memset(ptr, '\0', size * count);
	return (ptr);
}
