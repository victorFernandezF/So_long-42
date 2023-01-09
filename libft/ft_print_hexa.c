/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 19:22:04 by victofer          #+#    #+#             */
/*   Updated: 2022/10/11 18:02:14 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_hexa_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

static int	ft_hex_lower_upper(int num, char format, int i)
{
	if (format == 'x')
	{
		ft_putchar_fd(num - 10 + 'a', 1);
		i++;
	}
	if (format == 'X')
	{
		ft_putchar_fd(num -10 + 'A', 1);
		i++;
	}
	return (i);
}

static int	ft_print_hexadecimal(unsigned int num, char format)
{
	int	i;

	i = 0;
	if (num >= 16)
	{
		ft_print_hexadecimal(num / 16, format);
		ft_print_hexadecimal(num % 16, format);
	}
	else
	{
		if (num <= 9)
		{
			ft_putchar_fd(num + 48, 1);
			i++;
		}
		else
			i += ft_hex_lower_upper(num, format, i);
	}
	return (i);
}

int	ft_print_hexa(unsigned int num, char format)
{
	int	ret;

	ret = 0;
	if (num == 0)
	{
		ret += ft_print_char('0');
		return (ret);
	}
	else
		ft_print_hexadecimal(num, format);
		ret += ft_hexa_len(num);
	return (ret);
}
