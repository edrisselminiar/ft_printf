/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delminia <delminia@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:31:52 by delminia          #+#    #+#             */
/*   Updated: 2025/11/16 10:59:47 by delminia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nbr)
{
	int	lent;

	lent = 0;
	if (nbr == -2147483648)
		return (ft_putstr("-2147483648"));
	if (nbr < 0)
	{
		nbr = -nbr;
		lent += ft_putchar('-');
	}
	if (nbr > 9)
	{
		lent += ft_putnbr(nbr / 10);
	}
	lent += ft_putchar((nbr % 10) + '0');
	return (lent);
}
