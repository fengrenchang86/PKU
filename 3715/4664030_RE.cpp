#include <iostream>
using namespace std;
int c[210][210];
int d[210][210];
int Num[210];
int position[210];
int BeforeDel[210];
int n, m;
void Input()
{
	int i, j, x, y;
	scanf("%d %d", &n, &m);
	for(i = 0; i <= n; i++)
	{
		for(j = 0; j <= m; j++)
			c[i][j] = 0;
	}
	for(i = 0; i < n; i++)
	{
		scanf("%d", &position[i]);
	}
	for(i = 0; i < m; i++)
	{
		scanf("%d %d", &x, &y);
		c[x][y] = 1;
		c[y][x] = 1;
	}
	for(i = 0; i < n; i++)
	{
		Num[i] = 0;
		for(j = 0; j < n; j++)
		{
			if(c[i][j] == 1)
				d[i][Num[i]++] = j;
		}
	}
}
void Solve()
{
	int i, j, k, acMax, acMaxPos;
	int ans = 0;
	for(i = 0; i < n; i++)
	{
		BeforeDel[i] = 0;
	}
	while(1)
	{
		acMax = 0;
		for(i = 0; i < n; i++)
		{
			if(BeforeDel[i] == -1)
				continue;
			BeforeDel[i] = 0;
			for(j = 0; j < Num[i]; j++)
			{
				if(BeforeDel[d[i][j]] == -1)
					continue;
				if(position[i] != position[d[i][j]])
					BeforeDel[i]++;
			}
			if(BeforeDel[i] > acMax)
			{
				acMax = BeforeDel[i];
				acMaxPos = i;
			}
		}
		if(acMax == 0)
			break;
		BeforeDel[acMaxPos] = -1;
		ans++;
		
	}
	printf("%d", ans);
	for(i = 0; i < n; i++)
	{
		if(BeforeDel[i] == -1)
			printf(" %d", i);
	}
	printf("\n");
}
int main()
{
	int tc;
	scanf("%d", &tc);
	while(tc--)
	{
		Input();
		Solve();
	}
	return 0;
}