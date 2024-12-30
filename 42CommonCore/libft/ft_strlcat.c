/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjose-va <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:20:09 by bjose-va          #+#    #+#             */
/*   Updated: 2024/11/07 14:16:28 by bjose-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	c;
	size_t	start_len;

	i = ft_strlen(dst);
	c = 0;
	start_len = ft_strlen(dst);
	if (size == 0)
		return (ft_strlen(src));
	if (size <= i)
		return (size + ft_strlen(src));
	while (src[c] && i < size - 1)
	{
		dst[i] = src[c];
		i++;
		c++;
	}
	dst[i] = 0;
	return (start_len + ft_strlen(src));
}
/*
int     main(void)
{
    printf("%zu", ft_strlcat("HELLO", "WORLD", 6));
    return(0);
}
*/