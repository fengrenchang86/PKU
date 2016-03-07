#include<iostream>
using namespace std;
struct POINT
{
	double x, y;
}gopher[120], hole[120];
bool c[120][120];
int X[120], Y[120];
bool visit[120];
int n, m, s, v;

bool dfs(int u)
{
	int i;
	for(i = 0; i < m; i++)
	{
		if(c[u][i] && !visit[i])
		{
			visit[i] = true;
			if(Y[i] == -1 || dfs(Y[i]))
			{
				Y[i] = u;
				X[u] = i;
				return true;
			}
		}
	}
	return false;
}
int MaxMatch()
{
	int i, k = 0;
	memset(X, -1, sizeof(X));
	memset(Y, -1, sizeof(Y));
	for(i = 0; i < n; i++)
	{
		if(X[i] == -1)
		{
			memset(visit, false, sizeof(visit));
			if(dfs(i))
				k++;
		}
	}
	return k;
}
void MissHH()
{
	int i, j;
	for(i = 0; i < n; i++)
		scanf("%lf %lf", &gopher[i].x, &gopher[i].y);
	for(i = 0; i < m; i++)
		scanf("%lf %lf", &hole[i].x, &hole[i].y);
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < m; j++)
		{
			if((gopher[i].x - hole[j].x)*(gopher[i].x - hole[j].x) + 
			   (gopher[i].y - hole[j].y)*(gopher[i].y - hole[j].y) <= s*v*s*v)
			   c[i][j] = true;
			else
				c[i][j] = false;
		}
	}
}
void LoveHH()
{
	int k = MaxMatch();
	printf("%d\n", n - k);
}
int main ()
{
	while(scanf("%d%d%d%d", &n, &m, &s, &v) != EOF)
	{
		MissHH();
		LoveHH();
	}
	return 0;
}