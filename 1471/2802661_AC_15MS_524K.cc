#include <iostream>
#include <fstream>
using namespace std;
char a[520][520];
int t[520][520];
int n,big;
int main ()
{
	int find(int,int);
	int i,j,k,it=1;
	while ( scanf("%d",&n) && n!=0 )
	{
		cin.ignore();
		big = 0;
		for ( i = 0; i < n; i++ )
			gets(a[i]);
		for ( i = 0; i < n; i++ )
		{
			for ( j = i; j <= 2*n-1-i; j++ )
			{
				if ( a[i][j] == '#' )
					t[i][j] = 0;
				else if ( j == i )
					t[i][j] = 1;
				else
					t[i][j] = t[i][j-1]+1;
			}
		}
		for ( i = 0; i < n; i++ )
		{
			for ( j=2*n-i-2; j >= i; j-- )
			{
				if ( a[i][j] == '#' )
					continue;
				if ( j == 2*n-i-2 )
					t[i][j] = 1;
				else if ( t[i][j] > t[i][j+1]+1 )
					t[i][j] = t[i][j+1]+1;
			}
		}
/*		for ( i = 0; i < n; i++ )
		{
			for ( j = 0; j < i; j++ )
				cout<<" ";
			for ( j = i; j < 2*n-i-1; j++ )
				cout<<t[i][j];
			cout<<endl;
		}
*/		for ( i = 0; i < n; i++ )
		{
			for ( j = i; j < 2*n-1-i; j++ )
			{
				if ( t[i][j] == 0 )
					continue;
					k = find(i,j);
					if ( k > big )
						big = k;
			}
		}
		printf("Triangle #%d\n",it);
		it++;
		printf("The largest triangle area is %d.\n",big*big);
		printf("\n");
	}
	return 0;
}
int find ( int i, int j )
{
	int temp = i;
	int tmax = 1;
	int k = 2;
	if ( (j-i)%2==0)
	{
		i--;
		while ( i >= 0 )
		{
			if ( j < i || j >= 2*n-i-1)
				break;
			if ( t[i][j] < k )
				break;
			k++;
			i--;
		}
		tmax = k-1;
		return tmax;
	}
	i = temp;
	i++;
	k = 2;
	while ( i < n )
	{
		if ( j < i || j >= 2*n-i-1 )
			break;
		if ( t[i][j] < k )
			break;
		k++;
		i++;
	}
	if ( tmax < k-1 )
		tmax = k-1;
	return tmax;
}