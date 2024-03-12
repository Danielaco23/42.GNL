/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-l <dgomez-l@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 10:17:38 by dgomez-l          #+#    #+#             */
/*   Updated: 2024/03/06 12:08:17 by dgomez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_substr_funct(char *s, unsigned int start, ssize_t len)
{
	ssize_t	count;
	char	*res;

	count = 0;
	while (s[start + count])
		count ++;
	if (count >= len)
		count = len;
	res = malloc((count +1) * sizeof(char));
	if (!res)
		return (NULL);
	res[count] = 0;
	if (len != 0)
		count --;
	while (count > 0)
	{
		res[count] = s[start + count];
		count --;
	}
	if (len != 0)
		res[count] = s[start + count];
	return (res);
}

char	*ft_substr(char *s, unsigned int start, ssize_t len)
{
	char	*res;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (slen <= start)
	{
		res = malloc(1 * sizeof(char));
		if (!res)
			return (NULL);
		res[0] = s[slen];
	}
	else
	{
		res = ft_substr_funct(s, start, len);
		if (!res)
			return (NULL);
	}
	return (res);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len1;
	int		len2;
	int		count;
	char	*res;

	if (!s1)
		return (s2);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = malloc((len1 + len2 +1) * sizeof(char));
	if (!res)
		return (NULL);
	count = 0;
	while (count < (len1 + len2))
	{
		if (count < len1)
			res[count] = s1[count];
		else
			res[count] = s2[count - len1];
		count ++;
	}
	free (s1);
	res[count] = 0;
	return (res);
}

ssize_t	ft_strlen(const char *str)
{
	ssize_t		len;

	len = 0;
	while (str[len])
		len ++;
	return (len);
}

void	ft_bzero(void *s, ssize_t n)
{
	ssize_t	count;

	count = 0;
	while (count < n)
	{
		((char *)s)[count] = 0;
		count ++;
	}
}
