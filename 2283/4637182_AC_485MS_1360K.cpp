#include <iostream>
#include <queue>
using namespace std;
struct ac
{
	int nAdd;
	int pre;
	int step;
}record[70000];

bool visit[70000];

queue<int>que;
char szAns[70000];
int nLen;
int Compare(char *szTemp)
{
	int i;
	for(i = 0;i < nLen; i++)
	{
		if(szAns[i] > szTemp[i])
			return 1;
		else if(szAns[i] < szTemp[i])
			return -1;
	}
	return 0;
}
bool MatchOne(int x)
{
	nLen = 700000;
	int i, j, k;
	for(i = 1; i <= 9; i++)
	{
		memset(visit, 0, sizeof(visit));
		k = 0;
		for(j = 1; ; j++)
		{
			k *= 10;
			k += i;
			k %= x;
			if(k == 0)
			{
				if(nLen > j)
				{
					nLen = j;
					for(k = 0; k < j; k++)
						szAns[k] = '0' + i;
					szAns[k] = NULL;
				}
				break;
			}
			else if(visit[k])
				break;
			else
				visit[k] = 1;
		}
	}
	if(nLen != 700000)
	{
		printf("%s\n", szAns);
		return true;
	}
	return false;
}
void MatchTwo(int x, int y, int data)
{
	while(!que.empty())
		que.pop();

	int i;
	int p, q;
	for(i = 0; i < data; i++)
		record[i].pre = -1;
	if(x != 0)
	{
		record[x%data].nAdd = x;
		record[x%data].pre = 0;
		record[x%data].step = 0;
		que.push(x);
	}
	record[y%data].nAdd = y;
	record[y%data].pre = 0;
	record[y%data].step = 0;
	que.push(y);
	while(!que.empty())
	{
		p = que.front();
		que.pop();
		if(p == 0)
			break;
		q = (p * 10 + x) % data;
		if(record[q].pre == -1)
		{
			record[q].nAdd = x;
			record[q].step = record[p].step + 1;
			record[q].pre = p;
			que.push(q);
		}
		q = (p * 10 + y) % data;
		if(record[q].pre == -1)
		{
			record[q].nAdd = y;
			record[q].step = record[p].step + 1;
			record[q].pre = p;
			que.push(q);
		}
	}
	if(p != 0)
		return;
	char szTemp[70000];
	szTemp[record[p].step+1] = NULL;
	i = 0;
	do 
	{
		szTemp[record[p].step] = record[p].nAdd + '0';
		p = record[p].pre;
	} while(p != 0);
	if(record[p].step + 1 < nLen)
	{
		nLen = record[p].step + 1;
		strcpy(szAns, szTemp);
	}
	else if(record[p].step + 1 == nLen)
	{
		if(Compare(szTemp) == 1)
		{
			strcpy(szAns, szTemp);
		}
	}
}
void Solve(int data)
{
	if(MatchOne(data))
		return;
	int i, j;
	nLen = 700000;
	for(i = 0; i < 9; i++)
	{
		for(j = i + 1; j <= 9; j++)
		{
			MatchTwo(i, j, data);
		}
	}
	printf("%s\n", szAns);
}
int main()
{
	int data, x = 0;
	while(scanf("%d", &data))
	{
		if(data == 0)
			break;
		Solve(data);
	}
	return 0;
}