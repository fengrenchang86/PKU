#include <iostream>
using namespace std;
int dis[20][20];
char str[20][30];
int dp[1200][20];
int m;
int n;
int Cal(char *a, char *b)	//b插在a后面
{
	char *pa, *pb, *tmp = a;
	while(*tmp)
	{
		pa = tmp;
		pb = b;
		while(*pa && *pb)
		{
			if(*pa != *pb)
				break;
			pa++;
			pb++;
		}
		if(*pa == NULL || *pb == NULL)
		{
			int k = 0;
			while(*pb)
			{
				k++;
				pb++;
			}
			return k;
		}
		tmp++;
	}
	return strlen(b);
}
void InitDis()
{
	m = (1 << n) - 1;
	int i, j;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			if(i != j)
			{
				dis[i][j] = Cal(str[i], str[j]);
				if(dis[i][j] == 0)
				{
					m &= (~(1<<j));
				}
			}
			else
				dis[i][j] = 0;
		}
	}
	for(i = 0; i < 1200; i++)
	{
		for(j = 0; j < 10; j++)
			dp[i][j] = -1;
	}
}
void DFS(int nStatue, int k)
{
	dp[nStatue][k] = 0xFFFF;
	int newStatue = nStatue & (~(1<<k));
	if(newStatue == 0)
	{
		dp[nStatue][k] = strlen(str[k]);
	}
	int i, t;
	for(i = 0; i < n; i++)
	{
		t = (newStatue | (1<<i)); 
		if(t == newStatue)
		{
			if(dp[newStatue][i] == -1)
				DFS(newStatue, i);
			if(dp[nStatue][k] > dp[newStatue][i] + dis[i][k])
				dp[nStatue][k] = dp[newStatue][i] + dis[i][k];
		}
	}
}
void Solve()
{
	scanf("%d", &n);
	int i;
	for(i = 0; i < n; i++)
	{
		scanf("%s", &str[i]);
	}
	InitDis();
	int k = 0xffff;
	for(i = 0; i < n; i++)
	{
		if(((1<<i)&m) == 0)
			continue;
		DFS(m, i);
		if(dp[m][i] < k)
			k = dp[m][i];
	}
	printf("%d\n", k);
}
int main()
{
	int tc;
	scanf("%d", &tc);
	while(tc--)
	{
		Solve();
	}
	return 0;
}