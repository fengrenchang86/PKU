#include <iostream>
using namespace std;
class chang
{
public:
	int num;
	int money;
	int hight;
};
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
const int MAX = 40000;

int main ()
{
	chang boss[MAX];
	int tcase,it;
	int m, q;
	int i,j;
	int tnum;
	int x;
	int c,find;
	int CurrentSize;
	int len;
	scanf("%d",&tcase);
	for ( it = 0; it < tcase; it++ )
	{
		len = CurrentSize = 1;
		scanf("%d %d",&m,&q);
		for ( i = 1; i <= m; i++ )
			scanf("%d %d %d",&boss[i].num,&boss[i].money,&boss[i].hight);
		qs( boss, 1, m );
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
				x = 0;
			else
				x = boss[j].num;
			printf("%d %d\n",x,c);
		}
	}
	return 1;
}