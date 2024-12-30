/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjose-va <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:20:04 by bjose-va          #+#    #+#             */
/*   Updated: 2024/11/07 17:36:37 by bjose-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*temps;
	unsigned char	tempc;

	temps = (unsigned char *)s;
	tempc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (temps[i] == tempc)
			return ((void *)&temps[i]);
		i++;
	}
	return (NULL);
}
/*
int     main(void)
{
    char str[] = "UVA";
    ft_memchr(str, 85, 3);
    return (0);
}*/