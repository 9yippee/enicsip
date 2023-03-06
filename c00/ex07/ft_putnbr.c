/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gukwon <gukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:11:39 by gukwon            #+#    #+#             */
/*   Updated: 2023/02/19 14:11:43 by gukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	pn(int nb)
{
	char	a;

	a = (nb % 10) + '0';
	if (nb / 10 != 0)
	{
		pn(nb / 10);
	}
	write(1, &a, 1);
}

void	nn(int nb)
{
	char	a;

	a = -1 * (nb % 10) + '0';
	if (nb / 10 != 0)
	{
		nn(nb / 10);
	}
	write(1, &a, 1);
}

void	ft_putnbr(int nb)
{
	if (nb > 0)
	{
		pn(nb);
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nn(nb);
	}
	if (nb == 0)
	{
		write(1, "0", 1);
	}
}

int main()
{
	ft_putnbr(-2147483648);
	write(1, "\n", 1);
	ft_putnbr(-42);
}