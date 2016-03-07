#include <iostream>
using namespace std;
int main ()
{
	void f(int);
	int match(char*);
	int x,y,tcase;
	scanf("%d",&tcase);
	char a[100000],b[100000];
	while ( tcase-- )
	{
		scanf("%s %s",&a,&b);
		x = match(a);
		y = match(b);
		f(x+y);
		printf("\n");
	}
	return 0;
}
int match( char *t )
{
	int x=-1;
	int y=-1;
	int i=0;
	while ( t[i] != NULL )
	{
		if ( t[i] == '{' )
			x++;
		else if ( t[i] == '}' )
			x--;
		else
		{
			i++;
			continue;
		}
		if ( x == 0 )
			y++;
		i++;
	}
	return y;
}
void f ( int k )
{
	if ( k == 0 )
	{
		printf("{}");
		return;
	}
	else if ( k == 1 )
	{
		printf("{{}}");
		return;
	}
	else
	{
		printf("{");
		f(0);
		int i;
		for ( i = 1; i < k; i++ )
		{
			printf(",");
			f(i);
		}
		printf("}");
	}
}