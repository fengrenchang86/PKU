#include<iostream>
using namespace std;
int input[100];
int rest[100];
bool visit[100];
bool c[100][100];
int n, m, pos;
char str[10000];
void MissHH()
{
	int i, j;
	for(i = 0; i < 100; i++)
	{
		for(j = 0; j < 100; j++)
			c[i][j] = false;
		rest[i] = 0;
		visit[i] = false;
	}
	pos = 0;
}
void LoveHH()
{
	bool flag = false;
	int i, j;
	for(i = 0; i < m; i++)
	{
		if(rest[input[i]] < 0)
			continue;
		for(j = 1; j <= n; j++)
		{
			if(rest[j] == 0)
			{
				c[j][input[i]] = c[input[i]][j] = true;
				rest[j]--;
				rest[input[i]]--;
				flag = true;
				break;
			}
		}
	}
	if(flag)
		LoveHH();
}
void MeetHH(int node)
{
	int i;
	char ch[10];
	itoa(node, ch, 10);
	str[pos++] = '(';
	str[pos] = NULL;
	strcat(str, ch);
	pos += strlen(ch);
	for(i = 1; i <= n; i++)
	{
		if(c[node][i] && visit[i] == false)
		{
			visit[i] = true;
			c[node][i] = c[i][node] = false;
			MeetHH(i);
		}
	}
	str[pos++] = ')';
}
int main()
{
	n = 0;
	while(scanf("%d", &input[0]) != EOF)
	{
		m = 1;
		MissHH();
		rest[input[0]]++;
		while(scanf("%d", &input[m]))
		{
			rest[input[m]]++;
			m++;
			if(cin.peek() == '\n')
				break;
		}
		n = m+1;
		LoveHH();
		visit[n] = true;
		MeetHH(n);
		str[pos] = NULL;
		printf("%s\n", str);
	}
	return 0;
}