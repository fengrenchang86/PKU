#include <iostream>
using namespace std;
int v[10][10], b[10][10];
int a[10];
bool visit[10];
bool flag;
int t[10][2] = {{0, 0}, {1, 1}, {1, 2}, {1, 3}, {2, 1}, {2, 2}, {2, 3}, {3, 1}, {3, 2}, {3, 3}};
void Input()
{
	int i, j;
	for(i = 1; i <= 4; i++)
	{
		for(j = 1; j <= 4; j++)
			scanf("%d", &v[i][j]);
	}
}
void dfs(int lay)
{
	int i;
	if(lay == 10)
	{
		int j, k;
		for(k = 1; k <= 9; k++)
		{
			for(i = 0; i < 2; i++)
			{
				for(j = 0; j < 2; j++)
				{
					b[i+t[a[k]][0]][j+t[a[k]][1]] = a[k];
				}
			}
		}
		for(i = 1; i <= 4; i++)
		{
			for(j = 1; j <= 4; j++)
			{
				if(b[i][j] != v[i][j])
					return;
			}
		}
		flag = true;
		return;
	}
	for(i = 1; i <= 9; i++)
	{
		if(!visit[i])
		{
			visit[i] = true;
			a[lay] = i;
			dfs(lay+1);
			if(flag)
				return;
			visit[i] = false;
		}
	}
}
int main()
{
	char ch[100];
	while(scanf(" %s", &ch) != EOF)
	{
		if(strcmp(ch, "ENDOFINPUT") == 0)
			break;
		memset(visit, false, sizeof(visit));
		Input();
		flag = false;
		dfs(1);
		scanf(" %s", ch);
		if(flag)
			printf("THESE WINDOWS ARE CLEAN\n");
		else
			printf("THESE WINDOWS ARE BROKEN\n");
	}
	return 0;
}