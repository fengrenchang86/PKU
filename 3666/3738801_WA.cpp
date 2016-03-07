#include<iostream>
using namespace std;
int a[3000];
int f ( int nbegin, int nend )
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
	if ( a[mid] <= a[mid+1] )
		return f(nbegin,mid)+f(mid+1,nend);
	else
	{
		int k = a[mid] - a[mid+1];
		int x,y,z=a[mid];
		a[mid] = a[mid+1];
		x = f(nbegin,mid)+f(mid+1,nend);
		a[mid] = z;
		y = f(nbegin,mid)+f(mid+1,nend);
		if ( x < y )
			return x+k;
		else
			return y+k;
	}
}
int g ( int nbegin, int nend )
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
	if ( a[mid] >= a[mid+1] )
		return g(nbegin,mid)+g(mid+1,nend);
	else
	{
		int k = a[mid+1] - a[mid];
		int x,y,z=a[mid];
		a[mid] = a[mid+1];
		x = g(nbegin,mid)+g(mid+1,nend);
		a[mid] = z;
		y = g(nbegin,mid)+g(mid+1,nend);
		if ( x < y )
			return x+k;
		else
			return y+k;
	}
}
int main ()
{
	int n,i;
	scanf("%d",&n);
	for ( i = 0; i < n; i++ )
		scanf("%d",&a[i]);
	int x,y;
	x = f(0,n-1);
	y = g(0,n-1);
	if ( x < y)
		printf("%d\n",x);
	else
		printf("%d\n",y);
	return 0;
}