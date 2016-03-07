#include <iostream>
using namespace std;
int a[500][100];
int size[500];
int pow[4] = {1,10,100,1000};
int qa[100];
int qb[100];
int plus ( int a[], int sizea, int b[], int sizeb, int c[])
{
	int i;
	int max = sizea > sizeb ? sizea : sizeb;
	int min = sizea < sizeb ? sizea : sizeb;
	for ( i = 0; i <= max; i++ )
		c[i] = 0;
	for ( i = 0; i < min; i++ )
		c[i] = a[i]+b[i];
	while ( i < sizea )
	{
		c[i] = a[i];
		i++;
	}
	while ( i < sizeb )
	{
		c[i] = b[i];
		i++;
	}
	for ( i = 0; i < max; i++ )
	{
		c[i+1] += c[i]/10000;
		c[i] %= 10000;
	}
	while ( c[max] > 0 )
		max++;
	return max;
}
int comp ( int x, int y[], int sizey )
{
	if ( size[x] != sizey )
		return size[x] > sizey ? 1 : -1;
	int i = size[x];
	while ( i >= 0 )
	{
		if ( a[x][i] != y[i] )
			return a[x][i] > y[i] ? 1 : -1;
		i--;
	}
	return 0;
}
void init ()
{
	a[0][0] = 1;
	a[1][0] = 2;
	size[0] = 1;
	size[1] = 1;
	int i;
	for ( i = 2; i < 500; i++ )
		size[i] = plus(a[i-2],size[i-2],a[i-1],size[i-1],a[i]);
}
int toa ( char *t, int v[] )
{
	int len = strlen(t);
	int i = len-1;
	int j = 0, k = 0;
	for ( i = 0; i < 100; i++ )
		v[i] = 0;
	i = len-1;
	while ( i >= 0 )
	{
		if( k == 4 )
		{
			k = 0;
			j++;
		}
		v[j] += (t[i]-'0')*pow[k];
		k++;
		i--;
	}
	return j+1;
}
void p ( int t[], int size )
{
	int i = size-2;
	printf("%d",t[size-1]);
	while ( i >= 0 )
	{
		printf("%04d",t[i]);
		i--;
	}
	printf("\n");
}
int find1 ( int v[], int size )
{
	int i;
	int d;
	for ( i = 0; ; i++ )
	{
		d = comp(i,v,size);
		if ( d == 1 || d == 0)
			return i-1;
	}
	return 0;
}
int find2 ( int v[], int size )
{
	int i;
	for ( i = 0; ; i++ )
	{
		if ( comp(i,v,size) == 1 )
			return i-1;
	}
	return 0;
}
int main ()
{
	int k,i;
	init();
	int sa,sb;
	char ch1[200],ch2[200];
	while ( cin >> ch1 >> ch2 )
	{
		if ( ch1[0] == '0' && ch2[0] == '0' )
			break;
		sa = toa(ch1,qa);
		sa = find1(qa,sa);
		sb = toa(ch2,qb);
		sb = find2(qb,sb);
		cout<<sb-sa<<endl;
	}
	return 0;
}