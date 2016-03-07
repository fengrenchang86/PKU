#include <iostream>
using namespace std;

struct ac
{
	int x,y;
	int pay;//0表示未访问，1表示访问一次，2表示不用再访问
	ac(){pay=0;}
}cow[310];
int que[310];
int begin,end;
int main ()
{
	int m,p,i;
	int day = 0, now = 0, next = 0;
	begin = 0;
	end = 0;
	scanf("%d%d",&m,&p);
	for ( i = 1; i <= p; i++ )
		scanf("%d%d",&cow[i].x,&cow[i].y);
	for ( i = 1; i <= p; i++ )
	{
		if ( now + cow[i].x <= m && next + cow[i].y <= m )
		{
			now += cow[i].x;
			next += cow[i].y;
			que[end++] = i;
		}
		else
			break;
	}
	cow[p+1].x = cow[p+1].y = m;
	day=2;
	now = next;
	next = 0;
	while ( i <= p || !(now==0&&next==0))
	{
		if ( now + cow[i].x <= m && next + cow[i].y <= m )
		{
			now += cow[i].x;
			next += cow[i].y;
		}
		else
		{
			day++;
			now = next;
			next = 0;
			i--;
		}
		i++;
	}
	cout<<day<<endl;
	return 0;
}	