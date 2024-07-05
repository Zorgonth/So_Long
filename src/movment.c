/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:02:48 by sal-zuba          #+#    #+#             */
/*   Updated: 2023/10/24 12:57:51 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_right(t_m *m)
{
	t_position	p;

	p = player_position(m->map);
	if (m->map[p.y][p.x + 1] != '1' &&
	m->map[p.y][p.x + 1] != '\0' && m->map[p.y][p.x + 1] != 'E')
	{
		m->map[p.y][p.x] = '0';
		if (m->map[p.y][p.x + 1] == 'C')
			remove_images(m, p.y, p.x + 1);
		m->map[p.y][p.x + 1] = 'P';
		mlx_delete_image(m->mlx, m->p);
		m->p = start_images(m->mlx, 2);
		m->player.x += 32;
		mlx_image_to_window(m->mlx, m->p, m->player.x, m->player.y);
		print_moves(m);
	}
	else if (m->map[p.y][p.x + 1] == 'E' && !m->c_count)
	{
		ft_win(m, 1);
		mlx_terminate(m->mlx);
		exit(0);
	}
}

void	move_left(t_m *m)
{
	t_position	p;

	p = player_position(m->map);
	if (m->map[p.y][p.x - 1] != '1' &&
	m->map[p.y][p.x - 1] != '\0' && m->map[p.y][p.x - 1] != 'E')
	{
		m->map[p.y][p.x] = '0';
		if (m->map[p.y][p.x - 1] == 'C')
			remove_images(m, p.y, p.x - 1);
		m->map[p.y][p.x - 1] = 'P';
		mlx_delete_image(m->mlx, m->p);
		m->p = start_images(m->mlx, 2);
		m->player.x -= 32;
		mlx_image_to_window(m->mlx, m->p, m->player.x, m->player.y);
		print_moves(m);
	}
	else if (m->map[p.y][p.x - 1] == 'E' && !m->c_count)
	{
		ft_win(m, 1);
		mlx_terminate(m->mlx);
		exit(0);
	}
}

void	move_up(t_m *m)
{
	t_position	p;

	p = player_position(m->map);
	if (m->map[p.y - 1][p.x] != '1' &&
	m->map[p.y - 1][p.x] != '\0' && m->map[p.y - 1][p.x] != 'E')
	{
		m->map[p.y][p.x] = '0';
		if (m->map[p.y - 1][p.x] == 'C')
			remove_images(m, p.y - 1, p.x);
		m->map[p.y - 1][p.x] = 'P';
		mlx_delete_image(m->mlx, m->p);
		m->p = start_images(m->mlx, 2);
		m->player.y -= 32;
		mlx_image_to_window(m->mlx, m->p, m->player.x, m->player.y);
		print_moves(m);
	}
	else if (m->map[p.y - 1][p.x] == 'E' && !m->c_count)
	{
		ft_win(m, 1);
		mlx_terminate(m->mlx);
		exit (0);
	}
}

void	move_down(t_m *m)
{
	t_position	p;

	p = player_position(m->map);
	if (m->map[p.y + 1][p.x] != '1' &&
	m->map[p.y + 1][p.x] != '\0' && m->map[p.y + 1][p.x] != 'E')
	{
		m->map[p.y][p.x] = '0';
		if (m->map[p.y + 1][p.x] == 'C')
			remove_images(m, p.y + 1, p.x);
		m->map[p.y + 1][p.x] = 'P';
		mlx_delete_image(m->mlx, m->p);
		m->p = start_images(m->mlx, 2);
		m->player.y += 32;
		mlx_image_to_window(m->mlx, m->p, m->player.x, m->player.y);
		print_moves(m);
	}
	else if (m->map[p.y + 1][p.x] == 'E' && !m->c_count)
	{
		ft_win(m, 1);
		mlx_terminate(m->mlx);
		exit(0);
	}
}
