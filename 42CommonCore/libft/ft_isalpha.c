/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjose-va <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:40:15 by bjose-va          #+#    #+#             */
/*   Updated: 2024/11/07 15:44:40 by bjose-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

/*
int   main(void)
{
  printf("FT_ALPHA: %d\n", ft_isalpha('6'));
  printf("ALPHA: %d\n", isalpha('6'));
  return (0);
}
*/