/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjose-va <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:52:54 by bjose-va          #+#    #+#             */
/*   Updated: 2024/11/07 17:34:20 by bjose-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	p = malloc(size * nmemb);
	if (p)
		ft_bzero(p, nmemb * size);
	return (p);
}
/*
 int  main(void)                         
 {                                                                             
    printf("%s", ft_calloc(3, 6);     
    return (0);                        
 }                                                                               
*/
