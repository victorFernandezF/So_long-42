/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:06:05 by victofer          #+#    #+#             */
/*   Updated: 2022/10/11 19:16:13 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_hexa(unsigned int num)
{
	int	i;

	i = 0;
	if (num >= 16)
	{
		ft_put_hexa(num / 16);
		ft_put_hexa(num % 16);
	}
	else
	{
		if (num <= 9)
		{
			ft_putchar_fd(num + 48, 1);
			i++;
		}
		else
			ft_putchar_fd(num -10 + 'A', 1);
		i++;
	}
}
