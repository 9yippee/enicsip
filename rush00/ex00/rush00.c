/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunlee <hunlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:13:22 by hunlee            #+#    #+#             */
/*   Updated: 2023/02/12 18:45:15 by sunmikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	width_first(int x)
{
	int	i;

	i = 0;
	ft_putchar('o');
	while (i < x - 2)
	{
		ft_putchar('-');
		i++;
	}
	ft_putchar('o');
	ft_putchar('\n');
}

void	width_last(int x)
{
	int	i;

	i = 0;
	ft_putchar('o');
	while (i < x - 2)
	{
		ft_putchar('-');
		i++;
	}
	ft_putchar('o');
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
		ft_putchar('|');
		while (j < x - 2)
		{
			ft_putchar(' ');
			j++;
		}
		ft_putchar('|');
		ft_putchar('\n');
		i++;
	}
	width_last(x);
}

void	only_height(int y)
{
	int	i;

	i = 0;
	ft_putchar('o');
	ft_putchar('\n');
	while (i < y - 2)
	{
		ft_putchar('|');
		ft_putchar('\n');
		i++;
	}
	ft_putchar('o');
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	if (x == 1 && y == 1)
	{
		ft_putchar('o');
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
