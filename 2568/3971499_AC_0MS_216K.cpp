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
void ITOA(int n)
{
	if(n < 10)
	{
		str[pos++] = n+'0';
	}
	else
	{
		str[pos++] = n/10+'0';
		str[pos++] = n%10+'0';
	}
}
void LoveHH()
{
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
				break;
			}
		}
	}
}
void MeetHuiHui(int node)
{
	int i;
	if(pos != 0)
	str[pos++] = ' ';
	str[pos++] = '(';
	ITOA(node);
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
void init()
{
	int i = 0;
	while(str[i] == ' ')
		i++;
	while(str[i] != NULL)
	{
		InPut[m] = 0;
		while(str[i] >= '0' && str[i] <= '9')
		{
			InPut[m] *= 10;
			InPut[m] += (str[i]-'0');
			i++;
		}
		rest[InPut[m]]++;
		m++;
		while(str[i] == ' ')
			i++;
	}
}
int main()
{
	
	n = 0;
	while(gets(str))
	{
		m = 0;
		MissHH();
		init();
		
		n = m+1;
		LoveHH();
		visit[n] = true;
		MeetHuiHui(n);
		str[pos] = NULL;
		printf("%s\n", str);
	}
	return 0;
}
