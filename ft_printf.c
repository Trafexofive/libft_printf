/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamkadm <mlamkadm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:56:57 by mlamkadm          #+#    #+#             */
/*   Updated: 2022/12/15 16:52:34 by mlamkadm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"


static int	ft_check_percent(int c)
{
	if (c == '%')
		return (1);
	return (0);
}

static int	ft_check_specifier(int c)
{
	if (c == 'c')
		return (1);
	if (c == 's')
		return (2);
	if (c == 'p')
		return (3);
	if (c == 'd')
		return (4);
	if (c == 'i')
		return (5);
	if (c == 'u')
		return (6);
	if (c == 'x')
		return (7);
	if (c == 'X')
		return (8);
	if (c == '%')
		return (9);
	return (0);
}


int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, format);

	while (format[i])
	{
		if (ft_check_percent(format[i]) == 1)
		{
			i++;
			if (ft_check_specifier(format[i]) == 1)
				count = count + ft_putchar(va_arg(args, int));
			else if (ft_check_specifier(format[i]) == 2)
				count = count + ft_putstr(va_arg(args, const char *));
			else if (ft_check_specifier(format[i]) == 4)
				count = count + ft_putnbr(va_arg(args, int));
			else if (ft_check_specifier(format[i]) == 5)
				count = count + ft_putnbr(va_arg(args, int));
			else if (ft_check_specifier(format[i]) == 6)
				count = count + ft_putnbr_unsigned(va_arg(args, unsigned int));
				
		}
		else if(ft_check_percent(format[i]) == 0)
			count = count + ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}


// int main(void)
// {
// 	// char	str[] = "hello_world";
// 	// char	str1[] = "hello_world1";

// 	// ft_printf("My printf:\nnum:%d %s %s", 1234, str, str1);
// 	printf("\nSystem printf:\nnum:%d", 1234);
// }