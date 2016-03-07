#include<iostream>
#include <stdlib.h>
using namespace std;
struct huihui
{
	bool use;
	int min, max;
}hui[2600];
struct changchang
{
	int spf, cover;
}chang[2600];
int n, m;
int cmphui(const void*a, const void*b)
{
	struct huihui *c = (huihui*)a;
	struct huihui *d = (huihui*)b;
	return c->max - d->max;
}
int cmpchang(const void*a, const void*b)
{
	struct changchang *c = (changchang*)a;
	struct changchang *d = (changchang*)b;
	return c->spf - d->spf;
}
int FindMinMax(int begin, int end, int data)
{
	if(begin == end)
		return begin;
	int mid = (begin + end) / 2;
	if(hui[mid].max < data)
		return FindMinMax(mid+1, end, data);
	else
		return FindMinMax(begin, mid, data);
}
void MissHH()
{
	int i;
	scanf("%d %d", &n, &m);
	for(i = 0; i < n; i++)
	{
		scanf("%d %d", &hui[i].min, &hui[i].max);
		hui[i].use = false;
	}
	qsort(hui, n, sizeof(hui[0]), cmphui);
	for(i = 0; i < m; i++)
		scanf("%d %d", &chang[i].spf, &chang[i].cover);
	qsort(chang, m, sizeof(chang[0]), cmpchang);
}
void LoveHH()
{
	int i, j;
	int HH = 0;
	for(i = 0; i < m; i++)
	{
		j = FindMinMax(0, n-1, chang[i].spf);
		while(j < n && chang[i].cover > 0)
		{
			if(chang[i].spf >= hui[j].min && chang[i].spf <= hui[j].max && !hui[j].use)
			{
				hui[j].use = true;
				HH++;
				chang[i].cover--;
			}
			j++;
		}
	}
	printf("%d\n", HH);
}
int main ()
{
	MissHH();
	LoveHH();
	return 0;
}