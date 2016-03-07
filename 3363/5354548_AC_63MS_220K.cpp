#include <iostream>
using namespace std;
char a[120][120];
int n, m, r, c;
void Input()
{
	int i;
	for(i = 0; i < n; i++)
		scanf(" %s", a[i]);
}
bool Change(int x, int y)
{
	if(x + r - 1 >= n)
		return false;
	else if(y + c - 1 >= m)
		return false;
	int i, j;
	for(i = x; i < x + r ; i++)
	{
		for(j = y; j < y + c; j++)
		{
			if(a[i][j] == '0')
				a[i][j] = '1';
			else
				a[i][j] = '0';
		}
	}
	return true;
}
void Solve()
{
	int i, j;
	int ans = 0;
	for(i =0 ; i < n; i++)
	{
		for(j = 0; j < m; j++)
		{
			if(a[i][j] == '1')
			{
				ans ++;
				if(Change(i, j) == false)
				{
					printf("-1\n");
					return;
				}
			}
		}
	}
	printf("%d\n", ans);
}
int main()
{
	while(scanf("%d %d %d %d", &n, &m ,&r, &c) != EOF)
	{
		if(n == 0 && m == 0)
			break;
		Input();
		Solve();
	}
	return 0;
}