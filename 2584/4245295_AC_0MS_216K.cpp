#include <iostream>
using namespace std;
#define inf 2000000000
int n, m;
int f[50][50];
int dis[50];
int path[50];
bool visit[50];
int Trans(char ch)
{
	if(ch == 'S')
		return 1;
	else if(ch == 'M')
		return 2;
	else if(ch == 'L')
		return 3;
	else if(ch == 'X')
		return 4;
	else
		return 5;
}
void Init()
{
	int i, j;
	for(i = 0; i < 50; i++)
	{
		for(j = 0; j < 50; j++)
			f[i][j] = 0;
	}
	for(i = 0; i < n; i++)
	{
		f[0][i+6] = 1;
	}
}
void Input()
{
	char ch[100];
	int i, j;
	scanf("%d", &n);
	m = n+6;
	Init();
	for(i = 0; i < n; i++)
	{
		scanf(" %s", ch);
		for(j = Trans(ch[0]); j <= Trans(ch[1]); j++)
		{
			f[i+6][j] = 1;
		}
	}
	for(i = 1; i <= 5; i++)
	{
		scanf("%d", &j);
		f[i][n+6] = j;
	}
	scanf(" %s", ch);
}
int dij()
{
	memset(visit, false, sizeof(visit));
	int i, j, k, tmin;
	for(i = 0; i <= m; i++)
	{
		dis[i] = inf;
		path[i] = -1;
	}
	dis[0] = 0;
	for(i = 0; i <= m; i++)
	{
		tmin = inf;
		for(j = 0; j <= m; j++)
		{
			if(!visit[j] && dis[j] < tmin)
			{
				tmin = dis[j];
				k = j;
			}
		}
		if(tmin == inf)
			break;
		visit[k] = true;
		for(j = 0; j <= m; j++)
		{
			if(!visit[j] && f[k][j] > 0 && dis[j] > dis[k] + f[k][j])
			{
				dis[j] = dis[k] + f[k][j];
				path[j] = k;
			}
		}
	}
	if(dis[m] == inf)
		return 0;
	k = inf;
	j = m;
	while(path[j] != -1)
	{
		if(f[path[j]][j] < tmin)
			tmin = f[path[j]][j];
		j = path[j];
	}
	j = m;
	while(path[j] != -1)
	{
		f[path[j]][j] -= tmin;
		f[j][path[j]] += tmin;
		j = path[j];
	}
	return tmin;
}
void Solve()
{
	int k = 0, j = 1;
	while(j)
	{
		j = dij();
		k += j;
	}
	if(k == n)
		printf("T-shirts rock!\n");
	else
		printf("I'd rather not wear a shirt anyway...\n");
}
int main()
{
	char ch[100];
	while(scanf(" %s", &ch))
	{
		if(strcmp(ch, "ENDOFINPUT") == 0)
			break;
		Input();
		Solve();
	}
	return 0;
}
