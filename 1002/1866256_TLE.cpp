#include <iostream.h>
#include <iomanip.h>
#include<stdlib.h>
/*
int cmp ( const void *a ,const void *b ) 
{
	int *m = (int *)a, *n = (int *)b ;
	if ( *m > *n )
		return 1 ;
	else
	if ( *m == *n )
		return 0 ;
	else
	if ( *m < *n )
		return -1;
	else
		return 0;
}
*/
int list[26] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,-1,7,7,8,8,8,9,9,9,-1};
void main ()
{
	int n;
	char put[300];
	int i;
	int j;
	int t;
	int m;
	int c = 0;
	cin>>n;
	int **a ;
	a = new int*[2];
	for ( i = 0; i < 2; i++ )
		a[i] = new int[n];
	for ( i = 0; i <= n; i++ )
	{
		a[0][i] = 0;
		a[1][i] = 0;
	}
	for ( i = 0; i < n; i++ )
	{
		cin>>put;
		m = 0;
		for ( j = 0; put[j] != NULL; j++ )
		{
			if ( put[j] >= '0' && put[j] <= '9' )
				t = put[j] - '0';
			else if ( put[j] >= 'A' && put[j] < 'z' && put[j] != 'Q' )
				t = list[put[j]-'A'];
			else 
				continue;
			m = m*10 + t;
		}
		for ( j = 0; j < c; j++ )
		{
			if ( m == a[0][j] )
			{
				a[1][j]++;
				break;
			}
		}
		if ( j == c )
		{
			a[0][c] = m;
			a[1][c]++;
			c++;
		}
	}
	
	for ( i = 0; i < c-1; i++ )
	{
		for ( j = i+1; j < c; j++ )
		{
			if ( a[0][i] > a[0][j] )
			{
				m = a[0][i];
				a[0][i] = a[0][j];
				a[0][j] = m;
				m = a[1][i];
				a[1][i] = a[1][j];
				a[1][j] = m;
			}
		}
	}
	
//	qsort ( a[0], c, sizeof ( int ), cmp ) ;
	t = 0;
	for ( i = 0; i < c; i++ )
	{
		if ( a[1][i] > 1 )
		{
			cout<<setw(3)<<setfill('0')<<a[0][i]/10000<<'-'<<setw(4)<<setfill('0')<<a[0][i]%10000;
			cout<<" "<<a[1][i]<<endl;
			t++;
		}
	}
	if ( t == 0 )
		cout<<"No duplicates."<<endl;
}