/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunlee <hunlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:17:05 by hunlee            #+#    #+#             */
/*   Updated: 2023/02/12 18:51:19 by sunmikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	width_first(int x)
{
	int	i;

	i = 0;
	ft_putchar('A');
	while (i < x - 2)
	{
		ft_putchar('B');
		i++;
	}
	ft_putchar('C');
	ft_putchar('\n');
}

void	width_last(int x)
{
	int	i;

	i = 0;
	ft_putchar('C');
	while (i < x - 2)
	{
		ft_putchar('B');
		i++;
	}
	ft_putchar('A');
	ft_putchar('\n');
}

void	rectangle(int x, int y)
{
	int	i;
	int	j;

	i = 1;
	width_first(x);
	while (i < y - 1)
	{
		j = 0;
		ft_putchar('B');
		while (j < x - 2)
		{
			ft_putchar(' ');
			j++;
		}
		ft_putchar('B');
		ft_putchar('\n');
		i++;
	}
	width_last(x);
}

void	only_height(int y)
{
	int	i;

	i = 0;
	ft_putchar('A');
	ft_putchar('\n');
	while (i < y - 2)
	{
		ft_putchar('B');
		ft_putchar('\n');
		i++;
	}
	ft_putchar('C');
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	if (x == 1 && y == 1)
	{
		ft_putchar('A');
		ft_putchar('\n');
	}
	else if (x <= 0 || y <= 0)
	{
	}
	else if (x == 1 && y > 1)
	{
		only_height(y);
	}
	else if (x > 1 && y == 1)
	{
		width_first(x);
	}
	else
	{
		rectangle(x, y);
	}
}
