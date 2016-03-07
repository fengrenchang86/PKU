#include <iostream>
using namespace std;

struct ac
{
	int v;
	int a, b;
	ac *next;
}*tree[100];
char table[100][30];
bool visit[100];
int n;
int ansA, ansB;

int gcd(int x, int y)
{
	if (x % y == 0)
	{
		return y;
	}
	else
		return gcd(y, x % y);
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
	if (node == final || ansA > 0)
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
	for (int i = 0; i < 100; i++)
	{
		tree[i] = NULL;
	}
	char ch, op;
	int a, b;
	int i1, i2;
	char str1[30], str2[30];
	while(scanf(" %c", &ch))
	{
		if (ch == '.')
		{
			break;
		}
		else if (ch == '!')
		{
			scanf(" %d %s %c %d %s", &a, &str1, &op, &b, &str2);
			i1 = FindData(str1);
			i2 = FindData(str2);
			Insert(i1, i2, a, b);
			Insert(i2, i1, b, a);
		}
		else
		{
			scanf(" %s %c %s", &str1, &op, &str2);
			i1 = FindData(str1);
			i2 = FindData(str2);
			ansA = ansB = -1;
			memset(visit, false, sizeof(visit));
			dfs(i1, 1, 1, i2);
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