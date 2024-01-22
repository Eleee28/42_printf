/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:02:28 by ejuarros          #+#    #+#             */
/*   Updated: 2024/01/22 11:29:12 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/** @brief Convert a number to string
 * 
 *  @details Consider if the number is negative. Add zeroes at the beggining 
 *  to match the length.
 * 
 *  @param n number to convert
 *  @param len length of the string
 *  @param sign sign flag
 *  @param str string where the converted number is stored
 * 
 *  @return void
*/
static void	ft_num_to_str(int n, int len, char sign, char *str)
{
	int	i;

	str[len] = 0;
	i = 1;
	while (n != 0)
	{
		if (n < 0)
			str[len - i] = "0123456789"[-(n % 10)];
		else
			str[len - i] = "0123456789"[n % 10];
		n /= 10;
		i++;
	}
	while (i <= len)
	{
		str[len - i] = '0';
		i++;
	}
	if (sign)
		str[0] = sign;
}

/** @brief Print a number
 * 
 *  @details 
 * 
 *  @param flags structure that stores flags information
 *  @param n number to print
 * 
 *  @return string to print taking into account the flags
 * 
*/
char	*ft_putnbr(t_flags *flags, int n)
{
	int		len;
	char	*str;

	if (n < 0)
		flags->sign = '-';
	len = ft_numlen(n, 10);
	if (!flags->precision && !n)
		len = 0;
	else if (flags->precision >= len)
		len = flags->precision;
	else if (flags->precision < 0 && flags->justified == '0')
	{
		if (flags->sign && flags->width - 1 >= len)
			len = flags->width - 1;
		if (!flags->sign && flags->width >= len)
			len = flags->width;
	}
	if (flags->sign)
		len += 1;
	str = (char *)malloc((len + 1) * sizeof(char));
	ft_num_to_str(n, len, flags->sign, str);
	return (str);
}