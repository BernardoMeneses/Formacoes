/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjose-va <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:12:56 by bjose-va          #+#    #+#             */
/*   Updated: 2024/11/04 18:30:04 by bjose-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*str;

	str = (char *) s;
	while (n > 0)
	{
		str[n - 1] = c;
		n--;
	}
	return (str);
}
/*
int     main(void)
{
    char str[] = "XXXXXX";
    ft_memset(str, 3, 4);
}*/