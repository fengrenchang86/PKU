
#include <iostream>
using namespace std;
int a[1000000];
struct ac
{
	int id;
	int time;
	int count;
	ac(){count=1;}
}team[1200];
void SmallHeapInsert (int& CurrentSize, int x )
{
	int i = CurrentSize;
	while ( i > 1 )
	{
		if ( team[a[i/2]].count*team[a[i/2]].time > team[x].count*team[x].time )
		{
			a[i] = a[i/2];
			i /= 2;
		}
		else if ( team[a[i/2]].count*team[a[i/2]].time == team[x].count*team[x].time &&
			team[a[i/2]].id > team[x].id)
		{
			a[i] = a[i/2];
			i /= 2;
		}
		else
			break;
	}
	a[i] = x;
	CurrentSize++;
}
void SmallDel ( int& CurrentSize )
{
	CurrentSize--;
	int cha = a[1];
	printf("%d\n",team[a[1]].id);
	int item = a[CurrentSize];
	int i = 2;
	while ( i <= CurrentSize )
	{
		if ( i < CurrentSize && team[a[i]].count*team[a[i]].time > team[a[i+1]].count*team[a[i+1]].time )
			i++;
		else if ( i < CurrentSize && team[a[i]].count*team[a[i]].time == team[a[i+1]].count*team[a[i+1]].time &&
			team[a[i]].id > team[a[i+1]].id)
			i++;
		if ( team[item].count*team[item].time < team[a[i]].count*team[a[i]].time )
			break;
		else if ( team[item].count*team[item].time == team[a[i]].count*team[a[i]].time &&
			team[item].id < team[a[i]].id)
			break;
		a[i/2] = a[i];
		i *= 2;
	}
	a[i/2] = item;
	team[cha].count++;
	SmallHeapInsert(CurrentSize,cha);
}

int main ()
{
	char ch[100];
	int CurrentSize = 1;
	int j;
	int i = 0;
	int count = 0;
	while( scanf("%s",ch) && ch[0] != '#')
	{
		scanf("%d%d",&team[i].id,&team[i].time);
		SmallHeapInsert(CurrentSize,i);
		i++;
	}
	scanf("%d",&count);
	for ( i = 0; i < count; i++ )
		SmallDel(CurrentSize);
	return 0;
}
