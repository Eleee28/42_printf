/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putargs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 09:59:29 by ejuarros          #+#    #+#             */
/*   Updated: 2024/01/23 09:32:39 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/** @brief Print string
 * 
 *  @details If flag '-' is not present print as many ' ' as the width 
 *  (depending on length). Then, print the string and after that, if the flag 
 *  '-' is present, print as many ' ' as the width (depending on length).
 *  Free the memory at the end.
 * 
 *  @param len length of the printed output
 *  @param flags structure that stores flags information
 *  @param str string to print
 * 
 *  @return void 
*/
static void	ft_printstr(int *len, t_flags *flags, char *str)
{
	int	strlen;
	int	i;

	if (!str)
		return ;
	strlen = ft_strlen(str);
	i = 0;
	while (flags->justified != '-' && i + strlen < flags->width)
	{
		ft_printchar(len, ' ');
		i++;
	}
	i = 0;
	while (str && str[i])
	{
		ft_printchar(len, str[i]);
		i++;
	}
	i = 0;
	while (flags->justified == '-' && i + strlen < flags->width)
	{
		ft_printchar(len, ' ');
		i++;
	}
	free(str);
}

/** @brief Print the arguments
 * 
 *  @details Call the corresponding function depending on the argument type.
 * 
 *  @param len length of the printed output
 *  @param flags structure that stores flags information
 *  @param args argements of the ft_printf call
 * 
 *  @return void
*/
void	ft_putargs(int *len, t_flags *flags, va_list args)
{
	char	*str;

	str = 0;
	if (flags->args == 'c')
		ft_putchar(flags, len, va_arg(args, int));
	else if (flags->args == 's')
		str = ft_putstr(flags->precision, va_arg(args, char *));
	else if (flags->args == 'p')
		str = ft_putptr(flags, va_arg(args, unsigned long int));
	else if (flags->args == 'd' || flags->args == 'i')
		str = ft_putnbr(flags, va_arg(args, int));
	else if (flags->args == 'u')
		str = ft_putunsig(flags, va_arg(args, unsigned int));
	else if (flags->args == 'x')
		str = ft_puthex_low(flags, va_arg(args, unsigned int));
	else if (flags->args == 'X')
		str = ft_puthex_up(flags, va_arg(args, unsigned int));
	else if (flags->args == '%')
		ft_putchar(flags, len, '%');
	ft_printstr(len, flags, str);
}