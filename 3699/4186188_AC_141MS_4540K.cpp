#include <iostream>
#include <string>
using namespace std;
#define Text 30
#define M 12
#define N 10001
struct FORMAT
{
	char chName[Text];
	bool bIsStr;
}kVar[M];
struct DATA
{
	char chName[Text];
	int nDig;
}table[N][M];
int nPrint[1000];
char chStr[100000];
char query[Text];
bool visit[M];
bool output[N];
int nColWide[10000];
int n, m, k, oper, nCol;
int GetID(char *pchStr)
{
	int i;
	for(i = 0; i < m; i++)
	{
		if(strcmp(pchStr, kVar[i].chName) == 0)
			break;
	}
	return i;
}
int GetNumber(char *pchStr)
{
	int i, k = 0;
	for(i = 0; pchStr[i] != NULL; i++)
	{
		k *= 10;
		k += (pchStr[i] - '0');
	}
	return k;
}
void Input()
{
	int i, j;
	char str[Text];
	for(i = 0; i < m; i++)
	{
		scanf("%s %s", kVar[i].chName, str);
		if(str[0] == 'I')
			kVar[i].bIsStr = false;
		else
			kVar[i].bIsStr = true;
	}
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < m; j++)
		{
			scanf(" %s", table[i][j].chName);
		}
	}
	for(j = 0; j < m; j++)
	{
		if(kVar[j].bIsStr)
			continue;
		for(i = 0; i < n; i++)
		{
			table[i][j].nDig = GetNumber(table[i][j].chName);
		}
	}
}
void SolveStr(int i)
{
	int j, x = GetID(query);
	char chCondition[Text];
	memset(output, false, sizeof(output));
	while(chStr[i] != '\"')
	{
		i++;
	}
	j = 0;
	i++;
	while(chStr[i] != '\"')
	{
		chCondition[j++] = chStr[i++];
	}
	chCondition[j] = NULL;
	for(j = 0; j < n; j++)
	{
		if(strcmp(table[j][x].chName, chCondition) == 0)
			output[j] = true;
		else
			output[j] = false;
	}
}
void SolveInt(int i)
{
	int j, y, x = GetID(query);
	y = 0;
	while(chStr[i] >= '0' && chStr[i] <= '9')
	{
		y *= 10;
		y += (chStr[i] - '0');
		i++;
	}
	for(j = 0; j < n; j++)
	{
		if(oper == 1 && table[j][x].nDig < y)
			output[j] = true;
		else if(oper == 2 && table[j][x].nDig > y)
			output[j] = true;
		else if(oper == 0 && table[j][x].nDig == y)
			output[j] = true;
		else
			output[j] = false;
	}
}
void PrintSpace(int nSpace)
{
	int i; 
	for(i = 0; i < nSpace; i++)
		printf(" ");
}
void Print()
{
	int i, j, x, y;
	for(j = 0; j < nCol; j++)
	{
		nColWide[j] = strlen(kVar[nPrint[j]].chName);
	}
	for(i = 0; i < n; i++)
	{
		if(!output[i])
			continue;
		for(j = 0; j < nCol; j++)
		{
			x = strlen(table[i][nPrint[j]].chName);
			if(nColWide[j] < x)
				nColWide[j] = x;
		}
	}
	x = 0;
	for(j = 0; j < nCol; j++)
	{
		nColWide[j] += 2;
		x += nColWide[j];
	}
	x += nCol;
	printf("+");
	for(j = 0; j < x-1; j++)
		printf("-");
	printf("+\n");
	printf("|");
	for(j = 0; j < nCol; j++)
	{
		y = strlen(kVar[nPrint[j]].chName);
		x = nColWide[j] - y;
		x /= 2;
		PrintSpace(x);
		printf("%s", kVar[nPrint[j]].chName);
		PrintSpace(nColWide[j] - y - x);
		printf("|");
	}
	printf("\n");

	printf("|");
	for(j = 0; j < nCol; j++)
	{
		for(x = 0; x < nColWide[j]; x++)
			printf("-");
		printf("|");
	}
	printf("\n");

	for(i = 0; i < n; i++)
	{
		if(output[i] == false)
			continue;
		printf("|");
		for(j = 0; j < nCol; j++)
		{
			y = strlen(table[i][nPrint[j]].chName);
			x = nColWide[j] - y;
			x /= 2;
			PrintSpace(x);
			printf("%s", table[i][nPrint[j]].chName);
			PrintSpace(nColWide[j] - y - x);
			printf("|");
		}
		printf("\n");
	}
	x = 0;
	for(j = 0; j < nCol; j++)
	{
		x += nColWide[j];
	}
	x += nCol;
	printf("+");
	for(j = 0; j < x-1; j++)
		printf("-");
	printf("+\n");
}
void Query()
{
	char Str[Text];
	int i = 0, j, nNum = 0;
	while(chStr[i] == ' ')
		i++;
	while(chStr[i] != ' ')
		i++;
	i++;
	memset(visit, false, sizeof(visit));
	while(chStr[i] != ' ')
	{
		j = 0;
		while(chStr[i] != ' ' && chStr[i] != ',')
		{
			Str[j++] = chStr[i++];
		}
		Str[j] = NULL;
		j = GetID(Str);
		visit[j] = true;
		nPrint[nNum++] = j;
		if(chStr[i] == ',')
			i++;
	}
	nCol = nNum;
	i++;
	while(chStr[i] != ' ')
		i++;
	i++;
	j = 0;
	while(chStr[i] != '=' && chStr[i] != '>' && chStr[i] != '<')
	{
		query[j] = chStr[i];
		i++;
		j++;
	}
	query[j] = NULL;
	if(chStr[i] == '<')
		oper = 1;
	else if(chStr[i] == '>')
		oper = 2;
	else
		oper = 0;
	j = GetID(query);
	if(kVar[j].bIsStr)
		SolveStr(i+1);
	else
		SolveInt(i+1);
}
void Solve()
{
	int i;
	Input();
	cin.ignore();
	for(i = 0; i < k; i++)
	{
		gets(chStr);
		Query();
		Print();
		if(i < k-1)
			printf("\n");
	}
}
int main ()
{
	cin>>m>>n>>k;
	Solve();
	return 0;
}