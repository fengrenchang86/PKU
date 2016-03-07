#include <iostream>
using namespace std;
char a[6][6];
int v[8];
int b[25][2];
int next ()
{
	int i = 7;
	v[i]++;
	while ( v[i]-i > 17 && i > 0 )
	{
		i--;
		v[i]++;
	}
	if ( i == 0 )
		return 0;
	i++;
	while ( i <= 7 )
	{
		v[i] = v[i-1]+1;
		i++;
	}
	return 1;
}
int father[25];
int find ( int x )
{
	while ( father[x] !=x )
		x =father[x];
	return x;
}
void join ( int a, int b )
{
	father[find(a)] = find(b);
}
int p ( )
{
	int i,j,k = 0,x = 0;
	for ( i = 1; i <= 7; i++ )
	{
		if ( a[b[v[i]][0]][b[v[i]][1]] == 'H' )
			x++;
	}
	if ( x >= 4 )
		return 0;
	for ( i = 0; i <= 7; i++ )
		father[v[i]] = v[i];
	for ( i = 1; i < 7; i++ )
	{
		for ( j = i+1; j <= 7; j++ )
		{
			if ( b[v[i]][0] == b[v[j]][0] && abs(b[v[i]][1]-b[v[j]][1])==1 )
			{
				join(v[j],v[i]);
			}
			else if ( b[v[i]][1] == b[v[j]][1] && abs(b[v[i]][0]-b[v[j]][0])==1 )
			{
				join(v[j],v[i]);
			}
		}
	}
	k = find(v[1]);
	for ( i = 2; i <= 7; i++ )
	{
		if ( find(v[i]) != k )
			return 0;
	}
	return 1;
}
int main ()
{
	int i,j = 0;
	for ( i = 0; i < 5; i++ )
		scanf("%s",&a[i]);
	for ( i = 0; i <= 7; i++ )
		v[i] = i-1;
	for ( i = 0; i <= 24; i++ )
	{
		b[i][0] = i/5;
		b[i][1] = i%5;
	}
	do
	{
		j += p();
		i = next();
	}while ( i == 1 );
	cout<<j<<endl;
	return 0;
}