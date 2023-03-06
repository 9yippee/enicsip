/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gukwon <gukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:12:14 by gukwon            #+#    #+#             */
/*   Updated: 2023/02/09 18:04:22 by gukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_comb(void)
{
	char	arr[3];

	arr[0] = '0';
	while (arr[0] <= '7')
	{
		arr[1] = arr[0] + 1;
		while (arr[1] <= '8')
		{
			arr[2] = arr[1] + 1;
			while (arr[2] <= '9')
			{
				write(1, &arr, 3);
				if (arr[0] != '7')
				{
					write(1, ", ", 2);
				}
			arr[2]++;
			}
		arr[1]++;
		}
	arr[0]++;
	}
}
int main()
{
	ft_print_comb();
}