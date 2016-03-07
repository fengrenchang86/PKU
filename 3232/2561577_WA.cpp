#include <iostream>
using namespace std;
int a[100200];
int m,n,k;
int f ( int begin, int end )
{
	if( begin >= end )
		return end;
	int mid = (begin+end)/2;
	__int64 t = __int64(m*mid);
	int v;
	for ( int i = 0; i < n; i++ )
	{
		if ( a[i] > mid )
		{
			if ( (a[i]-mid)%k==0 )
				v = (a[i]-mid)/k;
			else
				v = (a[i]-mid)/k+1;
			if ( v > mid || v > t )
			{
				t = -1;
				break;
			}
			t -=v;
		}
	}
	if ( t < 0 )
		return f( mid+1, end );
	else
		return f( begin, mid);
}
int main ()
{
	int tcase,i,max;
	scanf("%d",&tcase);
	while ( tcase )
	{
		tcase--;
		max = 0;
		scanf("%d",&n);
		for ( i = 0; i < n; i++ )
		{
			scanf("%d",&a[i]);
			if( a[i] > max )
				max = a[i];
		}
		scanf("%d%d",&m,&k);
		if ( k == 1 )
			printf("%d\n",max);
		else
		{
			k--;
			printf("%d\n",f(1,max));
		}
	}
	return 0;
}