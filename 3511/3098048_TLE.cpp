#include <iostream>
using namespace std;
class ac
{
public:
	int x;
	int y;
	ac(){x=0;y=0;}
}t[8000000];
void insert ( int i, int begin, int end, int data )
{
	t[i].x ++;
	if ( (data-1)%4==0 )
		t[i].y++;
	if ( begin == end )
		return;
	int mid = (begin+end)/2;
	if ( data <= mid )
		insert(i*2,begin,mid,data);
	else
		insert(i*2+1,mid+1,end,data);
}
void find ( int i, int begin, int end, int l, int u, int&x, int &y )
{
	if ( begin == end )
	{
		x = t[i].x;
		y = t[i].y;
		return;
	}
	int mid = (begin+end)/2;
	int x1,x2,y1,y2;
	if ( u <= mid )
	{
		find(i*2,begin,mid,l,u,x1,y1);
		x = x1;
		y = y1;
	}
	else if ( l > mid )
	{
		find ( i*2+1,mid+1,end,l,u,x2,y2);
		x = x2;
		y = y2;
	}
	else
	{
		find(i*2,begin,mid,l,mid,x1,y1);
		find(i*2+1,mid+1,end,mid+1,u,x2,y2);
		x = x1+x2;
		y = y1+y2;
	}
}
int make ( int begin, int end )
{
	if ( begin % 2 == 0 )
	{
		begin--;
		if ( begin < 0 )
			begin = 3;
	}
	int i,j,k=2;
	for ( i = begin; i <= end; i+=2 )
	{
		for ( j = 3; j*j <= i; j+= 2 )
		{
			if ( i % j == 0 )
				break;
		}
		if ( i % j != 0 )
			insert(1,1,1000000,i);
	}
	return k;
}
int main ()
{
	int l,u,x,y,b=2,max=-1;
	while ( cin>>l>>u )
	{
		if ( l == -1 && u == -1 )
			break;
		if ( u > max )
		{
			b = max;
			max = u;
			make(b,max);
		}
		find(1,1,1000000,l,u,x,y);
		printf("%d %d %d %d\n",l,u,x,y);
	}
	return 0;
}