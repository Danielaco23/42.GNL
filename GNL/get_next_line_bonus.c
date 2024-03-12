/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-l <dgomez-l@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 10:17:38 by dgomez-l          #+#    #+#             */
/*   Updated: 2024/03/06 12:08:17 by dgomez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <limits.h>

void	freedom(void **ptr)
{
	if (*ptr != NULL)
	{
		free (*ptr);
		*ptr = NULL;
	}
}

static char	*gnl_strjoin(char **res, t_buf tbuf, ssize_t charpos)
{
	char	*str;
	char	*buf;
	char	*aux_res;

	buf = tbuf.str;
	while (!(*buf))
	{
		buf ++;
		charpos --;
	}
	str = ft_substr(buf, 0, charpos);
	if (!str)
		return (freedom((void **)res), NULL);
	if (!res || !(*res))
		return (freedom((void **)res), str);
	aux_res = *res;
	*res = ft_strjoin(*res, str);
	if (!*res)
		freedom((void **)&aux_res);
	return (freedom((void **)&str), *res);
}

static int	gnl_r(t_buf *buf, ssize_t *index, char **res, int control)
{
	while (control)
	{
		while ((buf->str)[*index] != '\n' && *index < buf->len)
			*index = *index +1;
		*res = gnl_strjoin(res, *buf, *index +1);
		if (!(*res))
			return (ft_bzero(buf->str, BUFFER_SIZE), 0);
		if ((buf->str)[*index] == '\n')
			return (ft_bzero(buf->str, *index +1), 1);
		ft_bzero(buf->str, BUFFER_SIZE);
		buf->len = read(buf->fd, buf->str, BUFFER_SIZE);
		if (buf->len < 0)
			return (ft_bzero(buf->str, BUFFER_SIZE),
				buf->len = 0, *index = 0, freedom((void **)res), 0);
		*index = 0;
		if (buf->len == 0)
		{
			if (!*res)
				return (ft_bzero(buf->str, BUFFER_SIZE), 0);
			return (ft_bzero(buf->str, *index +1), 1);
		}
	}
	return (ft_bzero(buf->str, BUFFER_SIZE), 0);
}

static int	buf_init(t_buf *buf, int *iter, ssize_t *index)
{
	if (*iter == 0)
	{
		ft_bzero(buf->str, BUFFER_SIZE);
		buf->len = read(buf->fd, buf->str, BUFFER_SIZE);
		if (buf->len <= 0)
			return (ft_bzero(buf->str, BUFFER_SIZE), buf->len = 0, 0);
		*iter = 1;
	}
	*index = 0;
	return (1);
}

char	*get_next_line(int fd)
{
	static t_buf	buf[OPEN_MAX];
	char			*res;
	int				control;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return ((buf[fd]).iter = 0, NULL);
	buf[fd].fd = fd;
	if (!buf_init(&buf[fd], &(buf[fd].iter), &(buf[fd].index)))
		return ((buf[fd].iter) = 0, NULL);
	control = 1;
	res = NULL;
	if (!gnl_r(&buf[fd], &(buf[fd].index), &res, control))
		return (freedom((void **)&res), (buf[fd].iter) = 0, NULL);
	if (buf[fd].len == 0)
		(buf[fd].iter) = 0;
	else if ((buf[fd].index) == buf[fd].len -1)
		(buf[fd].iter) = 0;
	return (res);
}
