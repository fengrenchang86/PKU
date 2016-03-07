#include <iostream>
using namespace std;
int a[1100][1100];
int n;
void f ( int i, int j, int k, int t[] )//k从1开始
{
	int x=i,y=j;
	int m=0;
	do
	{
		if ( i == k && j < n-k+1 )
		{
			t[m++] = a[i][j];
			j++;
		}
		else if ( j == n-k+1 && i < n-k+1 )
		{
			t[m++] = a[i][j];
			i++;
		}
		else if ( i == n-k+1 && j > k )
		{
			t[m++] = a[i][j];
			j--;
		}
		else if ( j == k && i > k )
		{
			t[m++] = a[i][j];
			i--;
		}
	}while(x!=i||y!=j);
}
bool same ( int i, int j, int k, int t[] )
{
	int x=i,y=j;
	int m = 0;
	do
	{
		if ( i == k && j < n-k+1 )
		{
			if ( n*(i-1)+j == t[0] )
				break;
			j++;
		}
		else if ( j == n-k+1 && i <n-k+1 )
		{
			if ( n*(i-1)+j == t[0] )
				break;
			i++;
		}
		else if ( i == n-k+1 && j > k )
		{
			if ( n*(i-1)+j == t[0] )
				break;
			j--;
		}
		else if ( j == k && i > k )
		{
			if ( n*(i-1)+j == t[0] )
				break;
			i--;
		}
	}while ( x!=i || y!=j );
	x = i;
	y = j;
	do
	{
		if ( i == k && j < n-k+1 )
		{
			if ( n*(i-1)+j != t[m] )
				return false;
			m++;
			j++;
		}
		else if ( j == n-k+1 && i < n-k+1 )
		{
			if ( n*(i-1)+j != t[m] )
				return false;
			m++;
			i++;
		}
		else if ( i == n-k+1 && j > k )
		{
			if ( n*(i-1)+j != t[m] )
				return false;
			m++;
			j--;
		}
		else if ( j == k && i > k )
		{
			if ( n*(i-1)+j != t[m] )
				return false;
			m++;
			i--;
		}
	}while ( x!=i || y!=j );
	return true;
}
void input()
{
	int i,j;
	for ( i = 1; i <= n; i++ )
		for ( j =1; j <= n; j++ )
			scanf("%d",&a[i][j]);
}
int main ()
{
	int j,k,tc=1;
	int t[5200];
	while ( scanf("%d",&n) && n!=0 )
	{
		input();
		j = 1;
		for ( k = 1; k <= n-k+1; k++ )
		{
			f(k,k,k,t);
			if ( same(k,k,k,t)==true )
				j++;
			else
				break;
		}
		cout<<tc++<<". ";
		if ( k > n-k+1 )
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}