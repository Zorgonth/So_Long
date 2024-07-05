/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 13:28:10 by sal-zuba          #+#    #+#             */
/*   Updated: 2023/10/27 14:15:43 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_hw
{
	int	height;
	int	width;
}		t_hw;

typedef struct s_solv
{
	int	i;
	int	j;
	int	count;
}		t_solv;

typedef struct s_position
{
	int	x;
	int	y;
}				t_position;

typedef struct s_pixel
{
	int	pixel_x;
	int	x;
	int	pixel_y;
	int	y;
}			t_pixel;

typedef struct s_m
{
	int					moves;
	mlx_t				*mlx;
	char				**map;
	t_position			player;
	t_position			*collectibles;
	int					t_count;
	int					c_count;
	mlx_image_t			*b;
	mlx_image_t			*w;
	mlx_image_t			*e;
	mlx_image_t			*p;
	mlx_image_t			**coll;
}		t_m;

mlx_image_t	*start_images( mlx_t *mlx, int flag);
t_position	player_position(char **map);
xpm_t		*start_textures(int flag);
t_m			init(char **map);
t_hw		size(char **m);
void		img_to_win(mlx_t *mlx, mlx_image_t *img, t_pixel b);
void		my_keyhook(mlx_key_data_t keydata, void *param);
void		ft_check_num(char **map, int p, int e, int c);
void		solve_e(char **map, int count, int i, int j);
void		build_background(char **map, mlx_t *mlx);
void		flood_fill(char **tmp, int x, int y);
void		remove_images(t_m *m, int y, int x);
void		*ft_calloc(size_t nmemb, size_t size);
void		ft_check_borders(char **map);
void		ft_er(char **map, int flag);
void		ft_win(t_m *m, int flag);
void		build_images(t_m	*m);
void		check_map(char **map);
void		build_player(t_m *m);
void		solvable(char **map);
void		print_moves(t_m *m);
void		ft_fnl(char **map);
void		build_coll(t_m *m);
void		move_right(t_m *m);
void		build_other(t_m m);
void		move_left(t_m *m);
void		move_down(t_m *m);
void		build_map(t_m m);
void		move_up(t_m *m);
void		c_count(t_m *m);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_read(int fd, char *s);
char		*get_next_line(int fd);
char		**mapcp(char **map);
char		*ft_strdup(char *s);
char		**maps(char *name);
int			ft_strlen(const char *str);
int			map_size(char *name);
int			check(char **tmp);

#endif