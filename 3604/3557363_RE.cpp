#include <iostream>
using namespace std;
int a[5000000];
int n;
struct ac
{
	int dig[20];
	int len;
}b[500000];
int c[5000000];
void init ()
{
	int i,j;
	for ( i = 1; i <= 5000000; i++ )
		c[i] = 1;
	for ( i = 2; i <= 5000000; i++ )
	{
		for ( j = 1; i*j <= 5000000; j++ )
			c[i*j]++;
	}
}
void make ( int m )
{
	int i;
	n = 1;
	a[0] = 1;
	for ( i = 2; i*2 <= m; i++ )
	{
		if ( m % i == 0 )
			a[n++] = i;
	}
	a[n++] = m;
}
void trans ( ac &t, int k )
{
	if ( k < 10000 )
	{
		t.len = 1;
		t.dig[0] = k;
	}
	else
	{
		t.len = 2;
		t.dig[0] = k%10000;
		t.dig[1] = k/10000;
	}
}
void cube ( ac &t )
{
	ac x=t,y;
	int i,j;
	for ( i = 0; i <200; i++ )
	{
		y.dig[i] = 0;
		x.dig[i] = 0;
	}
	y.len = t.len*2;
	for ( i = 0; i < t.len; i++ )
	{
		for ( j = 0; j < t.len; j++ )
			y.dig[i+j] += t.dig[i]*t.dig[j];
	}
	for ( i = 0; i < y.len; i++ )
	{
		y.dig[i+1] += y.dig[i]/10000;
		y.dig[i] %= 10000;
	}
	for ( i = 0; i < t.len; i++ )
	{
		for ( j = 0; j < y.len; j++ )
			x.dig[i+j] += t.dig[i]*y.dig[j];
	}
	for ( i = 0; i < 200; i++ )
	{
		x.dig[i+1] += x.dig[i]/10000;
		x.dig[i] %= 10000;
	}
	i = 199;
	while ( i > 0 && x.dig[i] == 0 )
		i--;
	x.len = i+1;
	t = x;
}
void plus ( ac &x, ac y )
{
	int i,carry=0;
	ac z;
	for ( i = 0; i < 200; i++ )
		z.dig[i] = 0;
	for ( i = 0; i < 200; i++ )
	{
		z.dig[i] = (x.dig[i]+y.dig[i]+carry)%10000;
		carry = (x.dig[i]+y.dig[i]+carry)/10000;
	}
	i = 199;
	while ( i > 0 && z.dig[i] == 0 )
		i--;
	z.len = i+1;
	x = z;
}
void print ( ac x )
{
	int i;
	printf("%d",x.dig[x.len-1]);
	for ( i = x.len - 2; i >= 0; i-- )
		printf("%04d",x.dig[i]);
	printf("\n");
}
void solve ( )
{
	int m,i;
	cin>>m;
	make(m);
	for ( i = 0; i < n; i++ )
	{
		trans(b[i],c[a[i]]);
		cube(b[i]);
	}
	ac x;
	for ( i = 0; i < 200; i++ )
		x.dig[i] = 0;
	x.len = 1;
	for ( i = 0; i < n; i++ )
		plus(x,b[i]);
	print(x);
}
int main ()
{
	init();
	int tc;
	cin>>tc;
	while ( tc-- )
		solve();
	return 0;
}