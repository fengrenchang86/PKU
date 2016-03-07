#include <iostream>
#include <stdlib.h>
using namespace std;
struct huihui
{
	int nMin, nMax;
}hui[2600];
struct changchang
{
	int spf, num;
}chang[2600];
int n, m;
int HelloHH(const void*a, const void*b)
{
	struct huihui *c = (huihui*)a;
	struct huihui *d = (huihui*)b;
	if(c->nMin != d->nMin)
		return c->nMin - d->nMin;
	else
		return d->nMax - c->nMax;
}
int MeetHH(const void*a, const void*b)
{
	struct changchang *c = (changchang*)a;
	struct changchang *d = (changchang*)b;
	return c->spf - d->spf;
}
void MissHH()
{
	int i;
	scanf("%d %d", &n, &m);
	for(i = 0; i < n; i++)
		scanf("%d%d",&hui[i].nMin, &hui[i].nMax);
	qsort(hui, n, sizeof(hui[0]), HelloHH);
	for(i = 0; i < m; i++)
		scanf("%d %d",&chang[i].spf, &chang[i].num);
	qsort(chang, m, sizeof(chang[0]), MeetHH);
}
void LoveHH()
{
	int i = 0, j = 0;
	int HH = 0;
	while(i < n && j < m)
	{
		if(chang[j].num == 0)
			j++;
		else if(chang[j].spf >= hui[i].nMin && chang[j].spf <= hui[i].nMax)
		{
			i++;
			HH++;
			chang[j].num--;
		}
		else
			i++;
	}
	printf("%d\n",HH);
}
int main ()
{
	MissHH();
	LoveHH();
	return 0;
}