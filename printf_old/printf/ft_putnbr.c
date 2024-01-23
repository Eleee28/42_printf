/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elena <elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:29:17 by elena             #+#    #+#             */
/*   Updated: 2023/11/13 21:59:37 by elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	if (n / 10 != 0)
		ft_putnbr(n / 10);
	else if (n < 0)
		ft_putchar('-');
	if (n < 0)
		ft_putchar((char){'0' - (n % 10)});
	if (n >= 0)
		ft_putchar((char){'0' + (n % 10)});
	return (count_signed(n, 10));
}
