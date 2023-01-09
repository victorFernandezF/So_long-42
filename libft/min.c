/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:28:06 by victofer          #+#    #+#             */
/*   Updated: 2022/11/10 12:33:37 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	min(int *tab, unsigned int len)
{
	int				min;
	unsigned int	i;

	min = tab[0];
	i = 0;
	while (i <= len)
	{
		if (i == len - 1)
			if (tab[i] < min)
				min = tab[i];
		if ((tab[i] < tab[i + 1]) && (tab[i] < min))
			min = tab[i];
		i++;
	}
	return (min);
}
