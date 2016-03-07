#include <iostream>
using namespace std;
char a[6][6];
int v[8];
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
		if ( a[v[i]/5][v[i]%5] == 'H' )
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
			if ( v[i]/5 == v[j]/5 && abs(v[i]%5-v[j]%5)==1 )
			{
				join(v[i],v[j]);
			}
			else if ( v[i]%5 == v[j]%5 && abs(v[i]/5-v[j]/5)==1 )
			{
				join(v[i],v[j]);
			}
		}
	}
	k = find(v[1]);
	for ( i = 2; i <= 7; i++ )
		if ( find(v[i]) != k )
			return 0;
	return 1;
}
int main ()
{
	int i,j = 0;
	for ( i = 0; i < 5; i++ )
		scanf("%s",&a[i]);
	for ( i = 0; i <= 7; i++ )
		v[i] = i-1;
	do
	{
		j += p();
		i = next();
	}while ( i == 1 );
	cout<<j<<endl;
	return 0;
}