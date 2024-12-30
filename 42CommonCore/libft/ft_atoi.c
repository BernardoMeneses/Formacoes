/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjose-va <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:05:09 by bjose-va          #+#    #+#             */
/*   Updated: 2024/11/07 14:28:09 by bjose-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	res;
	int	sign;
	int	len;

	res = 0;
	sign = 1;
	len = 0;
	while ((str[len] >= 9 && str[len] <= 13) || (str[len] == ' '))
		len++;
	if (str[len] == '+' || str[len] == '-')
	{
		if (str[len + 1] == '+' || str[len + 1] == '-')
			return (0);
		if (str[len] == '-')
			sign *= -1;
		len++;
	}
	while (str[len] >= '0' && str[len] <= '9')
	{
		res = res * 10 + (str[len] - '0');
		len++;
	}
	return (res * sign);
}

/*
int     main(void)
{
    printf("FT_ATOI: %d\n",ft_atoi("-658"));
    printf("ATOI: %d\n", atoi("-658"));
    return (0);   
}*/