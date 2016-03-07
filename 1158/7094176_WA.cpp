#include <iostream>
#include <queue>
using namespace std;
#define INF 1000000000
struct ac
{
	int x, len;
	ac *next;
}*pTable[400];
struct wa
{
	bool ch;
	int ric;
	int tip, tib;
}t[400];
int dist[400];
int path[400];
struct ce
{
	int v;
	int step;
	bool operator()(ce &m1, ce &m2)
	{
		return m1.step > m2.step;
	}
};
priority_queue<ce, vector<ce>, ce>que;
int nBegin, nEnd;
int n, m;
void Init()
{
	int i;
	for (i = 0; i <= n; i++)
	{
		pTable[i] = 0;
	}
}
void Insert(int x, int y, int len)
{
	ac *p = new ac;
	p->x = y;
	p->len = len;
	p->next = pTable[x];
	pTable[x] = p;
}
void Input()
{
	scanf("%d %d", &n, &m);
	Init();
	int i, x, y, len;
	char ch;
	for (i = 1; i <= n; i++)
	{
		scanf(" %c %d %d %d", &ch, &t[i].ric, &t[i].tib, &t[i].tip);
		if (ch == 'B')
		{
			t[i].ch = 1;
		}
		else
		{
			t[i].ch = 0;
		}
	}
	for (i = 0; i < m; i++)
	{
		scanf("%d %d %d", &x, &y, &len);
		Insert(x, y, len);
		Insert(y, x, len);
	}
}
void Solve()
{
	int i, j;
	for (i = 0; i <= n; i++)
	{
		dist[i] = INF;
	}
	while (!que.empty())
	{
		que.pop();
	}
	dist[nBegin] = 0;
	ce p, q;
	p.v = nBegin;
	p.step = 0;
	que.push(p);
	ac *acm;
	bool c1,c2;
	int t1, t11, t2, t22;
	while (!que.empty())
	{
		p = que.top();
		que.pop();
		if (p.step > dist[p.v])
		{
			continue;
		}
		if (p.step < t[p.v].ric)
		{
			c1 = t[p.v].ch;
			t1 = t[p.v].ric - p.step;
			if (c1)
			{
				t11 = t1 + t[p.v].tip;
			}
			else
			{
				t11 = t1 + t[p.v].tib;
			}
		}
		else
		{
			t1 = (p.step - t[p.v].ric) % (t[p.v].tib + t[p.v].tip);
			if (t[p.v].ch)
			{
				c1 = (t1 >= t[p.v].tip);
				if (c1)
				{
					t1 = t[p.v].tib - t1 + t[p.v].tip;
					t11 = t1 + t[p.v].tip;
				}
				else
				{
					t1 = t[p.v].tip - t1;
					t11 = t1 + t[p.v].tib;
				}
			}
			else
			{
				c1 = (t1 <= t[p.v].tib);
				if (c1)
				{
					t1 = t[p.v].tib - t1;
					t11 = t1 + t[p.v].tip;
				}
				else
				{
					t1 = t[p.v].tip - t1 + t[p.v].tib;
					t11 = t1 + t[p.v].tib;
				}
			}
		}
		acm = pTable[p.v];
		while (acm != NULL)
		{
			if (p.step < t[acm->x].ric)
			{
				c2 = t[acm->x].ch;
				t2 = t[acm->x].ric - p.step;
				if (c2)
				{
					t22 = t2 + t[acm->x].tip;
				}
				else
				{
					t22 = t2 + t[acm->x].tib;
				}
			}
			else
			{
				t2 = (p.step - t[acm->x].ric) % (t[acm->x].tib + t[acm->x].tip);
				if (t[acm->x].ch)
				{
					c2 = (t2 >= t[acm->x].tip);
					if (c2)
					{
						t2 = t[acm->x].tib - t2 + t[acm->x].tip;
						t22 = t2 + t[acm->x].tip;
					}
					else
					{
						t2 = t[acm->x].tip - t2;
						t22 = t2 + t[acm->x].tib;
					}
				}
				else
				{
					c2 = (t2 <= t[acm->x].tib);
					if (c2)
					{
						t2 = t[acm->x].tib - t2 + t[acm->x].tip;
						t22 = t2 + t[acm->x].tip;
					}
					else
					{
						t2 = t[acm->x].tip - t2;
						t22 = t2 + t[acm->x].tib;
					}
				}
			}
			q.v = acm->x;
			if (c1 == c2)
			{
				if (dist[acm->x] > p.step + acm->len)
				{
					q.step = p.step + acm->len;
					dist[acm->x] = q.step;
					path[acm->x] = p.v;
					que.push(q);
				}
			}
			else
			{
				if (t1 < t2)
				{
					q.step = p.step + t1 + acm->len;
					if (dist[acm->x] > q.step)
					{
						dist[acm->x] = q.step;
						path[acm->x] = p.v;
						que.push(q);
					}
				}
				else if(t1 > t2)
				{
					q.step = p.step + t2 + acm->len;
					if (dist[acm->x] > q.step)
					{
						dist[acm->x] = q.step;
						path[acm->x] = p.v;
						que.push(q);
					}
				}
				else if (t11 < t22)
				{
					q.step = p.step + t11 + acm->len;
					if (dist[acm->x] > q.step)
					{
						dist[acm->x] = q.step;
						path[acm->x] = p.v;
						que.push(q);
					}
				}
				else if (t11 > t22)
				{
					q.step = p.step + t22 + acm->len;
					if (dist[acm->x] > q.step)
					{
						dist[acm->x] = q.step;
						path[acm->x] = p.v;
						que.push(q);
					}
				}
			}
			acm = acm->next;
		}
	}
	if (dist[nEnd] == INF)
	{
		printf("0\n");
	}
	else
	{
		printf("%d\n", dist[nEnd]);
	}
}
int main()
{
	while (scanf("%d %d", &nBegin, &nEnd) != EOF)
	{
		Input();
		Solve();
	}
	return 0;
}