/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gukwon <gukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:11:30 by gukwon            #+#    #+#             */
/*   Updated: 2023/02/19 14:11:33 by gukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	comma(char *num1, char *num2)
{
	write (1, num1, 2);
	write (1, " ", 1);
	write (1, num2, 2);
	if ((num1[0] != '9' || num1[1] != '8') || \
	(num2[0] != '9' || num2[1] != '9'))
	{
		write (1, ", ", 2);
	}
}

void	ft_print_comb1(char *num1, char *num2)
{
	while (num2[0] <= '9')
	{
		while (num2[1] <= '9')
		{
			comma(num1, num2);
			num2[1]++;
		}
		num2[0]++;
		num2[1] = '0';
	}
	num1[1]++;
}

void	ft_print_comb2(void)
{
	char	num1[2];
	char	num2[2];

	num1[0] = '0';
	num1[1] = '0';
	while (num1[0] <= '9')
	{
		while (num1[1] <= '9')
		{
			num2[0] = num1[0];
			num2[1] = num1[1] + 1;
			ft_print_comb1(num1, num2);
		}
	num1[0]++;
	num1[1] = '0';
	}
}

i