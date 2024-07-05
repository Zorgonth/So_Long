/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:04:20 by sal-zuba          #+#    #+#             */
/*   Updated: 2023/10/19 11:55:07 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	c_count(t_m *m)
{
	int	i;
	int	j;

	m->c_count = 0;
	i = 0;
	j = 0;
	while (m->map[i])
	{
		j = 0;
		while (m->map[i][j])
		{
			if (m->map[i][j] == 'C')
				m->c_count++;
			j++;
		}
		i++;
	}
	m->t_count = m->c_count;
	m->coll = malloc((m->c_count * sizeof(mlx_image_t *)));
	i = 0;
	while (i < m->c_count)
	{
		m->coll[i] = start_images(m->mlx, 3);
		i++;
	}
}

void	remove_images(t_m *m, int y, int x)
{
	int			i;

	i = -1;
	while (++i < m->t_count)
	{
		if (m->collectibles[i].y == y && m->collectibles[i].x == x)
		{
			mlx_delete_image(m->mlx, m->coll[i]);
			m->collectibles[i].x = -1;
			m->collectibles[i].y = -1;
			m->c_count--;
		}
	}
}

int	map_size(char *name)
{
	char	*tmp;
	int		i;
	int		fd;

	tmp = (char *)malloc((6 * sizeof(char)));
	tmp = "maps/";
	tmp[5] = '\0';
	tmp = ft_strjoin2(tmp, name);
	fd = open(tmp, O_RDONLY);
	if (fd == -1)
		ft_er(NULL, 0);
	free(tmp);
	i = 0;
	while (1)
	{
		tmp = get_next_line(fd);
		if (tmp && ++i > -1)
			free(tmp);
		else
			break ;
	}
	close (fd);
	return (i);
}

void	print_moves(t_m *m)
{
	write(1, "Number of moves : ", 19);
	ft_putnbr_fd(m->moves, 1);
	write(1, "\n", 1);
	m->moves++;
}

void	ft_win(t_m *m, int flag)
{
	int		i;

	i = 0;
	if (flag == 1)
		write(1, "You win !\n", 11);
	free(m->collectibles);
	while (m->map[i])
	{
		free(m->map[i]);
		i++;
	}
	free(m->map);
	free(m->coll);
}
