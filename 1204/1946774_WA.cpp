#include <iostream>
using namespace std;
class chang
{
public:
	char list[1010][1010];
	char data[1010][1010];
	int x;
	int y;
	int M;
	int N;
	int W;
	chang ( );
	int copy ( char *a1, char *a2 );
	void input ( );
	int getlen ( char*a );
	int search ( int w );
	int finda ( int w, int i, int j );
	int findb ( int w, int i, int j );
	int findc ( int w, int i, int j );
	int findd ( int w, int i, int j );
	int finde ( int w, int i, int j );
	int findf ( int w, int i, int j );
	int findg ( int w, int i, int j );
	int findh ( int w, int i, int j );
	void go ( );
};

int chang::findb ( int w, int i, int j )
{
	int len = chang::getlen ( data[w] );
	if ( len > i + 1 || len > N - j )
		return -1;
	int k = 0;
	int ii = i;
	int ij = j;
	while ( data[w][k] != NULL )
	{
		if ( data[w][k] != list[ii][ij] )
			return -1;
		ii--;
		ij++;
		k++;
	}
	return 'B';
}
int chang::findc ( int w, int i, int j )
{
	int len = chang::getlen ( data[w] );
	if ( len > N - j )
		return -1;
	int k = 0;
	int ii = i;
	int ij = j;
	while ( data[w][k] != NULL )
	{
		if ( data[w][k] != list[ii][ij] )
			return -1;
		k++;
		ij++;
	}
	return 'C';
}
int chang::findd ( int w, int i, int j )
{
	int len = chang::getlen ( data[w] );
	if ( len > M - i || len > N - j )
		return -1;
	int k = 0;
	int ii = i;
	int ij = j;
	while ( data[w][k] != NULL )
	{
		if ( data[w][k] != list[ii][ij] )
			return -1;
		ii++;
		ij++;
		k++;
	}
	return 'D';
}
int chang::finde ( int w, int i, int j )
{
	int len = chang::getlen ( data[w] );
	if ( len > M - i )
		return -1;
	int k = 0;
	int ii = i;
	int ij = j;
	while ( data[w][k] != NULL )
	{
		if ( data[w][k] != list[ii][ij] )
			return -1;
		ii++;
		k++;
	}
	return 'E';
}
int chang::findf ( int w, int i, int j )
{
	int len = chang::getlen ( data[w] );
	if ( len > j + 1 || len > M - i )
		return -1;
	int k = 0;
	int ii = i;
	int ij = j;
	while ( data[w][k] != NULL )
	{
		if ( data[w][k] != list[ii][ij] )
			return -1;
		ij--;
		ii++;
		k++;
	}
	return 'F';
}
int chang::findg ( int w, int i, int j )
{
	int len = chang::getlen ( data[w] );
	if ( len > j + 1 )
		return -1;
	int k = 0;
	int ii = i;
	int ij = j;
	while ( data[w][k] != NULL )
	{
		if ( data[w][k] != list[ii][ij] )
			return -1;
		ij--;
		k++;
	}
	return 'G';
}
int chang::findh ( int w, int i, int j )
{
	int len = chang::getlen ( data[w] );
	if ( len > i + 1 || len > j + 1 )
		return -1;
	int k = 0;
	int ii = i;
	int ij = j;
	while ( data[w][k] != NULL )
	{
		if ( data[w][k] != list[ii][ij] )
			return -1;
		ij--;
		ii--;
		k++;
	}
	return 'H';
}
int chang::finda ( int w, int i, int j )
{
	int len = chang::getlen ( data[w] );
	if ( len > i + 1 )
		return -1;
	int k = 0;
	int ii = i;
	int ij = j;
	while ( data[w][k] != NULL )
	{
		if ( data[w][k] != list[ii][ij] )
			return -1;
		ii--;
		k++;
	}
	return 'A';
}
int chang::search ( int w )
{
	int m = M;
	int n = N;
	int i;
	int j;
	int k;
	for ( i = 0; i < m; i++ )
	{
		for ( j = 0; j < n; j++ )
		{
			if ( list[i][j] == data[w][0] )
			{
				k = chang::finda ( w, i ,j );
				if ( k != -1 )
				{
					x = i;
					y = j;
					return k;
				}
				k = chang::findb ( w, i, j );
				if ( k != -1 )
				{
					x = i;
					y = j;
					return k;
				}
				k = chang::findc ( w, i ,j );
				if ( k != -1 )
				{
					x = i;
					y = j;
					return k;
				}
				k = chang::findd ( w, i ,j );
				if ( k != -1 )
				{
					x = i;
					y = j;
					return k;
				}
				k = chang::finde ( w, i ,j );
				if ( k != -1 )
				{
					x = i;
					y = j;
					return k;
				}
				k = chang::findf ( w, i ,j );
				if ( k != -1 )
				{
					x = i;
					y = j;
					return k;
				}
				k = chang::findg ( w, i ,j );
				if ( k != -1 )
				{
					x = i;
					y = j;
					return k;
				}
				k = chang::findh ( w, i ,j );
				if ( k != -1 )
				{
					x = i;
					y = j;
					return k;
				}
			}
		}
	}
	return -1;
}
int chang::getlen ( char *a )
{
	int i = 0;
	while ( a[i] != NULL )
		i++;
	return i;
}
int chang::copy ( char *a1, char *a2 )
{
	int i;
	for ( i = 0; a2[i] != NULL; i++ )
		a1[i] = a2[i];
	a1[i] = NULL;
	return 1;
}

chang::chang ( )
{
	M = 20;
	N = 20;
	W = 10;

}
void chang::input ( )
{
	int m;
	int n;
	int w;
	scanf("%d %d %d",&m,&n,&w);
	//cin>>m>>n>>w;
	M = m;
	N = n;
	W = w;
	int i;
	for ( i = 0; i < m; i++ )
		//cin>>list[i];
		scanf("%d",&list[i]);
	for ( i = 0 ; i < w; i++ )
//		cin>>data[i];
		scanf("%d",&data[i]);
}
void chang::go ( )
{
	int i;
	int w = W;
	for ( i = 0 ; i < w; i++ )
	{
	int pos = chang::search ( i );
//	cout<<x<<" "<<y<<" "<<char(pos)<<endl;
	printf("%d %d %c\n",x,y,char(pos));
	}
}

void main ( )
{
	chang a;
	a.input( );
	a.go();
}