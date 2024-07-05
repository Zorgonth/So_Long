/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 19:11:00 by sal-zuba          #+#    #+#             */
/*   Updated: 2023/11/08 13:36:39 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	name(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
		i++;
	i -= 4;
	if (i < 0 || ft_strncmp(".ber", arg + i, 4) != 0)
	{
		write(2, "Error\nWrong Input!\n", 20);
		exit(1);
	}
}

int32_t	main(int argc, char **argv)
{
	char			**map;
	t_m				m;

	if (argc != 2)
		return (ft_er(NULL, 0), 0);
	name(argv[1]);
	map = maps(argv[1]);
	m = init(map);
	ft_win(&m, 0);
	return (EXIT_SUCCESS);
}
