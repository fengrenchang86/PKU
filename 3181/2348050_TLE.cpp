#include <iostream>
using namespace std;
struct ac
{
	int res[20];
	int size;
}a[1010][120];
int plus ( int a[], int b[], int sizea, int sizeb)
{			//数组a[sizea]+数组b[sizeb],结果存入数组c[]
	int i,j;
	int max = sizea<sizeb ? sizea:sizeb;
	for ( i = 0; i < max; i++ )
		a[i] += b[i];
	if ( sizea < sizeb )
	{
		while ( i < sizeb )
		{
			a[i] = b[i];
			i++;
		}
	}
	else
		i = sizea;
	a[i] = 0;
	for ( j = 0; j < i; j++ )
	{
		a[j+1] += a[j]/10000;
		a[j] %= 10000;
	}
	if ( a[i] == 0 )
		return i;
	else
		return i+1;
}
void print( int t[], int size )
{
	cout<<t[size-1];
	for ( int i = size-2; i >= 0; i-- )
		printf("%04d",t[i]);
	cout<<endl;
}
int main () 
{				//a[i][j] = sum{a[i-k][k]}( k<=i && 1<=k<=j )
	int i,j,k;
	int x,y;
	cin>>x>>y;
	for ( i = 1; i <= x; i++ )
	{
		a[i][i].res[0] = 1;
		a[i][i].size = 1;
	}
	for ( i = 2; i <= x; i++ )
	{
		for ( j = 1; j < i&& j <= y; j++ )
		{
			a[i][j].res[0] = 0;
			a[i][j].size = 1;
			for ( k = 1; k <= j && k <= i-j; k++ )
			{
				a[i][j].size = plus(a[i][j].res,a[i-j][k].res,a[i][j].size,a[i-j][k].size);
			}
		}
	}
	int t[20];
	int size = 1;
	{
		for ( i = 0; i < 20; i++ )
			t[i] = 0;
		for ( i = 1; i <= y; i++ )
			size = plus(t,a[x][i].res,size,a[x][i].size);
		print(t,size);
	}
	return 0;
}