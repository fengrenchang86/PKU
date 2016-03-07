#include <iostream>
using namespace std;
#define inf 200000
int a[220];
bool visit[220];
int b[10];
void input()
{
	int i;
	for(i = 0; i <= 100; i++)
	{
		a[i] = inf;
		visit[i] = false;
	}
	for(i = 0; i < 6; i++)
	{
		scanf("%d", &b[i]);
		a[b[i]] = 1;
	}
}
void solve()
{
	int i, j, k, tmin;
	double ans = 0.0;
	for(i = 1; i <= 100; i++)
	{
		tmin = inf;
		for(j = 1; j <= 100; j++)
		{
			if(a[j] < tmin && !visit[j])
			{
				tmin = a[j];
				k = j;
			}
		}
		if(tmin == inf)
			break;
		visit[k] = true;
		for(j = 0; j < 6; j++)
		{
			if(k+b[j] <= 200 && a[k+b[j]] > a[k]+1)
				a[k+b[j]] = a[k]+1;
			if(k-b[j] > 0 && a[k-b[j]] > a[k]+1)
				a[k-b[j]] = a[k]+1;
		}
	}
	tmin = 0;
	for(i = 1; i <= 100; i++)
	{
		ans += a[i];
		if(a[i] > tmin)
			tmin = a[i];
	}
	ans /= 100.0;
	printf("%.2lf %d\n", ans, tmin);
}
int main()
{
	int tc;
	scanf("%d", &tc);
	while(tc--)
	{
		input();
		solve();
	}
	return 0;
}