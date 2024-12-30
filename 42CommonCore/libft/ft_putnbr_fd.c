/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjose-va <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:50:01 by bjose-va          #+#    #+#             */
/*   Updated: 2024/11/07 18:08:54 by bjose-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -nb;
	}
	if (nb > 9)
		ft_putnbr_fd(nb / 10, fd);
	ft_putchar_fd(nb % 10 + '0', fd);
}
/*
int     main(void)
{
    int     fd;
    
    fd = open("test1.txt", O_CREAT | O_RDWR);
    ft_putnbr_fd(13, fd);
    ft_putchar_fd('\n', fd);
    ft_putnbr_fd(-87, fd);
    ft_putchar_fd('\n', fd);
    ft_putnbr_fd(3, fd);
    ft_putchar_fd('\n', fd);
    ft_putnbr_fd(-472847, fd);
}*/