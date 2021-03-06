#include <iostream>
using namespace std;
struct chang
{
	int num;
	int money;
	int hight;
};
void SmallHeapInsert ( chang a[], int MaxSize, int& CurrentSize, chang x )
{
//	if ( CurrentSize == MaxSize )
	{
//		printf("No memory\n");
//		return;
	}
	int i = CurrentSize;
	while ( i > 1 )
	{
		if ( a[i/2].money > x.money )
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

void SmallDel ( chang sort[], chang a[], int& CurrentSize, int& Len )
{
	CurrentSize--;
	sort[Len++] = a[1];
	chang item = a[CurrentSize];
	int i = 2;
	while ( i <= CurrentSize )
	{
		if ( i < CurrentSize && a[i].money > a[i+1].money )
			i++;
		if ( item.money <= a[i].money )
			break;
		a[i/2] = a[i];
		i *= 2;
	}
	a[i/2] = item;
}
int Qsort( chang t[], int start, int end )
{
	int i;
	t[0] = t[start];
	i = 0; // i==0表示t[up]跟t[0]比较， i==1表示t[down]跟t[0]比较。
	int up = end;
	int down = start;
	while ( up != down )
	{
		if ( i == 0 && t[up].money >= t[0].money )
		{
			up--;
			continue;
		}
		if ( i == 0 && t[up].money < t[0].money )
		{
			t[down] = t[up];
			i = 1;
			down++;
			continue;
		}
		if ( i == 1 && t[down].money <= t[0].money )
		{
			down++;
			continue;
		}
		if ( i == 1 && t[down].money > t[0].money )
		{
			t[up] = t[down];
			i = 0;
			up--;
		}
	}
	t[down] = t[0];
	return down;
}
void qs ( chang t[], int start, int end )		//递归实现快排
{
	int mid;
	if ( start < end )
	{
		mid = Qsort(t,start,end);
		qs ( t,start,mid-1);
		qs ( t,mid+1,end);
	}
}
const int MAX = 32000;

int main ()
{
	chang boss[MAX];
	chang sort[MAX];
	int tcase,it;
	int m, q;
	int i,j;
	int tnum;
	int x,y;
	int c,find;
	int CurrentSize;
	int len;
	int a[220][2];
	scanf("%d",&tcase);
	for ( it = 0; it < tcase; it++ )
	{
		len = CurrentSize = 1;
		scanf("%d %d",&m,&q);
		for ( i = 1; i <= m; i++ )
		{
			scanf("%d %d %d",&boss[0].num,&boss[0].money,&boss[0].hight);
			SmallHeapInsert( sort,1000000, CurrentSize, boss[0] );
		}
		for ( i = 1; i <= m; i++ )
			SmallDel(boss,sort,CurrentSize,len);
//		qs( boss, 1, m );
		for ( i = 1; i <= q; i++ )
		{
			scanf("%d",&tnum);
			j = 1;
			while ( boss[j].num != tnum )
				j++;
			find = j--;
			c = 0;
			while ( j >= 1 )
			{
				if ( boss[j].hight <= boss[find].hight )
					c++;
				j--;
			}
			j = find+1;
			boss[m+1].hight = 0;
			while ( (boss[j].hight < boss[find].hight)&&(j<=m) )
				j++;
			if ( j > m )
				a[i][0] = 0;
			else
				a[i][0] = boss[j].num;
			a[i][1] = c;
		}
		for ( j = 1; j <= m; j++ )
			printf("%d %d\n",a[j][0],a[j][1]);
	}
	return 1;
}