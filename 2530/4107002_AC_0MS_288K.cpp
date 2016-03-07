#include <iostream>
using namespace std;
bool c[30][30];
bool visit[30];
int degree[30];
char a[60][30];
char str[30];
int n,k,m;
void Input()
{
	int i;
	for(i = 0; i < n; i++)
		scanf(" %s", &a[i]);
}
void Init()
{
	int i, j;
	char ch;
	for(i = 0; i < 26; i++)
	{
		degree[i] = 0;
		visit[i] = false;
	}
	for(i = 0; i < 26; i++)
	{
		for(j = 0; j < 26; j++)
			c[i][j] = false;
	}
	for(j = 0; j < 20; j++)
	{
		for(i = 0; i < n; i++)
		{
			if(a[i][j] != '.')
			{
				ch = a[i][j];
				visit[ch-'A'] = true;
				break;
			}
		}
		i++;
		while(i < n)
		{
			if(a[i][j] != '.' && ch != a[i][j])
			{
				visit[a[i][j]-'A'] = true;
				if(c[a[i][j] - 'A'][ch - 'A'] == false)
					degree[ch-'A']++;
				c[a[i][j] - 'A'][ch - 'A'] = true;
				ch = a[i][j];
			}
			i++;
		}
	}
	m = k = 0;
}
void dfs(int node)
{
	degree[node] = -1;
	int i;
	for(i = 0; i < 26; i++)
	{
		if(c[node][i])
			degree[i]--;
	}
}
int main()
{
	int i;
	while(cin>>n)
	{
		Input();
		Init();
		for(i = 0; i < 26; i++)
		{
			if(visit[i])
				m++;
		}
		while(k < m)
		{
			for(i = 0; i < 26; i++)
			{
				if(visit[i] && degree[i] == 0)
				{
					str[k++] = char(i+'A');
					degree[i]--;
					dfs(i);
					break;
				}
			}
		}
		str[k] = NULL;
		cout<<str<<endl;
	}
	return 0;
}