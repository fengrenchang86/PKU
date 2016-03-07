#include <iostream>
#include <queue>
using namespace std;
#define inf 2000000000
int a[110];
int c[110];
int n, m;
bool visit[110000];
int use[110000];

void Input()
{
	int i;
	for(i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for(i = 1; i <= n; i++)
		scanf("%d", &c[i]);
}
void Solve()
{
	memset(visit, false, sizeof(visit));
	visit[0] = true;
	int i, j;
	for(i = 1; i <= m; i++)
		use[i] = inf;
	use[0] = 0;
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= m; j++)
		{
			if(visit[j])
				use[j] = 0;
			else
				use[j] = inf;
		}
		for(j = 1; j <= m; j++)
		{
			if(j >= a[i] && visit[j-a[i]] && use[j-a[i]] < c[i])
			{
				if(use[j] > use[j-a[i]] + 1)
					use[j] = use[j-a[i]] + 1;
				visit[j] = true;
			}
		}
	}
	j = 0;
	for(i = 1; i <= m; i++)
	{
		if(visit[i])
			j++;
	}
	printf("%d\n", j);
}
int main()
{
	while(scanf("%d %d", &n, &m) != EOF)
	{
		if(n == 0 && m == 0)
			break;
		Input();
		Solve();
	}
	return 0;
}