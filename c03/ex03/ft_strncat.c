/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gukwon <gukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:45:52 by gukwon            #+#    #+#             */
/*   Updated: 2023/02/21 20:45:53 by gukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int	i;

	i = 0;
	while (dest[i])
		i++;
	while (*src && nb > 0)
	{
		dest[i] = *src;
		i++;
		src++;
		nb--;
	}
	dest[i] = '\0';
	return (dest);
}
