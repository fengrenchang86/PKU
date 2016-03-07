#include <iostream>
#include <string>
using namespace std;

struct CSudokuMarix
{
	int nValue;
	bool bCanFill[10];
}m_kArrCol[9], m_kArrRow[9], m_kArrBlock[9];
CSudokuMarix m_kSudokuMarix[9][9];
bool m_bSolve;
int NextXY(int *x, int *y)
{
	(*y)++;
	if (*y == 9)
	{
		(*x)++;
		*y = 0;
		if (*x < 9)
		{
			return 1;
		}
		else
			return 0;
	}
	else if (*y < 9)
	{
		return 1;
	}
	return 0;
}
int CountBlockId(int x, int y)
{
	int k = (x/3) * 3 + (y/3);
	return k;
}
int Solve(int x, int y)
{
	if (m_bSolve)
	{
		return 0;
	}
	if (NextXY(&x, &y) == false)
	{
		m_bSolve = true;
		int i, j;
		for (i = 0; i < 9; i++)
		{
			for (j = 0; j < 9; j++)
			{
				printf("%d",m_kSudokuMarix[i][j].nValue);
			}
		}
		printf("\n");
		return 0;
	}
	if (m_kSudokuMarix[x][y].nValue != 0)
	{
		Solve(x, y);
		return 0;
	}
	
	int i, j;
	for (i = 1; i <= 9; i++)
	{
		j = CountBlockId(x, y);
		if (m_kArrRow[x].bCanFill[i] || m_kArrCol[y].bCanFill[i] || m_kArrBlock[j].bCanFill[i] /*|| m_kSudokuMarix[x][y].bCanFill[i]*/)
		{
			continue;
		}
		m_kArrBlock[j].bCanFill[i] = true;
		m_kArrRow[x].bCanFill[i] = true;
		m_kArrCol[y].bCanFill[i] = true;
		m_kSudokuMarix[x][y].nValue = i;
		Solve(x, y);
		m_kSudokuMarix[x][y].nValue = 0;
		if (m_bSolve)
		{
			return 1;
		}
		m_kArrBlock[j].bCanFill[i] = false;
		m_kArrRow[x].bCanFill[i] = false;
		m_kArrCol[y].bCanFill[i] = false;
	}
	return 1;
}
int main()
{
	char str[1000];
	int i, j, k, x = 0, y = 0;
	while (scanf("%s", &str) != EOF)
	{
		if (strcmp(str, "end") == 0)
		{
			break;
		}
		x = y = 0;
		for (i = 0; i < 9; i++)
		{
			for (j = 0; j < 9; j++)
			{
				memset(m_kSudokuMarix[i][j].bCanFill, false, sizeof(m_kSudokuMarix[i][j].bCanFill));
				m_kSudokuMarix[i][j].nValue = 0;
			}
		}
		for (i = 0; i < 9; i++)
		{
			memset(m_kArrBlock[i].bCanFill, false, sizeof(m_kArrBlock[i].bCanFill));
			memset(m_kArrCol[i].bCanFill, false, sizeof(m_kArrCol[i].bCanFill));
			memset(m_kArrRow[i].bCanFill, false, sizeof(m_kArrRow[i].bCanFill));
		}
		for (i = 0; i < 81; i++)
		{
			if (str[i] == '.')
			{
				m_kSudokuMarix[x][y].nValue = 0;
			}
			else
				m_kSudokuMarix[x][y].nValue = (str[i] - '0');
			NextXY(&x, &y);
		}
		for (i = 0; i < 9; i++)
		{
			for (j = 0; j < 9; j++)
			{
				if (m_kSudokuMarix[i][j].nValue == 0)
				{
					continue;
				}
				m_kArrRow[i].bCanFill[m_kSudokuMarix[i][j].nValue] = true;
				m_kArrCol[j].bCanFill[m_kSudokuMarix[i][j].nValue] = true;
				k = CountBlockId(i, j);
				m_kArrBlock[k].bCanFill[m_kSudokuMarix[i][j].nValue] = true;
			}
		}
		m_bSolve = false;
		Solve(0, -1);
		
	}
	return 0;
}