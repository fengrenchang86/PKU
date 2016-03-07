#include <iostream>
using namespace std;
int a[1200];
int b[1200];
bool visit[1200];
bool isprime[100000];
int n, m, d;
bool flag;
void MakePrime()
{
	int i, j;
	for(i = 0; i < 100000; i++)
		isprime[i] = true;
	isprime[1] = false;
	for(i = 2; i <= 100000; i++)
	{
		if(!isprime[i])
			continue;
		for(j = 2; i*j <= 100000; j++)
			isprime[i*j] = false;
	}
}
void dfs(int lay)
{
	int i, j;
	if(lay == m+1)
	{
		flag = true;
		return;
	}
	for(i = n; i <= m; i++)
	{
		if(visit[i])
			continue;
		for(j = 2; j <= d && lay-j >= n-1; j++)
		{
			if(isprime[b[lay-1]+i-b[lay-j]])
			{
				j = -1;
				break;
			}
		}
		if(j == -1)
			continue;
		visit[i] = true;
		a[lay] = i;
		b[lay] = b[lay-1] + i;
		dfs(lay+1);
		if(flag)
			return;
		visit[i] = false;
	}
}
int main()
{
	int i;
	MakePrime();
	while(scanf("%d %d %d", &n, &m, &d) != EOF)
	{
		if(n == 0 && m == 0 && d == 0)
			break;
		flag = false;
		memset(visit, false ,sizeof(visit));
		b[n-1] = 0;
		dfs(n);
		if(flag)
		{
			for(i = n; i < m; i++)
				printf("%d,", a[i]);
			printf("%d\n", a[i]);
		}
		else
		{
			printf("No anti-prime sequence exists.\n");
		}
	}
	return 0;
}