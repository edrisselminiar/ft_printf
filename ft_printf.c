/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delminia <delminia@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:33:05 by delminia          #+#    #+#             */
/*   Updated: 2025/11/16 10:31:58 by delminia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	format_specifier(char form_spe, va_list args)
{
	if (form_spe == 'd' || form_spe == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (form_spe == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (form_spe == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (form_spe == 'x' || form_spe == 'X')
		return (ft_puthex((va_arg(args, unsigned int)), form_spe));
	else if (form_spe == 'u')
		return (ft_putnbr_unsigned(va_arg(args, unsigned int)));
	else if (form_spe == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (form_spe == '%')
		return (ft_putchar('%'));
	else
		return (ft_putchar('%') + ft_putchar(form_spe));
	return (0);
}

int	ft_printf(const char *form_spe, ...)
{
	va_list	args;
	int		i;
	int		count;

	count = 0;
	va_start(args, form_spe);
	i = 0;
	if (!form_spe)
		return (-1);
	while (form_spe[i])
	{
		if (form_spe[i] == '%')
		{
			i++;
			if (form_spe[i] == '\0')
				return (va_end(args), -1);
			else
				count += format_specifier(form_spe[i], args);
		}
		else
			count += ft_putchar(form_spe[i]);
		i++;
	}
	va_end(args);
	return (count);
}
