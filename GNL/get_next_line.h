/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-l <dgomez-l@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:17:45 by dgomez-l          #+#    #+#             */
/*   Updated: 2024/03/06 12:08:17 by dgomez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_buf
{
	char	str[BUFFER_SIZE];
	ssize_t	len;
	int		fd;
	ssize_t	index;
	int		iter;
}	t_buf;

char	*get_next_line(int fd);
char	*ft_substr(char *s, unsigned int start, ssize_t len);
char	*ft_strjoin(char *s1, char *s2);
ssize_t	ft_strlen(const char *str);
void	ft_bzero(void *s, ssize_t n);
void	freedom(void **ptr);

#endif