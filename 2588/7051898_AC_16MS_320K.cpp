#include <iostream>
#include <math.h>
using namespace std;
struct ac
{
	int v;
	ac *next;
}*List[1010];
struct wa
{
	double x, y, r;
}snake[1010];
int n;
double lefty, righty;
bool visit[1010];
void Insert(int x, int y)
{
	ac *p = new ac;
	p->v = y;
	p->next = List[x];
	List[x] = p;
}
double Caldis(int i, int j)
{
	return sqrt((snake[i].x-snake[j].x)*(snake[i].x-snake[j].x) + (snake[i].y-snake[j].y)*(snake[i].y-snake[j].y));
}
void Input()
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		List[i] = NULL;
		scanf("%lf %lf %lf", &snake[i].x, &snake[i].y, &snake[i].r);
	}
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (Caldis(i, j) <= snake[i].r + snake[j].r)
			{
				Insert(i, j);
				Insert(j, i);
			}
		}
	}
}
void dfs(int node)
{
	if (snake[node].x <= snake[node].r)
	{
		double dy = sqrt(snake[node].r * snake[node].r - snake[node].x * snake[node].x);
		dy = snake[node].y - dy;
		if (dy < lefty)
		{
			lefty = dy;
		}
	}
	if (snake[node].x + snake[node].r >= 1000.0)
	{
		double dy = sqrt(snake[node].r * snake[node].r - (1000.0-snake[node].x) * (1000.0-snake[node].x));
		dy = snake[node].y - dy;
		if (dy < righty)
		{
			righty = dy;
		}
	}
	visit[node] = true;
	ac *p = List[node];
	while(p != NULL)
	{
		if (!visit[p->v])
		{
			dfs(p->v);
		}
		p = p->next;
	}
}
void Solve()
{
	memset(visit, false, sizeof(visit));
	int i;
	lefty = righty = 1000.0;
	for (i = 0; i < n; i++)
	{
		if (visit[i])
			continue;
		if (snake[i].y + snake[i].r >= 1000.0)
		{
			dfs(i);
		}
	}
	for (i = 0; i < n; i++)
	{
		if (!visit[i])
			continue;
		if (snake[i].y - snake[i].r <= 0.0)
		{
			break;
		}
	}
	if (i < n)
	{
		printf("Bill will be bitten.\n");
	}
	else
	{
		printf("Bill enters at (0.00, %.2lf) and leaves at (1000.00, %.2lf).\n", lefty, righty);
	}
}
int main()
{
	while(scanf("%d", &n) != EOF)
	{
		Input();
		Solve();
	}
	return 0;
}