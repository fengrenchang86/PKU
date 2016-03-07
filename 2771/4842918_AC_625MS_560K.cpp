#include <iostream>
using namespace std;
struct ac
{
	int nHeight;
	bool sex;
	char music[101];
	char sport[101];
}t[520];
bool c[510][510];
int n;
int xm[510], ym[510];
bool visit[510];
void BeforeSolve()
{
	int i, j;
	for(i = 0; i < n; i++)
	{
		for(j = i+1; j < n; j++)
		{
			if(abs(t[i].nHeight - t[j].nHeight) > 40)
				c[i][j] = c[j][i] = false;
			else if(t[i].sex == t[j].sex)
				c[i][j] = c[j][i] = false;
			else if(strcmp(t[i].music, t[j].music) != 0)
				c[i][j] = c[j][i] = false;
			else if(strcmp(t[i].sport, t[j].sport) == 0)
				c[i][j] = c[j][i] = false;
			else
				c[i][j] = c[j][i] = true;			
		}
		c[i][i] = false;
	}
	
}

void Input()
{
	scanf("%d", &n);
	int i;
	char ch;
	for(i = 0; i < n; i++)
	{
		scanf("%d %c %s %s", &t[i].nHeight, &ch, &t[i].music, &t[i].sport);
		if(ch == 'F')
			t[i].sex = true;
		else
			t[i].sex = false;
	}
}

bool dfs(int u)
{
	int i;
	for(i = 0; i < n; i++)
	{
		if(c[u][i] && !visit[i])
		{
			visit[i] = true;
			if(ym[i] == -1 || dfs(ym[i]))
			{
				ym[i] = u;
				xm[u] = i;
				return true;
			}
		}
	}
	return false;
}

int MaxMatch()
{
	int u;
	int ret = 0;
	memset(xm, -1, sizeof(xm));
	memset(ym, -1, sizeof(ym));
	for(u = 0; u < n; u++)
	{
		if(xm[u] == -1)
		{
			memset(visit, false, sizeof(visit));
			if(dfs(u))
				ret ++;
		}
	}
	return ret;
}

void Solve()
{
	int k = MaxMatch();
	printf("%d\n", n - k/2);
}
int main()
{
	int tc;
	scanf("%d", &tc);
	while(tc--)
	{
		Input();
		BeforeSolve();
		Solve();
	}
	return 0;
}