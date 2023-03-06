/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gukwon <gukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:12:58 by gukwon            #+#    #+#             */
/*   Updated: 2023/02/09 12:13:01 by gukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_numbers(void);

void	ft_print_numbers(void)
{
	int	num;

	num = 0;
	while (num <= 9)
	{
		write(1, &num, 1);
		num++;
	}
}
int main()
{
	ft_print_numbers();
}