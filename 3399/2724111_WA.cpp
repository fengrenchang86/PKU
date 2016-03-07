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
	int t,n,k,i=0,j=0,x=0,y,count=0;
	int a[200],b[200];
//	while ( 1 )
	{
	cin>>n>>k;
	i = 0;
	j = 0;
	x = 0;
	for ( t =0;t<n;t++ )
	{
		scanf("%d",&y);
	//	y = rand();
/*		if ( y % 2 == 0 )
			y = rand()%20;
		else
			y = -1*rand()%20;
		cout<<y<<" ";
		*/
		if ( y > 0 )
			a[i++] = y;
		else if ( y < 0 )
		{
			x++;
			b[j++] = y;
		}
		else
			count++; 
	}
//	cout<<endl;
	if ( i != 0 )
		qsort(a,i,sizeof(a[0]),cmp2);
	if ( j != 0 )
		qsort(b,j,sizeof(b[0]),cmp1);
	if ( x == 0 && i!=0)
	{
		for ( i = 0; i < k-1; i++ )
			cout<<a[i]<<" ";
		cout<<a[i]<<endl;
		return 0;
	}
	if ( n == k )
	{
		if ( j != 0 )
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
				cout<<b[t]<<" ";
			cout<<b[j-1]<<endl;
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
		if ( b1 >= e1 && b2 < e2)
		{
			i+=2;
			b2+=2;
		}
		else if ( b2>=e2 && b1 < e1 )
		{
			i+=2;
			b1+=2;
		}
		else if ( b1 < e1 && b2 < e2 )
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
		else
			break;
	}
	if ( i == k-1 )
	{
		if ( b1 <= e1 )
			b1++;
		else
		{
			b1-=2;
			b2+=3;
		}
	}
	else if ( i < k-1 )
	{
		if ( j != 0 )
			qsort(b,j,sizeof(b[0]),cmp2);
		while ( k > 0 )
		{
			for ( i = 0; i <= e1; i++ )
			{
				cout<<a[i]<<" ";
				k--;
			}
			count--;
			cout<<"0";
			k--;
			while ( count > 0 && k > 0 )
			{
				cout<<" 0";
				k--;
				count--;
			}
			for ( i = 0; i < e2 && k > 0;i++ )
			{
				cout<<" "<<b[i];
				k--;
			}
			cout<<endl;
			return 0;
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
	}
	return 0;
}