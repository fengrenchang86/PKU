#include <iostream>
using namespace std;
int dis[20][20];
char str[20][30];
int dp[1200][20];
int m;
int n;
int Cal(char *a, char *b)	//b插在a后面
{
	int i, j, k = strlen(b) - 1;
	int ans = 0;
	int n = strlen(a);
	int t;
	while(k >= 0)
	{
		i = 0;
		j = k;
		t = 0;
		while(a[i] != NULL && b[j] != NULL)
		{
			if(a[i] == b[j])
				t++;
			i++;
			j++;
		}
		if(t > ans)
			ans = t;
		k--;
	}
	k = 1;
	while(k < n)
	{
		i = k;
		j = 0;
		t = 0;
		while(a[i] != NULL && b[j] != NULL)
		{
			if(a[i] == b[j])
				t++;
			i++;
			j++;
		}
		if(t > ans)
			ans = t;
		k++;
	}
	return ans;
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
	dp[nStatue][k] = 0;
	int newStatue = nStatue & (~(1<<k));
	if(newStatue == 0)
	{
		dp[nStatue][k] = 0;
	}
	int i, t;
	for(i = 0; i < n; i++)
	{
		t = (newStatue | (1<<i)); 
		if(t == newStatue)
		{
			if(dp[newStatue][i] == -1)
				DFS(newStatue, i);
			if(dp[nStatue][k] < dp[newStatue][i] + dis[i][k])
				dp[nStatue][k] = dp[newStatue][i] + dis[i][k];
		}
	}
}
void Solve()
{
	int i;
	for(i = 0; i < n; i++)
	{
		scanf("%s", &str[i]);
	}
	InitDis();
	int k = 0;
	for(i = 0; i < n; i++)
	{
		DFS(m, i);
		if(dp[m][i] > k)
			k = dp[m][i];
	}
	printf("%d\n", k);
}
int main()
{
// 	while(cin>>str[0]>>str[1])
// 	{
// 		cout<<Cal(str[0], str[1])<<endl;
// 	}
	while(scanf("%d", &n) && n)
	{
		Solve();
	}
	return 0;
}