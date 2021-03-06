#include <iostream>
#include <queue>
using namespace std;

struct ac
{
	int v;
	__int64 a, b;
	ac *next;
}*tree[100];
int gcd(int x, int y)
{
	if (x % y == 0)
	{
		return y;
	}
	else
		return gcd(y, x % y);
}
struct acm
{
	int a, b;
	int node;
	bool operator()(acm &m1, acm &m2)
	{
		return (m1.a + m1.b) > (m2.a + m2.b);
	}
};
priority_queue<acm, vector<acm>, acm>que;
char table[100][30];
bool visit[100];
int n;
int ansA, ansB;
int bfs(int i1, int i2)
{
	while(!que.empty())
		que.pop();
	acm p, q;
	p.node = i1;
	p.a = p.b = 1;
	__int64 xa, xb, g;
	que.push(p);
	ac *t;
	memset(visit, false, sizeof(visit));
	while(!que.empty())
	{
		p = que.top();
		que.pop();
		if (p.node == i2)
		{
			ansA = p.a;
			ansB = p.b;
			return 0;
		}
		visit[p.node] = true;
		t = tree[p.node];
		while(t != NULL)
		{
			if (!visit[t->v])
			{
				xa = p.a * t->a;
				xb = p.b * t->b;
				g = gcd(xa, xb);
				xa /= g;
				xb /= g;
				q.a = xa;
				q.b = xb;
				q.node = t->v;
				que.push(q);
			}
			t = t->next;
		}
	}
	return 0;
}

void Insert(int x, int y, int a, int b)
{
	ac *p = new ac;
	p->a = a;
	p->b = b;
	p->v = y;
	p->next = tree[x];
	tree[x] = p;
}
int FindData(char *pstr)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (strcmp(table[i], pstr) == 0)
		{
			return i;
		}
	}
	strcpy(table[n], pstr);
	n++;
	return i;
}
void dfs(int node, __int64 a, __int64 b, int final)
{
	visit[node] = true;
	ac *p = tree[node];
	if (ansA > 0 || node == final)
	{
		ansA = a;
		ansB = b;
		return;
	}
	__int64 xa, xb, g;
	while(p != NULL)
	{
		if (!visit[p->v])
		{
			xa = a * p->a;
			xb = b * p->b;
			g = gcd(xa, xb);
			xa /= g;
			xb /= g;
			dfs(p->v, xa, xb, final);
		}
		p = p->next;
	}
}
void Input()
{
	n = 0;
	int i;
	for (i = 0; i < 100; i++)
	{
		tree[i] = NULL;
	}
	char ch, op;
	int a, b;
	int i1, i2;
	char str1[30], str2[30];
	while(scanf(" %c", &ch) != EOF)
	{
		if (ch == '.')
		{
			for (i =0 ; i < 100; i++)
			{
				tree[i] = NULL;
			}
			n = 0;
		}
		else if (ch == '!')
		{
			scanf(" %d %s %c %d %s", &a, &str1, &op, &b, &str2);
			i1 = FindData(str1);
			i2 = FindData(str2);
			int g = gcd(a, b);
			a /= g;
			b /= g;
			Insert(i1, i2, a, b);
			Insert(i2, i1, b, a);
		}
		else
		{
			scanf(" %s %c %s", &str1, &op, &str2);
			i1 = FindData(str1);
			i2 = FindData(str2);
			ansA = ansB = -1;
//			memset(visit, false, sizeof(visit));
//			dfs(i1, 1, 1, i2);
			bfs(i1, i2);
			if (ansA > 0)
			{
				printf("%d %s = %d %s\n", ansA, str1, ansB, str2);
			}
			else
			{
				printf("? %s = ? %s\n", str1, str2);
			}
		}
	}
}
int main()
{
	Input();
	return 0;
}