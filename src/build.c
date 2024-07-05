/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:01:55 by sal-zuba          #+#    #+#             */
/*   Updated: 2023/10/19 11:53:15 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	build_player(t_m *m)
{
	t_pixel				b;

	b.pixel_x = 0;
	b.pixel_y = 0;
	b.x = -1;
	while (m->map[++b.x])
	{
		b.pixel_y = 0;
		b.y = -1;
		while (m->map[b.x][++b.y] != '\0' && m->map[b.x][b.y] != '\n')
		{
			if (m->map[b.x][b.y] == 'P')
			{
				mlx_image_to_window(m->mlx, m->p, b.pixel_y, b.pixel_x);
				m->player.x = b.pixel_y;
				m->player.y = b.pixel_x;
			}
			b.pixel_y += 32;
		}
		b.pixel_x += 32;
	}
}

void	build_map(t_m m)
{
	t_pixel				b;

	b.pixel_x = 0;
	b.pixel_y = 0;
	b.x = -1;
	while (m.map[++b.x])
	{
		b.pixel_y = 0;
		b.y = -1;
		while (m.map[b.x][++b.y] != '\0' && m.map[b.x][b.y] != '\n')
		{
			if (m.map[b.x][b.y] == '1')
				mlx_image_to_window(m.mlx, m.b, b.pixel_y, b.pixel_x);
			else
				mlx_image_to_window(m.mlx, m.w, b.pixel_y, b.pixel_x);
			b.pixel_y += 32;
		}
		b.pixel_x += 32;
	}
	build_other(m);
}

void	build_coll(t_m *m)
{
	t_pixel				b;
	int					i;

	i = 0;
	c_count(m);
	m->collectibles = malloc(m->c_count * sizeof(t_position));
	b.pixel_x = 0;
	b.pixel_y = 0;
	b.x = -1;
	while (m->map[++b.x])
	{
		b.pixel_y = 0;
		b.y = -1;
		while (m->map[b.x][++b.y] != '\0' && m->map[b.x][b.y] != '\n')
		{
			if (m->map[b.x][b.y] == 'C')
			{
				mlx_image_to_window(m->mlx, m->coll[i], b.pixel_y, b.pixel_x);
				m->collectibles[i].y = b.x;
				m->collectibles[i++].x = b.y;
			}
			b.pixel_y += 32;
		}
		b.pixel_x += 32;
	}
}

void	build_other(t_m m)
{
	t_pixel	b;

	b.pixel_x = 0;
	b.pixel_y = 0;
	b.x = -1;
	while (m.map[++b.x])
	{
		b.pixel_y = 0;
		b.y = -1;
		while (m.map[b.x][++b.y] != '\0' && m.map[b.x][b.y] != '\n')
		{
			if (m.map[b.x][b.y] == 'E')
				mlx_image_to_window(m.mlx, m.e, b.pixel_y, b.pixel_x);
			b.pixel_y += 32;
		}
		b.pixel_x += 32;
	}
}

void	build_images(t_m	*m)
{
	m->b = start_images(m->mlx, 0);
	m->w = start_images(m->mlx, 1);
	m->p = start_images(m->mlx, 2);
	m->e = start_images(m->mlx, 4);
}
