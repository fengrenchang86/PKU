#include <iostream>
using namespace std;
struct ac
{
	int x,y;
}path[2100][2100];
bool c[2100][2100];
int a[2100];
int n, x, y, m;
void init()
{
	int i, j;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < m; j++)
			c[i][j] = false;
	}
}
void input()
{
	int i;
	scanf("%d", &n);
	m = 0;
	for(i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		m += a[i];
	}
}
void solve()
{
	int i, j, k;
	input();
	init();
	c[0][0] = true;
	c[0][a[0]] = true;
	for(i = 1; i < n; i++)
	{
		for(j = 0; j <= x; j++)
		{
			if(!c[i][j] && c[i-1][j])
			{
				c[i][j] = true;
				path[i][j].x = i-1;
				path[i][j].y = j;
			}
			if(j >= a[i] && c[i-1][j-a[i]])
			{
				c[i][j] = true;
				path[i][j].x = i-1;
				path[i][j].y = j-a[i];
			}
		}
	}
	i = n-1;
	j = x;
	while(i >= 0)
	{
		if(j != path[i][j].y)
			a[i] *= -1;
		if(i == 0)
			break;
		k = i;
		i = path[k][j].x;
		j = path[k][j].y;
	}
	j = k = 0;
	for(i = 0; i < n; i++)
	{
		if(a[i] < 0)
		{
			k -= a[i];
			j++;
		}
	}
	if(m - k > y)
		printf("Impossible to distribute\n");
	else
	{
		printf("%d", j);
		for(i = 0; i < n; i++)
		{
			if(a[i] < 0)
				printf(" %d", i+1);
		}
		printf("\n");
	}
}
int main ()
{
	while(scanf("%d %d", &x, &y) != EOF)
	{
		m = x+y;
		if(m == 0)
			break;
		solve();
	}
	return 0;
}