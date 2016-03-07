#include <iostream.h>
int a[100][100];
void make ( )
{
	int i;
	int j;
	for ( i = 0; i < 100; i++ )
		for ( j = 0; j < 100; j++ )
			a[i][j] = 0;
}
void print (int x, int y , int l ,int w)
{
	int i;
	int j;
	for ( i = x; i <= x+l-1; i++ )
		for ( j = y; j <= y+l-1; j++ )
			a[i][j] = w;
}
int test ( int x, int y, int l )
{
	int i;
	int j;
	int c = 0;
	for ( i = x; i <= x+l-1; i++ )
	{
		for ( j = y; j <= y+l-1; j++ )
		{
			if ( a[i][j] == 1 )
				c++;
		}
	}
	return c;
}
void main ()
{
	int k;
	cin>>k;
	int i;
	char in[10];
	int x;
	int y; 
	int l;
	for ( i = 0; i < k; i++ )
	{
		cin>>in>>x>>y>>l;
		switch(in[0])
		{
		case 'B':
			print(x,y,l,1);
			break;
		case 'W':
			print(x,y,l,0);
			break;
		case 'T':
			cout<<test(x,y,l)<<endl;
			break;
		}
	}
}