/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:05:18 by sal-zuba          #+#    #+#             */
/*   Updated: 2023/10/21 17:29:23 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	solvable(char **map)
{
	int				i;
	char			**tmp;
	t_position		size;
	t_position		player;

	tmp = mapcp(map);
	size.y = 0;
	size.x = 0;
	while (tmp[size.y])
		size.y++;
	while (tmp[0][size.x] != '\n' && tmp[0][size.x] != '\0')
		size.x++;
	player = player_position(map);
	tmp[player.y][player.x] = '0';
	flood_fill(tmp, player.x, player.y);
	if (check(tmp) == 1)
		ft_er(map, 1);
	i = -1;
	while (tmp[++i])
		free(tmp[i]);
	free(tmp);
}

int	check(char **tmp)
{
	int	i;
	int	j;

	i = -1;
	while (tmp[++i])
	{
		j = -1;
		while (tmp[i][++j])
		{
			if (tmp[i][j] == 'E' || tmp[i][j] == 'C')
				return (1);
		}
	}
	return (0);
}

void	flood_fill(char **tmp, int x, int y)
{
	if (tmp[y][x] == 'C')
		;
	if (tmp[y][x] == 'E')
		tmp[y][x] = '1';
	else
	{
		tmp[y][x] = '1';
		if (tmp[y][x + 1] != '1')
			flood_fill(tmp, x + 1, y);
		if (tmp[y][x - 1] != '1')
			flood_fill(tmp, x - 1, y);
		if (tmp[y + 1][x] != '1')
			flood_fill(tmp, x, y + 1);
		if (tmp[y - 1][x] != '1')
			flood_fill(tmp, x, y - 1);
	}
}

void	ft_check_num(char **map, int p, int e, int c)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'E')
				e++;
			if (map[i][j] == 'C')
				c++;
			if (map[i][j] == 'P')
				p++;
		}
	}
	if ((e > 1 || e == 0) || (p > 1 || p == 0) || (c == 0))
		ft_er(map, 1);
}
