/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoo <koomin1227@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:45:51 by mkoo              #+#    #+#             */
/*   Updated: 2023/03/01 12:45:54 by mkoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

void	p_error(void)
{
	write(1, "map error\n", 10);
	exit(0);
}

int	file_open(char *f_name)
{
	int	fd;

	fd = open(f_name, O_RDONLY);
	return (fd);
}

int	row_len(int fd)
{
	int		r;
	int		cnt;
	int		check;
	char	a;

	check = 0;
	cnt = 0;
	while (1)
	{
		r = read(fd, &a, 1);
		if (r == 0)
			break ;
		cnt++;
		if (a == '\n')
		{
			check = 1;
			break ;
		}
	}
	if (check == 0)
		return (-1);
	return (cnt);
}

void	map_free(char **map, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(map[i]);
		i++;
	}
	free(map);
}
