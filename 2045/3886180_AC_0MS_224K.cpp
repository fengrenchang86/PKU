#pragma warning(disable:4786)
#include<iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
struct ac
{
	char name[100];
	int value;
};
ac table[100100];
char g_chStr[1000];
int n;
bool bflag;
char g_ch[1000];
int g_pos;
int cmp(const void*a, const void*b)
{
	struct ac *c = (ac*)a;
	struct ac *d = (ac*)b;
	return strcmp(c->name, d->name);
}
void MissHH()
{
	n = 0;
	g_pos = 0;
}
void MeetHH()
{
	while(scanf(" %s", table[n].name))
	{
		if(strcmp(table[n].name, "END_OF_FIRST_PART") == 0)
			break;
		scanf("%d", &table[n].value);
		n++;
	}
	qsort(table, n, sizeof(table[0]), cmp);
	n -- ;
}
void GetNextChar()
{
	g_ch[0] = g_chStr[g_pos];
	g_ch[1] = NULL;
	g_pos++;
}
void GetNextDig()
{
	int i = 0;
	while(g_chStr[g_pos] >= '0' && g_chStr[g_pos] <= '9')
	{
		g_ch[i] = g_chStr[g_pos];
		g_pos++;
		i++;
	}
	g_ch[i] = 0;
}
int GetChar()
{
	if(g_chStr[g_pos] >= '0' && g_chStr[g_pos] <= '9')
		return 1;
	else if(g_chStr[g_pos] >= 'a' && g_chStr[g_pos] <= 'z')
		return 2;
	else if(g_chStr[g_pos] >= 'A' && g_chStr[g_pos] <= 'Z')
		return 3;
	else if(g_chStr[g_pos] == '(')
		return 4;
	else
		return 5;
}
int GetScore(int begin, int end, char* str)
{
	if(begin == end)
	{
		if(0 == strcmp(table[begin].name, str))
			return table[begin].value;
		else
			return -1;
	}
	int mid = (begin+end)/2;
	int k = strcmp(table[mid].name, str);
	if(0 == k)
		return table[mid].value;
	else if(k > 0)
		return GetScore(begin, mid, str);
	else
		return GetScore(mid+1, end, str);
}
int SmallLetter()
{
	g_ch[1] = g_chStr[g_pos++];
	g_ch[2] = 0;
	return GetScore(0, n, g_ch);
}
int BigLetter()
{
	GetNextChar();
	return GetScore(0, n, g_ch);
}
int Number()
{
	GetNextDig();
	int i, k = 0;
	for(i = 0; g_ch[i] != 0; i++)
	{
		k *= 10;
		k += (g_ch[i] - '0');
	}
	if(k != 0)
		return k;
	else
	{
		bflag = false;
		return -1;
	}
}
int Atom()
{
	int k = BigLetter();
	if(2 == GetChar())
		k = SmallLetter();
	if(-1 == k)
		bflag = false;
	return k;
}
int Molecule()
{
	int HH = 0;
	int j, k = 0;
	while(g_chStr[g_pos] != 0 && g_chStr[g_pos] != ')')
	{
		if(3 == GetChar())
		{
			k = Atom();
			if(1 == GetChar())
			{
				k *= Number();
			}
			HH += k;
		}
		else if(4 == GetChar())
		{
			GetNextChar();
			k = Molecule();
			GetNextChar();
			
			j = Number();
			k *= j;
			if(-1 == j)
				bflag = false;
			HH += k;
		}
		else
			break;
	}
	return HH;
}
void LoveHH()
{
	int k;
	while(scanf(" %s", &g_chStr))
	{
		if(g_chStr[0] == '0')
			break;
		g_pos = 0;
		bflag = true;
		k = Molecule();
		if(bflag)
			printf("%d\n", k);
		else
			printf("UNKNOWN\n");
	}
}
int main ()
{
	MissHH();
	MeetHH();
	LoveHH();
	return 0;
}