/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkrawczy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 13:15:53 by dkrawczy          #+#    #+#             */
/*   Updated: 2022/03/15 13:21:13 by dkrawczy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_arg(char c, va_list ap, int *i)
{
	if (c == 'c')
		*i += ft_putchar(va_arg(ap, int));
	else if (c == 's')
		*i += ft_putstr(va_arg(ap, char *));
	else if (c == 'p')
	{
		ft_putstr("0x");
		*i += 2;
		*i += ft_hex(va_arg(ap, unsigned long), 1);
	}
	else if (c == 'd' || c == 'i')
		*i += ft_putnbr(va_arg(ap, int));
	else if (c == 'u')
		*i += ft_uint(va_arg(ap, unsigned int));
	else if (c == 'x')
		*i += ft_hex(va_arg(ap, unsigned int), 1);
	else if (c == 'X')
		*i += ft_hex(va_arg(ap, unsigned int), 0);
	else if (c == '%')
		*i += ft_putchar('%');
	else
		*i += ft_putchar(c);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	ap;

	i = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				return (i);
			ft_arg(*format, ap, &i);
		}
		else
		{
			ft_putchar(*format);
			i++;
		}
		format++;
	}
	va_end(ap);
	return (i);
}
