/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunlee <hunlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:22:55 by hunlee            #+#    #+#             */
/*   Updated: 2023/02/13 13:51:28 by gukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	rush(int a, int b);
void	ft_putchar(char c);

int	len_count(char argv[])
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (argv[i] != '\0')
	{
		count++;
		i++;
	}
	return (count);
}

unsigned long long	calculate(int i, char argv[])
{
	unsigned long long		result;

	result = 0;
	while (argv[i] && (argv[i] >= '0' && argv[i] <= '9'))
	{
		if (i == 0 && argv[0] == '-')
		{
			return (0);
		}
		result = result * 10 + (argv[i] - '0');
		i++;
	}
	return (result);
}

int	atoi_(char argv[])
{
	unsigned long long	result;
	int					i;
	int					j;

	result = 0;
	i = 0;
	j = len_count(argv);
	result = calculate(i, argv);
	if (result <= 2147483647 && result > 0)
	{
		return (result);
	}
	else
	{
		return (0);
	}
}

int	main(int argc, char *argv[])
{
	int		x;
	int		y;

	if (argc == 3)
	{
		x = atoi_(argv[1]);
		y = atoi_(argv[2]);
		rush(x, y);
	}
}
