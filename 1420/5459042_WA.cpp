#include <iostream>
using namespace std;
struct wa
{
	int x, y;
	wa *next;
};
struct ac
{
	int val;
	int visit;
	wa *next;
}a[1000][19000];
int m, n;
int GetVal(char *p)
{
	int k = strlen(p);
	if (k == 1)
	{
		return (int)(*p - 'A' + 1);
	}
	else if (k == 2)
	{
		return (int)((p[0]-'A'+1)*26 + p[1]-'A' + 1);
	}
	else
	{
		return (int)((p[0]-'A'+1)*26*26 + (p[1]-'A'+1)*26 + p[2]-'A' + 1);
	}
}
int GetInt(char *p)
{
	int k = 0;
	while(*p != NULL)
	{
		k *= 10;
		k += (*p - '0');
		p++;
	}
	return k;
}
void dfs(int i, int j)
{
	wa *p = a[i][j].next;
	while(p != NULL)
	{
		a[p->x][p->y].val += a[i][j].val;
		a[p->x][p->y].visit--;
		if (a[p->x][p->y].visit == 0)
		{
			dfs(p->x, p->y);
		}
		p = p->next;
	}
}
void Input()
{
	scanf("%d %d", &m, &n);
	int i, j, k;
	int x, y;
	char str[3000];
	char ch[3000];
	char *p;
	wa *q;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			a[i][j].next = NULL;
			a[i][j].val = 0;
			a[i][j].visit = -1;
		}
	}
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			a[i][j].visit = 0;
			scanf(" %s", str);
			if (str[0] != '=')
			{
				a[i][j].val = GetInt(str);
				dfs(i, j);
			}
			else
			{
				p = &(str[1]);
				k = 0;
				while(*p >= 'A' && *p <= 'Z')
				{
					ch[k++] = *p;
					p++;
				}
				ch[k] = NULL;
				y = GetVal(ch);
				x = 0;
				while(*p >= '0' && *p <= '9')
				{
					x *= 10;
					x += (*p - '0');
					p++;
				}
				if (a[x][y].visit == 0)
				{
					a[i][j].val += a[x][y].val;
					if (a[i][j].visit == 0)
					{
						dfs(i, j);
					}
				}
				else
				{
					a[i][j].visit++;
					q = new wa;
					q->next = a[x][y].next;
					q->x = i;
					q->y = j;
					a[x][y].next = q;
				}
				while (*p == '+')
				{
					p++;
					k = 0;
					while (*p >= 'A' && *p <= 'Z')
					{
						ch[k++] = *p;
						p++;
					}
					ch[k] = NULL;
					y = GetVal(ch);
					x = 0;
					while (*p >= '0' && *p <= '9')
					{
						x *= 10;
						x += (*p - '0');
						p++;
					}
					if (a[x][y].visit == 0)
					{
						a[i][j].val += a[x][y].val;
						if (a[i][j].visit == 0)
						{
							dfs(i, j);
						}
					}
					else
					{
						a[i][j].visit++;
						q = new wa;
						q->next = a[x][y].next;
						q->x = i;
						q->y = j;
						a[x][y].next = q;
					}
				}
			}
		}
	}
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j < m; j++)
		{
			printf("%d ", a[i][j].val);
		}
		printf("%d\n", a[i][j].val);
	}
}
int main()
{
	int tc;
	scanf("%d", &tc);
	while(tc--)
	{
		Input();
	}
	return 0;
}