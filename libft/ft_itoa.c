/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 17:19:08 by victofer          #+#    #+#             */
/*   Updated: 2022/09/23 18:16:29 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static int	ft_intlen(int n)
{	
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*ft_array(char *array, int nb, int len)
{
	while (nb > 0)
	{
		array[len - 1] = 48 + (nb % 10);
		nb = nb / 10;
		len--;
	}
	return (array);
}

static char	*ft_make_itoa(char *itoa, int n, int len)
{
	int	nb;

	if (n == -2147483648)
	{
		itoa[0] = '-';
		itoa[1] = '2';
		nb = 147483648;
	}
	else
	{
		if (n == 0)
			itoa[0] = '0';
		if (n < 0)
		{
			nb = n * -1;
			itoa[0] = '-';
		}
		else
			nb = n;
	}
	itoa = ft_array(itoa, nb, len);
	return (itoa);
}

char	*ft_itoa(int n)
{
	char	*itoa;
	int		len;

	len = ft_intlen(n);
	itoa = malloc((len + 1) * sizeof(char));
	if (!itoa)
		return (NULL);
	itoa = ft_make_itoa(itoa, n, len);
	itoa[len] = '\0';
	return (itoa);
}
