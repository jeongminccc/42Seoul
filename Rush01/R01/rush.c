/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 10:14:16 by jechoi            #+#    #+#             */
/*   Updated: 2020/10/24 21:29:14 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** global variables
** - g_board[i][j] is used for fill the value and make answer
** - g_succeed is for ignore the rest after find first answer
** - and check if are input values valid
*/

int		g_board[5][5];
int		g_succeed;

int		is_valid_value(int row, int col);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_board(void)
{
	int row;
	int col;

	row = 0;
	while (row++ < 4)
	{
		col = 0;
		while (col++ < 4)
		{
			ft_putchar('0' + g_board[row][col]);
			if (col != 4)
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}

/*
** is_exist(int row, int col, int i)
** - function is used for check if value is already in the same row, col
*/

int		is_exist(int row, int col, int i)
{
	int idx;

	idx = 0;
	while (idx++ < 4)
	{
		if (g_board[row][idx] == i || g_board[idx][col] == i)
			return (0);
	}
	return (1);
}

/*
** make_board(int row, int col)
** - fiil the board and find answer
** - check if value is already in the same row and col
** - check if value is satisfy the condition && check answer is already found
** - if value don't satisfy, reset the value to 0
*/

void	make_board(int row, int col)
{
	int	i;

	if (row == 5)
	{
		print_board();
		g_succeed = 1;
		return ;
	}
	i = 0;
	while (i++ < 4)
	{
		if (!is_exist(row, col, i))
			continue;
		g_board[row][col] = i;
		if (is_valid_value(row, col) && !g_succeed)
		{
			if (col == 4)
				make_board(row + 1, 1);
			else
				make_board(row, col + 1);
		}
		g_board[row][col] = 0;
	}
}

/*
** rush()
** - initialize each board value to 0
** - start make_board() in index 1,1
** - if find the answer, return true
*/

int		rush(void)
{
	int i;
	int j;

	g_succeed = 0;
	i = 0;
	while (i++ < 4)
	{
		j = 0;
		while (j++ < 4)
			g_board[i][j] = 0;
	}
	make_board(1, 1);
	return (g_succeed);
}
