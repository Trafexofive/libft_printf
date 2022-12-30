/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamkadm <mlamkadm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:58:25 by mlamkadm          #+#    #+#             */
/*   Updated: 2022/12/15 16:51:09 by mlamkadm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		ft_putchar('-');
		n = n * -1;
		count++;
	}
	if (n == -2147483648)
		ft_putstr("2147483648");
		count = 11;
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	if (n >= 0 && n <= 9)
		ft_putchar(n + 48);
		count++;
	return (count);
}
