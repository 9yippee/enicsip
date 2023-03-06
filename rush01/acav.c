#include <stdio.h>

int	board_size(char *str) //board size = 4
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '4')
			size++;
		i++;
	}
	return (size / 4);
}

int	*get_num(char *str, int *num)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] >= '1' && str[i] <= '4')
		{
			num[j] = str[i] - '0';
			j++;
		}
		i++;
	}
	return (num);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_ag(int size, char **a, int argc)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (argc != 2)
		return (0);
	if ((ft_strlen(a[1]) != (size * 8) - 1))
		return (0);
	while (a[1][i])
	{
		if (a[1][i] != ' ')
			return (0);
		i += 2;
		if (!((a[1][j]) >= '1' && a[1][j] <= '4'))
			return (0);
		j += 2;
	}
	printf("%s\n", a[1]);
	return (1);
}

int	main(int argc, char **argv)
{
	int		i;
	char	*a;

	// i = check_ag(2, argv[1], 4);
	check_ag(4, argv, argc);
	
}