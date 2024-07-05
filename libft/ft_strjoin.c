/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 21:00:34 by sal-zuba          #+#    #+#             */
/*   Updated: 2023/10/24 14:52:45 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin2(char const *s1, char const *s2)
{
	char		*str;
	size_t		len;

	len = ft_strlen2(s1) + ft_strlen2(s2) + 1;
	str = (char *)malloc(len);
	if (!str)
		return (0);
	ft_strlcpy(str, s1, ft_strlen2(s1) + 1);
	ft_strlcat(str, s2, len);
	return (str);
}
