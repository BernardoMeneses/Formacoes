/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjose-va <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:56:32 by bjose-va          #+#    #+#             */
/*   Updated: 2024/11/07 15:46:28 by bjose-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
/*
int     main(void)
{
    printf("FT_ASCII: %d\n ", ft_isascii(-1));
    printf("ASCII: %d\n ", isascii(-1));
}
*/