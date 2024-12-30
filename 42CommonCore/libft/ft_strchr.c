/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjose-va <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:24:11 by bjose-va          #+#    #+#             */
/*   Updated: 2024/11/07 17:29:58 by bjose-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	tempc;

	tempc = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == tempc)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == tempc)
		return ((char *)&s[i]);
	return (NULL);
}

/*
int		main(void)
{
	char	s[] = "UVA";
	printf("%c", ft_strchr(s, 85));
}*/