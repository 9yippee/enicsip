/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gukwon <gukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:36:26 by gukwon            #+#    #+#             */
/*   Updated: 2023/02/16 14:36:26 by gukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	unsigned char	c;
	char			*hex;

	hex = "0123456789abcdef";
	while (*str)
	{
		if ((unsigned char) *str >= 32 && (unsigned char) *str <= 126)
		{
			c = (unsigned char) *str;
			write(1, &c, 1);
		}
		else
		{
			write(1, "\\", 1);
			write(1, &hex[(unsigned char) *str / 16], 1);
			write(1, &hex[(unsigned char) *str % 16], 1);
		}
		str++;
	}
}
