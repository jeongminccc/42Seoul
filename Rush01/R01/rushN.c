/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rushN.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 10:14:16 by jechoi            #+#    #+#             */
/*   Updated: 2020/10/24 17:45:54 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int **g_board; // 답안 board
int g_size; // 입력받은 board의 size
int *g_input; // 입력받은 값들을 저장 ( col_up / col_down / row_left / row_right 순 )
int g_succeed; // 답을 구했으면 1로 초기화

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int	make_row(int row, int input_idx, int i)
{
	if (input_idx < g_size) // input index가col_up 이므로, 위에서 아래로 row값을 변경
		return (1 + i);
	else if (input_idx < g_size * 2) // col_down이므로 아래에서 위로 row값 변경
		return (g_size - i);
	else 				// 이외의 경우 row값은 변하지 않음
		return (row);
}

int	make_col(int col, int input_idx, int i)
{
	if (input_idx < g_size * 2) // 위와 같은 로직
		return (col);
	else if (input_idx < g_size * 3)
		return (1 + i);
	else
		return (g_size - i);
}

int	is_valid_value_sub(int row, int col, int input_idx) // 각각의 조건을 개별로 검사
{
	int i;
	int cnt; // 본 상자의 개수
	int max_val; // 이때까지 본 가장 높은 상자의 높이

	i = -1;
	cnt = 0;
	max_val = -1;
	while (++i < g_size){
		row = make_row(row, input_idx, i); // row index 초기화
		col = make_col(col, input_idx, i); // col index 초기화

/* 신경 쓰지마**********
//		if (g_board[row][col] == 0 && cnt > g_input[input_idx])
//			return (0);
//		else if (g_board[row][col] == 0 && cnt + (4 - i) < g_input[input_idx])
//			return (0);
*/

		if (g_board[row][col] == 0) // 아직 검사하는 줄의 모든 칸이 채워지지 않았다면 true로 넘김
			return (1);
		if (max_val < g_board[row][col]) 
		{
			max_val = g_board[row][col];
			cnt++;
		}
	}
	if (cnt == g_input[input_idx]) // 조건을 만족하면 true
		return (1);
	return (0);
}

int is_valid_value(int row, int col) // 맞닿는 4개의 조건을 검사
{
	int	i;
	int	input_idx;

	i = 0;
	while (++i < 4) // 4개의 조건(2개의 열, 2개의 행) 에 대해 만족하는지 검사
	{
		if (i < 3) // 2개의 col에 대한 검사
			input_idx = (i - 1) * g_size + (col - 1);
		else // 2개의 row에 대한 검사
			input_idx = (i - 1) * g_size + (row - 1);
		if (!is_valid_value_sub(row, col, input_idx)) // 4개의 조건중 하나라도 만족하지 못할시 false 리턴
			return (0);
	}
	return (1);
}

void print_board() // 답 출력
{
	int row;
	int col;

	row = 0;
	while(row++ < g_size)
	{
		col = 0;
		while(col++ < g_size)
		{
			ft_putchar('0' + g_board[row][col]);
			if (col != g_size)
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}

int is_exist(int row, int col, int i) // 지금 넣으려는 값 i가 같은 row, col에 이미 있는지 검사
{
	int idx;

	idx = 0;
	while(++idx < g_size)
	{
		if(g_board[row][idx] == i || g_board[idx][col] == i)
			return (0);
	}
	return (1);
}

void	make_board(int row, int col) // 답안 board를 채우는 함수
{
	int	i;

	if (row == g_size + 1) // 중간에 false를 만나지 않고 board를 모두 다 채웠을때
	{
		print_board();
		g_succeed = 1;
		return ;
	}
	i = 0;
	while (i++ < g_size)
	{
		if(!is_exist(row, col, i)) // board에 채우는 숫자가 이미 그전에 채웠던 숫자와 중복되는지?
			continue; // 중복이면 continue로 밑의 과정 무시하고 넘어감
		g_board[row][col] = i; // board에 값 채움
		if (is_valid_value(row, col) && !g_succeed) // board에 채운 값이 규칙을 만족하는지 검사 (답을 이미 구했는지? 조건검사)
		{
			if (col == g_size)
				make_board(row + 1, 1); // 채우고 다음 board채우러 넘어감(재귀)
			else
				make_board(row, col + 1);
		}
		g_board[row][col] = 0; // board의 값을 다시 뺌 (중간에 false를 만나 종료됬기 때문에)
	}
}

int	rush() // 시작 함수
{
	int i;
	int j;

	g_succeed = 0; // 답 구하면 값이 1로 바뀜
	i = 0;
	while (++i < g_size + 1)
	{
		j = 0;
		while (++j < g_size + 1)
			g_board[i][j] = 0;
	}

	make_board(1,1); // 1,1 인덱스 부터 시작
	i = 0;
	while (i < g_size)
		free(g_board[i++]);
	free(g_input);
	return (g_succeed);
}

void init(char *input)
{
	int pos;
	int size;

	size = 0;
	pos = 0;
	while (input[pos])
	{
		if('1' <= input[pos] && input[pos] <= '9')
			size++;
		pos++;
	}
	g_input = (int*) malloc (sizeof(int) * size);
	size /= 4;
	if (size == 0)
		return ;

	g_size = size;
	g_board = malloc (sizeof(int*) * (size + 1));
	pos = 0;
	while (pos < size + 1)
		g_board[pos++] = malloc (sizeof(int) * (size + 1));
}

int is_valid_input(char *input) // 입력 값이 유효한지 검사
{
	int cnt;
	init(input);

	cnt = 0;
	while (*input)
	{
		if (cnt >= g_size * 4 ) // 16개의 숫자 이상으로 받았을때 false 반환
			return (0);
		if ('1' <= *input && *input <= '0' + g_size) // 1 ~ 4 사이의 값만 받도록
			g_input[cnt++] = *input - '0'; // g_input[] 에 입력값들을 넣어줌
		input++;
	}

	return (cnt == g_size * 4); // 16개의 숫자를 받았다면 true 반환
}
