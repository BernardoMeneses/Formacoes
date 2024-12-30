/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjose-va <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:53:51 by bjose-va          #+#    #+#             */
/*   Updated: 2024/11/07 17:42:32 by bjose-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *c, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;

	if (start > ft_strlen(c))
		return (ft_strdup(""));
	if (len > ft_strlen(c) - start)
		len = ft_strlen(c) - start;
	subs = (char *)malloc(sizeof(char) * len + 1);
	if (subs == 0)
		return (NULL);
	i = 0;
	while (i < len)
	{
		subs[i] = c[start];
		start++;
		i++;
	}
	subs[i] = 0;
	return (subs);
}
