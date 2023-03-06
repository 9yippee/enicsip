/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gukwon <gukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 21:38:48 by gukwon            #+#    #+#             */
/*   Updated: 2023/02/27 21:38:49 by gukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	main(int ac, char **av)
{
	int	j;

	while (ac > 1)
	{
		j = ac - 1;
		ft_print(av[j]);
		ac--;
		j--;
		write(1, "\n", 1);
	}
	return (0);
}
