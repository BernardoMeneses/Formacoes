/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjose-va <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:02:27 by bjose-va          #+#    #+#             */
/*   Updated: 2024/11/07 17:31:01 by bjose-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = (int)ft_strlen(s);
	if (!((unsigned char)c))
		return ((char *)&s[i]);
	while (i >= 0)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}
/*
#include <stdio.h>

int main(void)
{
    const char *str = "Hello, World!";
    char c = 'o';
    char *result;

    result = ft_strrchr(str, c);
    if (result)
printf("A última ocorrência de '%c' em \"%s\" 
está em: \"%s\"\n", c, str, result);
    else
        printf("O caractere '%c' não foi encontrado em \"%s\".\n", c, str);

    return 0;
}
*/