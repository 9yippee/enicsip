/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gukwon <gukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 21:35:24 by gukwon            #+#    #+#             */
/*   Updated: 2023/02/27 21:35:27 by gukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void	print_board(int *board)
{
	char	a;
	int		i;

	i = 0;
	while (i < 10)
	{
		a = '0' + board[i];
		write(1, &a, 1);
		i++;
	}
	write(1, "\n", 1);
}
int	check(int depth, int *board, int target)
{
	int	i;
	int	share;
	int	modu;

	i = depth - 1;
	while (i >= 0)
	{
		if (board[i] == target)
			return (0);
		share = (i - depth) / (board[i] - target);
		modu = (i - depth) % (board[i] - target);
		if (share == 1 && modu == 0)
			return (0);
		else if (share == -1 && modu == 0)
			return (0);
		i--;
	}
	return (1);
}
void	dfs(int depth, int *board, int *cnt)
{
	int	i;
	if (depth == 10)
	{
		(*cnt)++;
		print_board(board);
	}
	i = 0;
	while (i < 10)
	{
		if (check(depth, board, i) == 1)
		{
			board[depth] = i;
			dfs(depth + 1, board, cnt);
			board[depth] = -1;
		}
		i++;
	}
}
int	ft_ten_queens_puzzle(void)
{
	int	board[10];
	int	cnt;
	cnt = 0;
	dfs(0, board, &cnt);
	return (cnt);
}
#include <stdio.h>
int main()
{
	printf("%d",ft_ten_queens_puzzle());
}