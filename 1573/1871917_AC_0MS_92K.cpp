#include <iostream>
using namespace std;
int main ()
{
	int m;
	int n;
	int p;
	int i;
	int j;
	int step;
	int su ;
	while ( cin>>m>>n>>p )
	{
		if ( m == 0 && n ==0 && p == 0 )
			break;
		char **a;
		a = new char *[m];
		for ( i = 0; i < m; i++ )
			a[i] = new char[n];
		for ( i = 0; i < m; i++ )
			cin>>a[i];
		m--;
		n--;
		p--;
		step = 1;
		i = 0;
		j = p;
		su = 0;
		while ( su == 0 )
		{
			if ( a[i][j] == 'N' )
			{
				if ( i == 0 )
					su = 1;
				else
					a[i--][j] = step++;
			}
			else if ( a[i][j] == 'E' )
			{
				if ( j == n )
					su = 1;
				else
					a[i][j++] = step++;
			}
			else if  ( a[i][j] == 'W' )
			{
				if ( j == 0 )
					su = 1;
				else 
					a[i][j--] = step++;
			}
			else if ( a[i][j] == 'S' )
			{
				if ( i == m )
					su = 1;
				else
					a[i++][j] = step++;
			}
			else
				break;
		}
		if ( su == 1 )
			cout<<step<<" step(s) to exit"<<endl;
		else
			cout<<a[i][j]-1<<" step(s) before a loop of "<<step-a[i][j]<<" step(s)"<<endl;
		}

	return 1;
}