/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoo <koomin1227@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 05:56:48 by mkoo              #+#    #+#             */
/*   Updated: 2023/03/01 05:56:52 by mkoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void	p_error(void);
int		file_open(char *f_name);
int		row_len(int fd);
void	map_free(char **map, int size);

int	all_line_check(int len, int fd)
{
	int		r;
	int		cnt;
	int		check;
	char	a;

	check = 1;
	cnt = 0;
	while (1)
	{
		r = read(fd, &a, 1);
		if (r == 0)
			break ;
		cnt++;
		if (a == '\n' && cnt == len)
			cnt = 0;
		else if (a == '\n' && cnt != len)
		{
			check = 0;
			break ;
		}
	}
	return (check);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	create_map(char *f_name, int len)
{
	int		fd;
	int		i;
	char	info[6];
	char	**map;

	fd = file_open(f_name);
	read(fd, info, 5);
	map = (char **) malloc(sizeof(char *) * (info[0] - '0' + 1));
	i = 0;
	while (i < (info[0] - '0'))
	{
		map[i] = (char *) malloc(sizeof(char) * len);
		read(fd, map[i], len);
		map[i][len - 1] = 0;
		i++;
	}
	map[i] = 0;
	i = 0;
	while (i < info[0] - '0')
	{
		ft_putstr(map[i]);
		i++;
	}
	map_free(map, info[0] - '0');
}

void	make_map(char *f_name)
{
	int		fd;
	int		r;
	char	info[6];
	int		len;

	fd = file_open(f_name);
	r = read(fd, info, 5);
	if (r == 0)
		p_error();
	info[5] = 0;
	len = row_len(fd);
	if (len == -1)
		p_error();
	if (all_line_check(len, fd) == 0)
		p_error();
	close(fd);
	create_map(f_name, len);
}

int	main(int argc, char *argv[])
{
	int	i;

	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			make_map(argv[i]);
			i++;
		}
	}
	return (0);
}
