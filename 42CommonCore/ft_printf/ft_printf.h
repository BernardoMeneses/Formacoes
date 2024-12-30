/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjose-va <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:58:37 by bjose-va          #+#    #+#             */
/*   Updated: 2024/12/21 17:22:18 by bjose-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

# define TRUE 1
# define FALSE 0

int ft_putptr_fd(void *ptr, int fd);
int ft_putnbr_unsigned_fd(unsigned int n, int fd);
int ft_putnbr_hex_fd(unsigned int n, char format, int fd);
int ft_printf(const char *, ...);

#endif