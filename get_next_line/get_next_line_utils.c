/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 11:12:54 by victofer          #+#    #+#             */
/*   Updated: 2023/01/05 13:43:33 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

void	*ft_calloc_gnl(size_t count, size_t size)
{
	void			*res;
	unsigned char	*str;
	size_t			total;

	total = size * count;
	res = (char *)malloc(sizeof(char) * total);
	if (!res)
		return (NULL);
	str = (unsigned char *)res;
	while (total != 0)
	{
		*str = '\0';
		str++;
		total--;
	}
	return (res);
}

size_t	ft_strlen_gnl(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*join;
	int		i;
	int		j;
	int		size;

	i = 0;
	size = ft_strlen_gnl(s1) + ft_strlen_gnl(s2);
	join = (char *)malloc((size + 1) * sizeof(char));
	if (!join || !s1 || !s2)
		return (NULL);
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		join[i] = s2[j];
		i++;
		j++;
	}
	join[size] = 0;
	return (join);
}

char	*ft_strchr_gnl(char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != c && *str != 0)
		str++;
	if (*str == c)
		return (str);
	else
		return (NULL);
}
