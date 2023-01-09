/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:34:39 by victofer          #+#    #+#             */
/*   Updated: 2022/09/24 10:34:23 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnumber(int number, int fd)
{
	ft_putchar_fd((number / 10) + 48, fd);
	ft_putchar_fd((number % 10) + 48, fd);
}

static void	ft_print_limit(int fd)
{
	ft_putchar_fd('-', fd);
	ft_putchar_fd('2', fd);
	ft_putnbr_fd(147483648, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	nb2;

	if (n == -2147483648)
	{
		ft_print_limit(fd);
	}
	else if (n < 0)
	{
		nb2 = n * -1;
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(nb2, fd);
	}
	else if (n <= 9)
	{
		ft_putchar_fd(n + 48, fd);
	}
	else if (n <= 99)
	{
		ft_putnumber(n, fd);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd((n % 10) + 48, fd);
	}		
}
