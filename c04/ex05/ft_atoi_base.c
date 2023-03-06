/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gukwon <gukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:24:25 by gukwon            #+#    #+#             */
/*   Updated: 2023/02/27 16:49:37 by gukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	base_len(char *base)
{
	int	len;

	len = 0;
	while (base[len])
	{
		if (base[len] == '-' || base[len] == '+')
			return (0);
		if (base[len] == ' ' || (base[len] >= 9 && base[len] <= 13))
			return (0);
		len++;
	}
	return (len);
}

int	check(int len, char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	getindex(char c, int len, char *base)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	j;
	int	result;
	int	len;

	len = base_len(base);
	result = 0;
	j = 1;
	if (len < 2)
		return (0);
	if (check(len, base))
		return (0);
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	while (*str == '+' || *str == '-')
		if (*(str++) == '-')
			j *= -1;
	while (*str)
	{
		i = getindex(*(str++), len, base);
		if (i == -1)
			break ;
		result = len * result + i;
	}
	return (j * result);
}
