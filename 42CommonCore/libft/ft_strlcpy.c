/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjose-va <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:44:06 by bjose-va          #+#    #+#             */
/*   Updated: 2024/11/04 18:15:15 by bjose-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	c;

	c = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[c] && c < size - 1)
	{
		dst[c] = src[c];
		c++;
	}
	dst[c] = 0;
	return (ft_strlen(src));
}
/*
int		main(void)
{
	printf("%zu", ft_strlcpy("HELLO", "WORLD", 6));
	return (0);
}
*/