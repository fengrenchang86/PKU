#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
int InPut[100];
int rest[100];
bool visit[100];
bool c[100][100];
int n, m, pos;
char str[10000];
void MeetHuiHui(int);
void MissHH();
void LoveHH();
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
void ITOA(int n, char *ch)
{
	if(n < 10)
	{
		ch[0] = n+'0';
		ch[1] = NULL;
	}
	else
	{
		ch[0] = n/10+'0';
		ch[1] = n%10+'0';
		ch[2] = NULL;
	}
}
void LoveHH()
{
	bool flag = false;
	int i, j;
	for(i = 0; i < m; i++)
	{
		if(rest[InPut[i]] < 0)
			continue;
		for(j = 1; j <= n; j++)
		{
			if(rest[j] == 0)
			{
				c[j][InPut[i]] = c[InPut[i]][j] = true;
				rest[j]--;
				rest[InPut[i]]--;
				flag = true;
				break;
			}
		}
	}
}
void MeetHuiHui(int node)
{
	int i;
	char ch[10];
	ITOA(node,ch);
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
			MeetHuiHui(i);
		}
	}
	str[pos++] = ')';
}
int main()
{
	
	n = 0;
	while(scanf("%d", &InPut[0]) != EOF)
	{
		m = 1;
		MissHH();
		rest[InPut[0]]++;
		while(scanf("%d", &InPut[m]))
		{
			rest[InPut[m]]++;
			m++;
			if(cin.peek() == '\n')
				break;
		}
		n = m+1;
		LoveHH();
		visit[n] = true;
		MeetHuiHui(n);
		str[pos] = NULL;
		printf("%s\n", str);
	}
	return 0;
}
