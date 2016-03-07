#include <iostream>
#include <math.h>
using namespace std;

unsigned int toten ( char *a,int base )
{
	unsigned int ans = 0;
	int i;
	int len = strlen(a);
	for ( i = 0; i < len; i++ )
	{
		if ( a[i] >= '0' && a[i] <= '9' )
			ans += (a[i]-'0')*pow(base,len-1-i);
		else if ( a[i] >= 'A' && a[i] <= 'F' )
			ans += (a[i]-'A'+10)*pow(base,len-1-i);
	}
	return ans;
}
int change ( unsigned int ans, int base, char *a )
{
	int i;
	int temp;
	for ( i = 0; i < 7; i++ )
	{
		temp = ans/pow(base,6-i);
		if ( temp == 0 )
			a[i] = '0';
		else
		{
			if ( temp < 10 )
				a[i] = temp+'0';
			else
				a[i] = temp+'A'-10;
		}
		ans -= temp*pow(base,6-i);
	}
	for ( i = 0; i < 7; i++ )
	{
		if ( a[i] >= '0' && a[i] <= '9' )
		{
			if ( a[i]-'0' > base-1 )
				return 0;
		}
		else
		{
			if (a[i]-'A'+10 > base-1 )
				return 0;
		}
	}
	i = 0;
	while ( a[i] == '0' )
		a[i++] = ' ';
	return 1;
}

int main ()
{
	char a[10];
	int x,y;
	int g;
	char c;
	unsigned int ans;
	while ( scanf("%s",a)!=EOF )
	{
		cin.ignore();
		scanf("%d %d",&x,&y);
		cin.clear();
		ans = toten(a,x);
		g = change(ans,y,a);
		if ( g == 0 )
			printf("  ERROR\n");
		else
		{
			for ( g = 0; g < 7;g++ )
				printf("%c",a[g]);
			printf("\n");
		}
		cin.ignore();
	}
	return 1;
}