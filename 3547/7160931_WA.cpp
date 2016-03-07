#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m;
int a[102][102];
int acm[100][102][102];
int Line4heng(int x, int y)//打横4个
{
	if (x == 0 || x == n-1 || y+3 >= m)
	{
		return -1000000000;
	}
	int t = -1000000000;
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (a[x-1][y+i] + a[x+1][y+j] > t)
				t = a[x-1][y+i] + a[x+1][y+j];
		}
	}
	return t + a[x][y] + a[x][y+1] + a[x][y+2] + a[x][y+3];
}
int Line4shu(int x, int y)
{
	if (y == 0 || y == m-1 || x+3 >= n)
	{
		return -1000000000;
	}
	int t = -1000000000;
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (a[x+i][y-1] + a[x+j][y+1] > t)
				t = a[x+i][y-1] + a[x+j][y+1];
		}
	}
	return t + a[x][y] + a[x+1][y] + a[x+2][y] + a[x+3][y];
}
int Line3heng(int x, int y)
{
	int i, s, t = -1000000000;
	if (x == 0 || x == n-1)
	{
		return -1000000000;
	}
	if (y > 0)
	{
		s = a[x-1][y] + a[x-1][y-1];
		for (i = 0; i < 3; i++)
		{
			if(s+a[x+1][y+i]>t)
				t=s+a[x+1][y+i];
		}
		s = a[x+1][y] + a[x+1][y-1];
		for (i = 0; i < 3; i++)
		{
			if(s+a[x-1][y+i]>t)
				t=s+a[x-1][y+i];
		}
	}
	if (y+3 < m)
	{
		s = a[x-1][y+2] + a[x-1][y+3];
		for (i = 0; i < 3; i++)
		{
			if(s+a[x+1][y+i]>t)
				t=s+a[x+1][y+i];
		}
		s = a[x+1][y+2] + a[x+1][y+3];
		for (i = 0; i < 3; i++)
		{
			if(s+a[x-1][y+i]>t)
				t=s+a[x-1][y+i];
		}
	}
	return t;
}
int Line3shu(int x, int y)
{
	int i, s, t = -1000000000;
	if (y == 0 || y == m-1)
	{
		return -1000000000;
	}
	if (x > 0)
	{
		s = a[x-1][y-1] + a[x][y-1];
		for (i = 0; i < 3; i++)
		{
			if (s+a[x+i][y+1] > t)
				t = s+a[x+i][y+1];
		}
		s = a[x-1][y+1] + a[x][y+1];
		for (i = 0; i < 3; i++)
		{
			if(s+a[x+i][y-1]>t)
				t=s+a[x+i][y-1];
		}
	}
	if (x + 3 < n)
	{
		s = a[x+2][y-1] + a[x+3][y-1];
		for (i = 0; i < 3; i++)
		{
			if(s+a[x+i][y+1] > t)
				t=s+a[x+i][y+1];
		}
		s = a[x+2][y+1] + a[x+3][y+1];
		for (i = 0; i < 3; i++)
		{
			if(s+a[x+i][y-1]>t)
				t=s+a[x+i][y-1];
		}
	}
	return t;
}
int Line3(int x, int y)
{
	int s, t = -1000000000;
	if (y + 2 < m)
	{
		s = a[x][y] + a[x][y+1] + a[x][y+2];
		if (x >= 1 && y >= 2)
		{
			if (s + a[x-1][y] + a[x-1][y-1] + a[x-1][y-2] > t)
			{
				t = s + a[x-1][y] + a[x-1][y-1] + a[x-1][y-2];
			}
		}
		if (x >= 1 && y+4 < m)
		{
			if (s + a[x-1][y+2] + a[x-1][y+3] + a[x-1][y+4] > t)
			{
				t = a[x-1][y+2] + a[x-1][y+3] + a[x-1][y+4];
			}
		}
		if (x + 1 < n && y >= 2)
		{
			if (s + a[x+1][y] + a[x+1][y-1] + a[x+1][y-2] > t)
			{
				t = s + a[x+1][y] + a[x+1][y-1] + a[x+1][y-2];
			}
		}
		if (x + 1 < n && y + 4 < m)
		{
			if (s + a[x+1][y+2] + a[x+1][y+3] + a[x+1][y+4] > t)
			{
				t = a[x+1][y+2] + a[x+1][y+3] + a[x+1][y+4];
			}
		}
	}
	if (x + 2 < n)
	{
		s = a[x][y] + a[x+1][y] + a[x+2][y];
		if (y > 0 && x-2 >= 0)
		{
			if (s + a[x][y-1] + a[x-1][y-1] + a[x-2][y-1] > t)
			{
				t = s + a[x][y-1] + a[x-1][y-1] + a[x-2][y-1];
			}
		}
		if (y + 1 < m && x-2 >= 0)
		{
			if (s + a[x][y+1] + a[x-1][y+1] + a[x-2][y+1] > t)
			{
				t = s + a[x][y+1] + a[x-1][y+1] + a[x-2][y+1];
			}
		}
		if (y > 0 && x+4 < n)
		{
			if (s + a[x+2][y-1] + a[x+3][y-1] + a[x+4][y-1] > t)
			{
				t = s + a[x+2][y-1] + a[x+3][y-1] + a[x+4][y-1];
			}
		}
		if (y + 1 < m && x + 4 < n)
		{
			if (s + a[x+2][y+1] + a[x+3][y+1] + a[x+4][y+1] > t)
			{
				t = s + a[x+2][y+1] + a[x+3][y+1] + a[x+4][y+1];
			}
		}
	}
	return t;
}
int Line2(int x, int y)
{
	int s, t = -1000000000;
	if (x + 2 >= n)
	{
		return t;
	}
	if (y+1 < m && y > 1)
	{
		s = a[x][y] + a[x][y+1] + a[x+1][y] + a[x+1][y-1] + a[x+2][y-1] + a[x+2][y-2];
		if (s > t)
			t = s;
	}
	if (y + 3 < m)
	{
		s = a[x][y] + a[x][y+1] + a[x+1][y+1] + a[x+1][y+2] + a[x+2][y+2] + a[x+2][y+3];
		if (s > t)
			t = s;
	}
	if (x + 3 < n && y - 2 >= 0)
	{
		s = a[x][y] + a[x+1][y] + a[x+1][y-1] + a[x+2][y-1] + a[x+2][y-2] + a[x+3][y-2];
		if (s > t)
			t = s;
	}
	if (x + 3 < n && y + 2 < m)
	{
		s = a[x][y] + a[x+1][y] + a[x+1][y+1] + a[x+2][y+1] + a[x+2][y+2] + a[x+3][y+2];
		if (s > t)
			t = s;
	}
	return t;
}
void Input()
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
}
void Solve()
{
	int ans = -1000000000;
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			k = Line4heng(i, j);
			if(k > ans)
				ans = k;
			k = Line4shu(i, j);
			if(k > ans)
				ans = k;
			k = Line3heng(i, j);
			if (k > ans)
				ans = k;
			k = Line3shu(i, j);
			if (k > ans)
				ans = k;
			k = Line3(i, j);
			if (k > ans)
				ans = k;
			k = Line2(i, j);
			if (k > ans)
				ans = k;
			ans = ans;
		}
	}
	printf("%d\n", ans);
}
int main()
{
	while (scanf("%d %d", &n, &m) != EOF)
	{
		Input();
		Solve();
	}
	return 0;
}