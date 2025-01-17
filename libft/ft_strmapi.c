/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:50:35 by sal-zuba          #+#    #+#             */
/*   Updated: 2023/10/24 14:54:56 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		j;
	char				*c;
	unsigned int		a;

	a = 0;
	j = 0;
	a = ft_strlen2(s);
	c = (char *)malloc(a + 1);
	if (c == NULL)
		return (NULL);
	while (j < a)
	{
		c[j] = f(j, s[j]);
		j++;
	}
	c[j] = '\0';
	return (c);
}
