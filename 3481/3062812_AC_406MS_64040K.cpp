#include <iostream>
using namespace std;
struct ac
{
	int tmin,tmax,tcount;
}a[5000000];
int b[12000000];
void init ()
{
	int i;
	for ( i = 0; i < 2000000; i++ )
		a[i].tcount = 0;
}
int funMax ( int a, int b )
{
	return a>b?a:b;
}
int funMin ( int a, int b )
{
	return a<b?a:b;
}
void insert ( int i, int begin, int end, int x, int data )
{
	if ( begin == end )
	{
		a[i].tcount = 1;
		a[i].tmax = a[i].tmin = data;
		return;
	}
	a[i].tcount++;
	int mid = (begin+end)/2;
	if ( x <= mid )
		insert(i*2,begin,mid,x,data);
	else
		insert(i*2+1,mid+1,end,x,data);
	if ( a[i*2+1].tcount != 0 && a[i*2].tcount == 0 )
	{
		a[i].tmax = a[i*2+1].tmax;
		a[i].tmin = a[i*2+1].tmin;
	}
	else if ( a[i*2].tcount != 0 && a[i*2+1].tcount == 0)
	{
		a[i].tmax = a[i*2].tmax;
		a[i].tmin = a[i*2].tmin;
	}
	else if ( a[i*2].tcount != 0 && a[i*2+1].tcount != 0 )
	{
		a[i].tmax = funMax(a[i*2].tmax,a[i*2+1].tmax);
		a[i].tmin = funMin(a[i*2].tmin,a[i*2+1].tmin);
	}
}
void Dele ( int i, int begin, int end, int x )
{
	if ( begin == end )
	{
		a[i].tcount = 0;
		return;
	}
	a[i].tcount--;
	int mid = (begin+end)/2;
	if ( x <= mid )
		Dele(i*2,begin,mid,x);
	else
		Dele(i*2+1,mid+1,end,x);
	if ( a[i*2+1].tcount != 0 && a[i*2].tcount == 0 )
	{
		a[i].tmax = a[i*2+1].tmax;
		a[i].tmin = a[i*2+1].tmin;
	}
	else if ( a[i*2].tcount != 0 && a[i*2+1].tcount == 0 )
	{
		a[i].tmax = a[i*2].tmax;
		a[i].tmin = a[i*2].tmin;
	}
	else if ( a[i*2].tcount != 0 && a[i*2+1].tcount != 0 )
	{
		a[i].tmax = funMax(a[i*2].tmax,a[i*2+1].tmax);
		a[i].tmin = funMin(a[i*2].tmin,a[i*2+1].tmin);
	}
}
void input ()
{
	init();
	int oper,id,data;
	while ( scanf("%d",&oper) && oper != 0 )
	{
		if ( oper == 1 )
		{
			scanf("%d%d",&id,&data);
			b[data] = id;
			insert(1,1,1000000,id,data);
		}
		else if ( oper == 2 )
		{
			if ( a[1].tcount == 0 )
			{
				cout<<0<<endl;
				continue;
			}
			data = a[1].tmax;
			id = b[data];
			printf("%d\n",id);
			Dele(1,1,1000000,id);
		}
		else
		{
			if ( a[1].tcount == 0 )
			{
				cout<<0<<endl;
				continue;
			}
			data = a[1].tmin;
			id = b[data];
			printf("%d\n",id);
			Dele(1,1,1000000,id);
		}
	}
}
int main ()
{
	input();
	return 0;
}