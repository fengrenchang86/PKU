
#include <iostream>
using namespace std;
struct ac
{
	int x,y;
}b[30][900];
int size[30];
int m[30];
char a[30][900];
int count,n,it=1;
bool check ( int num, int step )
{
	int i,x,y;
	for ( i = 0; i < size[num]; i++ )
	{
		if ( b[num][i].y-step < 0 )
			return false;
		x = b[num][i].x;
		y = b[num][i].y;
		if ( a[x][y-step] != '.' && a[x][y-step] != ' ' && a[x][y-step] != num+'1' ) 
			return false;
	}
	return true;
}
void move ( int num, int step )
{
	int i,j,x,y;
	for ( i = 0; i < n; i++ )
	{
		for ( j = 0; j < 900; j++ )
		{
			if ( a[i][j] == num+'1')
				a[i][j] = '.';
		}
	}
	for ( i = 0; i < size[num]; i++ )
	{
		x = b[num][i].x;
		y = b[num][i].y;
		b[num][i].y -= step;
		a[x][y-step] = '1'+num;
	}
}
void solve  ()
{
	int i,j,k,l;
	getchar();
	for ( i = 0; i < n; i++ )
		for ( j = 0; j < 900; j++ )
			a[i][j] = '.';
	for ( i = 0; i < n; i++ )
		gets(a[i]);
	memset(size,0,sizeof(size));
	count = 1;
	m[0] = -1;
	for ( i = 0; a[0][i] != 0; i++ )
	{
		if ( a[0][i] == ' ' )
			m[count++] = i;
	}
	m[count] = i;
	for ( i = 0; i < count; i++ )
	{
		for ( j = 0; j < n; j++ )
		{
			for ( k = m[i]+1; k < m[i+1]; k++ )
			{
				if ( a[j][k] == '#' )
				{
					b[i][size[i]].x = j;
					b[i][size[i]].y = k;
					size[i]++;
					a[j][k] = i+'1';
				}
			}
		}
	}
	for ( i = 0; i < count; i++ )
	{
		if ( size[i] == 0 )
			continue;
		for ( j = 1;; j++ )
		{
			if ( check(i,j) == false )
				break;
		}
		if ( j-2 > 0 )
			move(i,j-2);
	}
	k = 0;
	for ( i = count-2; i >= 0; i-- )
	{
		if ( size[i] == 0 )
			continue;
		for ( j = -1; ; j-- )
		{
			if ( check(i,j) == false )
				break;
		}
		if ( j+2 < 0 )
		{
			k = 1;
			move(i,j+2);
		}
	}
	if ( k == 1 )
	{
		for ( i = 1; i < count; i++ )
		{
			if ( size[i] == 0 )
				continue;
			for ( j = 1;; j++ )
			{
				if ( check(i,j) == false )
					break;
			}
			if ( j-2 > 0 )
				move(i,j-2);
		}
	}
	k = 0;
	l = 20000;
	for ( i = 0; i < n; i++ )
	{
		for ( j = 0; j<900; j++ )
		{
			if ( a[i][j] > '0' && j > k )
				k = j;
			if ( a[i][j] > '0' && j < l)
				l = j;
		}
	}
	printf("%d\n",it++);
	for ( i = 0; i < n; i++ )
	{
		for ( j = l; j <= k; j++ )
		{
			if ( a[i][j] > '0' )
				printf("#");
			else
				printf(".");
		}
		printf("\n");
	}
}
int main ()
{
	while ( scanf("%d",&n)!=EOF )
	{
		if ( n == 0 )
			break;
		solve();
	}
	return 0;
}