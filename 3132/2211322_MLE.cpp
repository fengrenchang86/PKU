#include <iostream>
using namespace std;
int a[1121][15][1121];
bool ip[1200];
void make (int p[])
{
	int i,j,k=2;
	p[0] = 2;
	p[1] = 3;
	for ( i = 3; i <= 1200; i+=2 )
	{
		for ( j = 3; j*j <= i; j+=2 )
		{
			if ( i % j == 0 )
				break;
		}
		if ( i % j != 0 )
		{
			p[k] = i;
			k++;
		}
	}
}
int main ()
{
//	fstream cin("in.txt");
	int p[200];
	make(p);
	int i,j,k,l;

	for ( i = 0; i <= 1120; i++ )
	{
		for ( k = 0; k <= 187; k++ )
			for ( j = 0; j <= 14; j++ )
				a[i][j][k] = 0;
	}
	for ( i = 0; i < 187; i++ )
		a[p[i]][1][i] = 1;
	for ( j = 2; j <= 14; j++ )
	{
		for ( i = 3; i <= 1120; i++ )
		{
			for ( k = 1; k < 187 ; k++ )
			{
				for ( l = k+1; p[l] <= i-p[k] ; l++ )
					a[i][j][k] = a[i][j][k]+a[i-p[k]][j-1][l];
			}
		}
	}
	while ( cin>>l>>k && !(l==0&&k==0) )
	{
		if ( (l%2==0&&k%2==1 || l%2==1&&k%2==0) && k > 1 && l >=5 )
		{
			k--;
			l-=2;
		}
		j = 0;
		for ( i = 0; i < 187; i++ )
			j += a[l][k][i];
		cout<<j<<endl;
	}
	return 0;
}