/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_lines_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:42:07 by victofer          #+#    #+#             */
/*   Updated: 2023/01/05 13:24:49 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

/*
**	Check if the map is a sqare whitch is forbidden.
**	Return 0 if the map is fine.
**	If not, print an error and exit.
*/
int	check_map_not_sqare(t_map map_list)
{
	if (map_list.height == map_list.width)
		ft_error_free("Map can't be a sqare", map_list);
	return (0);
}

/*
** Check if the map is closed by left and right sides
** Return 1 if first char and last char of middle lines ar '1'
** Return 0 if not.
*/
int	check_middle_lines(char *str, t_map map_list)
{
	int	i;
	int	len;

	i = 0;
	(void)map_list;
	len = ft_strlen(str) - 1;
	if (str[0] != '1' || str[len - 1] != '1')
		return (0);
	if (len - 1 != map_list.width - 1)
		return (0);
	return (1);
}

/*
** Check if the map is closed by the top side
** Return 1 if every chars from first line '1'
** Return 0 if not.
*/
int	check_first_line(char *str, t_map map_list)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(str) - 1)
	{
		if (str[i] != '1')
			return (0);
		i++;
	}
	if (ft_strlen(str) - 1 != (size_t)map_list.width)
		return (0);
	return (1);
}

/*
** Check if the map is closed by the top side
** Return 1 if every chars from last line '1'
** Return 0 if not.
*/
int	check_last_line(char *str, t_map map_list)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(str))
	{
		if (str[i] != '1')
			return (0);
		i++;
	}
	if (ft_strlen(str) != (size_t)map_list.width)
		return (0);
	return (1);
}
