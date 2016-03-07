#include <iostream>
using namespace std;
int a[500];
int n;
struct ac
{
	bool use;
	int data;
}b[500];
int c[500];
bool visit[500];
int factor(int);
void init ()
{
	int i,j;
	for ( i = 0; i < 500; i++ )
		c[i] = -1;
	for ( i = 1; i <= 100; i++ )
	{
		b[i].use = false;
		b[i].data = i;
		b[i].data = (b[i].data*b[i].data*b[i].data);
	}
}
void make ( int m )
{
	int i;
	n = 0;
	for ( i = 1; i*i < m; i++ )
	{
		if ( m % i == 0 )
		{
			a[n++] = i;
			a[n++] = m/i;
		}
	}
	if ( i*i == m )
		a[n++] = i;
//	printf(" the num %d has %d factor\n",m,n);
}
int factor( int m )
{
	if ( m == 1 )
		return 1;
	else if ( m < 500 && c[m] != -1 )
		return c[m];
	int i,k = 0,sum=1;
	for ( i = 2; i*i <= m; i++ )
	{
		k = 0;
		while ( m % i == 0 )
		{
			k++;
			m/=i;
		}
		if ( k > 0 )
		{
			k++;
			sum *= k;
		}
	}
	if ( m > 1 )
		sum = sum*2;
	if ( m < 500 )
		c[m] = sum;
	return sum;
}
void plus ( ac &x, ac y )
{
	x.data = x.data+y.data;
}
void print ( ac x )
{
	printf("%d\n",x.data);
}
void solve ( )
{
	int m,i,k;
	scanf("%d",&m);
	make(m);
	memset(visit,false,sizeof(visit));
	ac x;
	x.data = 0;
	for ( i = 0; i < n; i++ )
	{
		k = factor(a[i]);
		plus(x,b[k]);
	}
	print(x);
}
int main ()
{
	init();
	int tc;
	scanf("%d",&tc);
	while ( tc-- )
		solve();
	return 0;
}