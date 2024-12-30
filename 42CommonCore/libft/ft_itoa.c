/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjose-va <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:08:51 by bjose-va          #+#    #+#             */
/*   Updated: 2024/11/07 17:51:10 by bjose-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(long int n);
static void	handle_zero(char **result, long int *nbr);

char	*ft_itoa(int n)
{
	char	*result;
	long	nbr;
	int		len;

	nbr = n;
	len = num_len(n);
	result = malloc(sizeof(char) * len + 1);
	if (!result)
		return (NULL);
	handle_zero(&result, &nbr);
	result[len] = 0;
	if (nbr < 0)
	{
		result[0] = '-';
		nbr = -nbr;
	}
	while (nbr)
	{
		result[len - 1] = nbr % 10 + 48;
		nbr = nbr / 10;
		len--;
	}
	return (result);
}

static void	handle_zero(char **result, long int *nbr)
{
	if (*nbr == 0)
	{
		**result = '0';
		*nbr = -*nbr;
	}
}

static int	num_len(long n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count++;
		n = -n;
	}
	if (n == 0)
		count++;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}
