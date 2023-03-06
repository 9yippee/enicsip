/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gukwon <gukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:46:23 by gukwon            #+#    #+#             */
/*   Updated: 2023/02/21 20:46:24 by gukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	ds;
	unsigned int	ss;
	unsigned int	i;

	ds = 0;
	ss = 0;
	i = 0;
	while (dest[ds])
		ds++;
	while (src[ss])
		ss++;
	if (size <= ds)
		ss += size;
	else
		ss += ds;
	while (src[i] && ds + 1 < size)
		dest[ds++] = src[i++];
	dest[ds] = '\0';
	return (ss);
}
