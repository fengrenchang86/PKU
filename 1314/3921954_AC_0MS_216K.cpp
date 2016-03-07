#include<iostream>
#include<stdlib.h>
using namespace std;
struct ac
{
	int x, y;
	char ch;
}t[60];
char a[60][60];
char str[100000][6];
int n, HH = 1;
int cmp(const void*a, const void*b)
{
	return strcmp((char*)a, (char*)b);
}
void init()
{
	int i, j;
	for(i = 0; i < 59; i++)
	{
		for(j = 0; j < 59; j++)
			a[i][j] = '.';
	}
}
void MissHH()
{
	init();
	int i;
	for(i = 0; i < n; i++)
	{
		scanf(" %c%d%d", &t[i].ch, &t[i].x, &t[i].y);
		a[t[i].x][t[i].y] = t[i].ch;
	}
}
void LoveHH()
{
	int i, j, k = 0;
	char cha, chb;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			if(t[i].x < t[j].x && t[i].y > t[j].y)
			{
				cha = a[t[j].x][t[i].y];
				chb = a[t[i].x][t[j].y];
				if(cha != '.' && chb != '.')
				{
					str[k][0] = t[i].ch;
					str[k][1] = cha;
					str[k][2] = t[j].ch;
					str[k][3] = chb;
					str[k][4] = NULL;
					k++;
				}
			}
		}
	}
	qsort(str, k, sizeof(str[0]), cmp);
	printf("Point set %d:", HH++);
	if(k == 0)
	{
		printf(" No rectangles\n");
		return;
	}
	printf("\n");
	for(i = 0; i < k; i++)
	{
		printf(" %s", str[i]);
		if((i+1)%10 == 0 && i+1 < k)
			printf("\n");
	}
	printf("\n");
}
int main ()
{
	while(scanf("%d",&n) != EOF)
	{
		if(n == 0)
			break;
		MissHH();
		LoveHH();
	}
	return 0;
}