#ifndef UNISTD_H
# define UNISTD_H
# include <unistd.h>
#endif

int g_board[5][5];
extern int g_chk_row[5][5];
extern int g_chk_col[5][5];
extern int g_condition[16];
extern int *g_start_ptr[4];
extern int g_offset[4][2];

int		is_valid_board(void);
int		fill_board(int r, int c);
void	ft_putchar(char c);

/*
** This Function shows the height of the elements if found the answer.
*/

void	print_board(void)
{
	int r;
	int c;

	r = 0;
	while (++r < 5)
	{
		c = 0;
		while (++c < 4)
		{
			ft_putchar('0' + g_board[r][c]);
			ft_putchar(' ');
		}
		ft_putchar('0' + g_board[r][c]);
		ft_putchar('\n');
	}
}

int		fill_board_sub(int r, int c)
{
	int val;

	val = 0;
	while (++val < 5)
	{
		if (g_chk_row[r][val] || g_chk_col[c][val])
			continue ;
		g_chk_row[r][val] = 1;
		g_chk_col[c][val] = 1;
		g_board[r][c] = val;
		if (fill_board(r, c + 1))
			return (1);
		g_chk_row[r][val] = 0;
		g_chk_col[c][val] = 0;
	}
	return (0);
}

int		fill_board(int r, int c)
{
	if (r == 5)
	{
		if (is_valid_board())
		{
			print_board();
			return (1);
		}
		return (0);
	}
	if (c == 5)
		return (fill_board(r + 1, 1));
	else
		return (fill_board_sub(r, c));
}

/*
** void init(void)
**
** This function sets the global variables that are declared at the top of the
** file. By using this function, global variables are set appropriately for the
** other functions that uses them.
**
** Global Variables set in this function
** - int g_chk_row[i][j] : set all values to 0. Which is opening all grids of
**   board to get box height of 'j' on row 'i'
** - int g_chk_col[i][j] : set all values to 0. Which is opening all grids of
**   board to get box height of 'j' on column 'i'
** - int *g_start_ptr[0] : Starting point of column-checking('up' to 'down').
**   Which is coordinate (1,1)
** - int *g_start_ptr[1] : Starting point of column-checking('down' to 'up').
**   Which is coordinate (4,1)
** - int *g_start_ptr[2] : Starting point of row-checking('left' to 'right').
**   Which is coordinate (1,1)
** - int *g_start_ptr[3] : Starting point of row-checking('right' to 'left').
**   Which is coordinate (1,4)
** - int g_offset[0][0] : (While 'up' to 'down' column-checking) Increment of
**   the address to move to next column. Which is +5
** - int g_offset[0][1] : (While 'up' to 'down' column-checking) Increment of
**   the address to move to next row. Which is +1
** - int g_offset[1][0] : (While 'down' to 'up' column-checking) Increment of
**   the address to move to next column. Which is -5
** - int g_offset[1][1] : (While 'down' to 'up' column-checking) Increment of
**   the address to move to next row. Which is +1
** - int g_offset[2][0] : (While 'left' to 'right' row-checking) Increment of
**   the address to move to next row. Which is +1
** - int g_offset[2][1] : (While 'left' to 'right' row-checking) Increment of
**   the address to move to next column. Which is +5
** - int g_offset[3][0] : (While 'right' to 'left' row-checking) Increment of
**   the address to move to next row. Which is -1
** - int g_offset[3][1] : (While 'right' to 'left' row-checking) Increment of
**   the address to move to next column. Which is +5
*/

void	init(void)
{
	int i;
	int j;

	i = 0;
	while (++i < 5)
	{
		j = 0;
		while (++j < 5)
		{
			g_chk_row[i][j] = 0;
			g_chk_col[i][j] = 0;
		}
	}
	g_start_ptr[0] = &g_board[1][1];
	g_start_ptr[1] = &g_board[4][1];
	g_start_ptr[2] = &g_board[1][1];
	g_start_ptr[3] = &g_board[1][4];
	g_offset[0][0] = 5;
	g_offset[0][1] = 1;
	g_offset[1][0] = -5;
	g_offset[1][1] = 1;
	g_offset[2][0] = 1;
	g_offset[2][1] = 5;
	g_offset[3][0] = -1;
	g_offset[3][1] = 5;
}

int		rush(void)
{
	init();
	return (fill_board(1, 1));
}