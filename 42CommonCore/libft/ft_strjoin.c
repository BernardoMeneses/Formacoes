/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjose-va <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:17:02 by bjose-va          #+#    #+#             */
/*   Updated: 2024/11/07 17:42:59 by bjose-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*endstr;
	int		i;
	int		j;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	endstr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (endstr == 0)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		endstr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		endstr[i++] = s2[j++];
	}
	endstr[i] = 0;
	return (endstr);
}
