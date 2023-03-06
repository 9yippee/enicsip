/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gukwon <gukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:38:08 by gukwon            #+#    #+#             */
/*   Updated: 2023/02/28 13:38:10 by gukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_board(int *board)
{
	char	c;
	int		i;

	i = 0;
	while (i < 10)
	{
		c = '0' + board[i];
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	queen(int row, int *board, int fix_col)
{
	int	fix_row;
	int	res;
	int	mod;

	fix_row = row;
	row -= 1;
	while (row >= 0)
	{
		if (board[row] == fix_col)
			return (0);
		res = (fix_row - row) / (fix_col - board[row]);
		mod = (fix_row - row) % (fix_col - board[row]);
		if (res == 1 && mod == 0)
			return (0);
		else if (res == -1 && mod == 0)
			return (0);
		row--;
	}
	return (1);
}

int	dfs(int row, int *board, int *cnt)
{
	int	col;

	if (row == 10)
	{
		(*cnt)++;
		print_board(board);
	}
	col = 0;
	while (col < 10)
	{
		if (queen(row, board, col))
		{
			board[row] = col;
			dfs(row + 1, board, cnt);
		}
		col++;
	}
	return (0);
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10];
	int	cnt;

	cnt = 0;
	dfs(0, board, &cnt);
	return (cnt);
}
