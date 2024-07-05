/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 09:32:40 by sal-zuba          #+#    #+#             */
/*   Updated: 2023/10/24 13:03:56 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_er(char **map, int flag)
{
	int		i;

	i = -1;
	if (flag == 1)
	{
		while (map[++i])
			free(map[i]);
		free(map);
	}
	ft_putstr_fd("Error\ninvalid map!\n", 2);
	exit(1);
}

void	ft_fnl(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (map[0][j + 1])
	{
		if (map[0][j] != '1')
			ft_er(map, 1);
		j++;
	}
	while (map[i + 1])
		i++;
	j = 0;
	while (map[i][j])
	{
		if (map[i][j] != '1')
			ft_er(map, 1);
		j++;
	}
}

void	ft_check_borders(char **map)
{
	int	i;
	int	j;
	int	x;

	x = 0;
	i = 0;
	j = 0;
	ft_fnl(map);
	while (map[j + 2] != NULL)
	{
		if (ft_strlen(map[j]) != ft_strlen(map[j + 1]))
			ft_er(map, 1);
		j++;
	}
	if (ft_strlen(map[j]) != (ft_strlen(map[j + 1]) + 1))
		ft_er(map, 1);
	while (map[i + 1])
	{
		j = 0;
		x = ft_strlen(map[i + 1]) - 2;
		if (map[i + 1][0] != '1' || map[i + 1][x] != '1')
			ft_er(map, 1);
		i++;
	}
}

void	check_map(char **map)
{
	int	p;
	int	e;
	int	c;
	int	i;
	int	j;

	c = 0;
	p = 0;
	e = 0;
	ft_check_borders(map);
	ft_check_num(map, p, e, c);
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] != 'E' && map[i][j] != '1' && map[i][j] != '0' &&
			map[i][j] != 'P' && map[i][j] != 'C' && map[i][j] != '\n')
				ft_er(map, 1);
		}
	}
}

char	**maps(char *name)
{
	char	**map;
	char	*tmp;
	int		fd;
	int		i;
	int		j;

	j = -1;
	i = map_size(name);
	map = (char **)malloc((i + 1) * sizeof(char *));
	tmp = (char *)malloc((6 * sizeof(char)));
	tmp = "maps/";
	tmp[5] = '\0';
	tmp = ft_strjoin2(tmp, name);
	fd = open(tmp, O_RDONLY);
	free(tmp);
	if (fd == -1)
		ft_er(map, 1);
	while (++j < i)
		map[j] = get_next_line(fd);
	map[j] = 0;
	close(fd);
	check_map(map);
	solvable(map);
	return (map);
}
