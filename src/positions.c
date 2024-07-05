/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:04:03 by sal-zuba          #+#    #+#             */
/*   Updated: 2023/10/24 13:02:36 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_position	player_position(char **map)
{
	int			i;
	int			j;
	t_position	p;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				p.x = j;
				p.y = i;
				break ;
			}
			j++;
		}
		i++;
	}
	return (p);
}

char	**mapcp(char **map)
{
	int		i;
	int		j;
	char	**new;

	j = 0;
	i = 0;
	while (map[i])
		i++;
	new = (char **)malloc((i + 1) * sizeof(char *));
	i = 0;
	while (map[i])
	{
		j = 0;
		new[i] = (char *)malloc((ft_strlen(map[i] + 1) * sizeof(char)));
		while (map[i][j])
		{
			new[i][j] = map[i][j];
			j++;
		}
		new[i][j] = '\0';
		i++;
	}
	new[i] = 0;
	return (new);
}
