#include<iostream>
using namespace std;
int a[3000];
int n;
__int64 f ( int nbegin, int nend )
{
	if ( nend == nbegin )
		return 0;
	else if ( nend - nbegin == 1 )
	{
		if ( a[nbegin] <= a[nend] )
			return 0;
		else
			return a[nbegin]-a[nend];
	}
	int mid = (nbegin+nend)/2;
	__int64 x,y;
	int k,nx=a[mid],ny=a[mid+1];
	if ( a[mid] <= a[mid+1] )
		x = f(nbegin,mid)+f(mid+1,nend);
	else
	{
		k = a[mid] - a[mid+1];
		a[mid] = ny;
		x = f(nbegin,mid)+f(mid+1,nend);
		a[mid] = nx;
		a[mid+1] = nx;
		y = f(nbegin,mid)+f(mid+1,nend);
		a[mid+1] = ny;
		if ( x > y )
			x = y;
		x +=k;
	}
	if ( mid > 0 )
	{
		k = abs(nx-a[mid-1])+abs(ny-a[mid-1]);
		a[mid] = a[mid+1] = a[mid-1];
		y = f(nbegin,mid)+f(mid+1,nend);
		a[mid] = nx;
		a[mid+1] = ny;
		y += k;
		if ( y < x )
			x = y;
	}
	if ( mid+2 < n)
	{
		k = abs(nx-a[mid+1])+abs(ny-a[mid+1]);
		a[mid] = a[mid+1] = a[mid+1];
		y = f(nbegin,mid)+f(mid+1,nend);
		a[mid] = nx;
		a[mid+1] = ny;
		y += k;
		if ( y < x )
			x = y;
	}
	return x;
}
__int64 g ( int nbegin, int nend )
{
	if ( nend == nbegin )
		return 0;
	else if ( nend - nbegin == 1 )
	{
		if ( a[nbegin] >= a[nend] )
			return 0;
		else
			return a[nend]-a[nbegin];
	}
	int mid = (nbegin+nend)/2;
	__int64 x,y;
	int k,nx=a[mid],ny=a[mid+1];
	if ( a[mid] >= a[mid+1] )
		x = g(nbegin,mid)+g(mid+1,nend);
	else
	{
		k = a[mid+1] - a[mid];
		a[mid] = ny;
		x = g(nbegin,mid)+g(mid+1,nend);
		a[mid] = nx;
		a[mid+1] = nx;
		y = g(nbegin,mid)+g(mid+1,nend);
		a[mid+1] = ny;
		if ( x > y )
			x = y;
		x += k;
	}
	if ( mid > 0 )
	{
		k = abs(nx-a[mid-1])+abs(ny-a[mid-1]);
		a[mid] = a[mid+1] = a[mid-1];
		y = g(nbegin,mid)+g(mid+1,nend);
		a[mid] = nx;
		a[mid+1] = ny;
		y += k;
		if ( y < x )
			x = y;
	}
	if ( mid+2 < n)
	{
		k = abs(nx-a[mid+1])+abs(ny-a[mid+1]);
		a[mid] = a[mid+1] = a[mid+1];
		y = g(nbegin,mid)+g(mid+1,nend);
		a[mid] = nx;
		a[mid+1] = ny;
		y += k;
		if ( y < x )
			x = y;
	}
	return x;
}
int main ()
{
	int i;
	scanf("%d",&n);
//	n = 2000;
	for ( i = 0; i < n; i++ )
		scanf("%d",&a[i]);
//	for ( i = 0; i < n; i+=2 )
//		a[i] = 0;
//	for ( i = 1; i < n; i+= 2 )
//		a[i] = 1000000000;
	__int64 x,y;
	x = f(0,n-1);
	y = g(0,n-1);
	if ( x < y)
		printf("%I64d\n",x);
	else
		printf("%I64d\n",y);
	return 0;
}