#include <iostream>
using namespace std;
int f[50];
int v[50];
void init ()
{
	int i;
	f[0] = 1;f[1] = 2;
	for ( i = 2; i <= 40; i++ )
		f[i] = f[i-1]+f[i-2];
}
int Change( char *t )
{
	int i,k=0,j=0;
	for ( i = strlen(t)-1; i >= 0; i--,j++)
	{
		if ( t[i] == '1' )
			k += f[j];
	}
	return k;
}
int Change( char *t, int k )
{
	int i,j;
	for ( i = 40; i >= 0; i-- )
	{
		v[i] = k/f[i];
		k %= f[i];
	}
	i = 40;
	while ( i > 0 && v[i] == 0 )
		i--;
	j = 0;
	while ( i >= 0 )
	{
		if ( v[i] == 1 )
			t[j] = '1';
		else
			t[j] = '0';
		j++;
		i--;
	}
	t[j] = 0;
	return j;
}
int main ()
{
	init();
	char a[100],b[100],c[100];
	int sa,sb,sc;
	int x,y,i;
	while ( scanf(" %s %s",a,b) != EOF )
	{
		x = Change(a);
		sa = Change(a,x);
		y = Change(b);
		sb = Change(b,y);
		sc = Change(c,x+y);
		printf("  ");
		for ( i = 0; i < sc-sa; i++ )
			printf(" ");
		printf("%s\n",a);

		printf("+ ");
		for ( i = 0; i < sc-sb; i++ )
			printf(" ");
		printf("%s\n",b);

		printf("  ");
		for ( i = 0; i < sc; i++ )
			printf("-");
		printf("\n");

		printf("  ");
		printf("%s\n\n",c);
	}
	return 0;
}