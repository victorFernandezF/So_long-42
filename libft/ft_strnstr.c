/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:27:23 by victofer          #+#    #+#             */
/*   Updated: 2022/09/24 13:58:57 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	nlen;
	char	*hay;
	char	*need;

	hay = (char *)haystack;
	need = (char *)needle;
	nlen = ft_strlen(needle);
	if (nlen == 0 || hay == need)
		return (hay);
	while (*hay && len-- >= nlen)
	{
		if (*hay == *need && ft_memcmp (hay, need, nlen) == 0)
			return ((char *)hay);
		hay++;
	}
	return (NULL);
}
