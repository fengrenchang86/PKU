
#include <iostream>
using namespace std;

bool c[33][33];

bool BeginStatue[33];
bool EndStatue[33];

int degee[33];
int ans, n;

void Init()
{
	memset(c, false, sizeof(c));
	memset(degee, 0, sizeof(degee));
	ans = 0;
}
void Input()
{
	scanf("%d", &n);
	int i, j;
	for(i = 1; i <= n; i++)
	{
		degee[i] = 1;
		scanf("%d", &j);
		if(j == 0)
			BeginStatue[i] = false;
		else
			BeginStatue[i] = true;
	}
	for(i = 1; i <= n; i++)
	{
		scanf("%d", &j);
		if(j == 0)
			EndStatue[i] = false;
		else
			EndStatue[i] = true;
	}
	while(scanf("%d %d", &i, &j))
	{
		if(i == 0 && j == 0)
			break;
		c[i][j] = c[j][i] = true;
		degee[i]++;
		degee[j]++;
	}
}
void ChangeStatue(int x, int k)
{
	int i;
	for(i = 1; i <= n; i++)
	{
		if(c[x][i])
		{
			BeginStatue[i] ^= 1;
			degee[i] += k;
		}
	}
	BeginStatue[x] ^= 1;
	degee[x] += k;
}
bool check()
{
	int i;
	for(i = 1; i <= n; i++)
	{
		if(degee[i] <= 0 && BeginStatue[i] != EndStatue[i])
			return false;
	}
	return true;
}
void dfs(int lay)
{
	if(check() == false)
		return;
	int i;
	if(lay == n+1)
	{
		for(i = 1; i <= n; i++)
		{
			if(BeginStatue[i] != EndStatue[i])
				break;
		}
		if(i > n)
			ans++;
		return;
	}
	ChangeStatue(lay, -1);
	dfs(lay+1);
	ChangeStatue(lay, 1);
	dfs(lay+1);
}
int main()
{
	int tc;
	scanf("%d", &tc);
	while(tc--)
	{
		Init();
		Input();
		dfs(1);
		if(ans)
			printf("%d\n", ans);
		else
			printf("Oh,it's impossible~!!\n");
	}
	return 0;
}