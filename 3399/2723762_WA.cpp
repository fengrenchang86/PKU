#include <iostream>
#include <stdlib.h>
using namespace std;
int cmp ( const void*a, const void*b )
{
	int *c = (int*)a;
	int *d = (int*)b;
	if ( abs(*c) > abs(*d) )
		return -1;
	else
		return 1;
}
int cmp1 ( const void*a, const void*b )
{
	return *(int*)a-*(int*)b;
}
int cmp2 ( const void*a, const void*b )
{
	return *(int*)b-*(int*)a;
}
int main ()
{
	int t,n,k,i=0,j=0,x=0,y;
	int a[200],b[200];
	cin>>n>>k;
	for ( t =0;t<n;t++ )
	{
		scanf("%d",&y);
		if ( y >= 0 )
			a[i++] = y;
		else
		{
			x++;
			b[j++] = y;
		}
	}
	if ( i != 0 )
		qsort(a,i,sizeof(a[0]),cmp2);
	if ( j != 0 )
		qsort(b,j,sizeof(b[0]),cmp1);
	if ( x == 0 )
	{
		for ( i = 0; i < k-1; i++ )
			cout<<a[i]<<" ";
		cout<<a[i]<<endl;
		return 0;
	}
	if ( n == k )
	{
		qsort(b,j,sizeof(b[0]),cmp2);
		if ( i != 0 )
		{
			cout<<a[0];
			for ( t = 1; t < i; t++ )
				cout<<" "<<a[t];
			for ( t = 0; t < j; t++ )
				cout<<" "<<b[t];
			cout<<endl;
		}
		else
		{
			for ( t = 0; t < j-1; t++ )
				cout<<a[t]<<" ";
			cout<<a[j-1]<<endl;
		}
		return 0;
	}
	int b1,b2,e1,e2;
	if ( x == n && k % 2 == 1 )
	{
		qsort(b,j,sizeof(b[0]),cmp2);
		for ( i = 0; i < k-1; i++ )
			cout<<b[i]<<" ";
		cout<<b[i]<<endl;
		return 0;
	}
	b1 = 0;
	e1 = i-1;
	b2 = 0;
	e2 = j-1;
	i = 0;
	while ( i < k-1 )
	{
		if ( b1 == e1 )
		{
			i+=2;
			b2+=2;
		}
		else if ( b2==e2 )
		{
			i+=2;
			b1+=2;
		}
		else 
		{
			if ( a[b1]*a[b1+1] > b[b2]*b[b2+1] )
			{
				b1 += 2;
				i+=2;
			}
			else
			{
				b2 +=2;
				i+=2;
			}
		}
	}
	if ( i == k-1 )
	{
		if ( b1 <= e1 )
			b1++;
		else
		{
			b1+=2;
			e1+=3;
		}
	}
	if ( b1 != 0 )
	{
		cout<<a[0];
		for ( i = 1; i< b1;i++ )
			cout<<" "<<a[i];
		for ( i = 0; i < b2; i++ )
			cout<<" "<<b[i];
		cout<<endl;
	}
	else
	{
		for ( i = 0; i < b2-1; i++ )
			cout<<b[i]<<" ";
		cout<<b[i]<<endl;
	}
	return 0;
}