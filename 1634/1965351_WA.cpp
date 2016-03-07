#include <iostream>
using namespace std;
struct chang
{
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
		if ( i == 0 && t[up].hight >= t[0].hight )
		{
			up--;
			continue;
		}
		if ( i == 0 && t[up].hight < t[0].hight )
		{
			t[down] = t[up];
			i = 1;
			down++;
			continue;
		}
		if ( i == 1 && t[down].hight <= t[0].hight )
		{
			down++;
			continue;
		}
		if ( i == 1 && t[down].hight > t[0].hight )
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
	int tcase,it;
	int m, q;
	int i,j;
	int num;
	int c,find;
	scanf("%d",&tcase);
	for ( it = 0; it < tcase; it++ )
	{
		scanf("%d %d",&m,&q);
		for ( i = 1; i <= m; i++ )
			scanf("%d %d %d",&boss[i].num,&boss[i].money,&boss[i].hight);
		qs( boss, 1, m );
		for ( i = 1; i <= q; i++ )
		{
			scanf("%d",&num);
			j = 1;
			while ( boss[j].num != num )
				j++;
			find = j--;
			c = 0;
			while ( j >= 1 )
			{
				if ( boss[j].money < boss[find].money && boss[j].hight <= boss[find].hight )
					c++;
				j--;
			}
			j = find+1;
			while ( (boss[j].money >= boss[find].money || boss[j].hight > boss[find].hight)&&(j>m) )
				j++;
			if ( j > m )
				printf("0 %d\n",c);
			else
				printf("%d %d\n",boss[j].num,c);
		}
	}
	return 1;
}