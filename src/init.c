/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:43:05 by sal-zuba          #+#    #+#             */
/*   Updated: 2023/10/27 13:39:28 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

xpm_t	*start_textures(int flag)
{
	if (flag == 0)
		return (mlx_load_xpm42("texture/b.xpm42"));
	if (flag == 1)
		return (mlx_load_xpm42("texture/w.xpm42"));
	if (flag == 2)
		return (mlx_load_xpm42("texture/p.xpm42"));
	if (flag == 3)
		return (mlx_load_xpm42("texture/c.xpm42"));
	else
		return (mlx_load_xpm42("texture/e.xpm42"));
}

mlx_image_t	*start_images( mlx_t *mlx, int flag)
{
	mlx_image_t		*img;
	xpm_t			*xpm;

	xpm = start_textures(flag);
	img = mlx_texture_to_image(mlx, &xpm->texture);
	mlx_delete_xpm42(xpm);
	return (img);
}

t_hw	size(char **m)
{
	t_hw	map;
	int		i;
	int		j;

	i = 0;
	j = 0;
	map.height = 0;
	map.width = 0;
	while (m[i])
	{
		i++;
		map.height += 32;
	}
	while (m[0][j] != '\0' && m[0][j] != '\n')
	{
		j++;
		map.width += 32;
	}
	return (map);
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_m	*m;

	m = (t_m *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		ft_win(m, 0);
		mlx_terminate(m->mlx);
		exit(0);
	}
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		move_right(m);
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		move_left(m);
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		move_up(m);
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		move_down(m);
}

t_m	init(char **map)
{
	t_hw				m;
	t_m					ml;
	mlx_image_t			*img;

	ml.moves = 0;
	m = size(map);
	ml.mlx = mlx_init(m.width, m.height, "so_long", true);
	if (!ml.mlx)
	{
		ft_er(map, 1);
		exit(1);
	}
	ml.map = map;
	img = mlx_new_image(ml.mlx, m.width, m.height);
	mlx_image_to_window(ml.mlx, img, 0, 0);
	build_images(&ml);
	build_map(ml);
	build_player(&ml);
	build_coll(&ml);
	mlx_key_hook(ml.mlx, &my_keyhook, &ml);
	mlx_loop(ml.mlx);
	mlx_terminate(ml.mlx);
	return (ml);
}
