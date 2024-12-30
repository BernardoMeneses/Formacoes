/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjose-va <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:39:52 by bjose-va          #+#    #+#             */
/*   Updated: 2024/11/07 14:24:47 by bjose-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t		len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}
/*
int     main(void)
{
    printf("%zu", ft_strlen("HELLO"));
    return (0);
}
*/