#include <iostream>
using namespace std;
int a[10];
char b[10000];
int j = 0;
void p ()
{
	int i;
	for ( i = 0; i <= 9; i++ )
	{
		while ( a[i] > 0 )
		{
			b[j++] = char(i+'0');
			a[i]--;
		}
	}
	j--;
	while ( b[j] == '0' && j >= 0)
		j--;
	if ( j < 0 )
		printf("0");
	while ( j >= 0 )
	{
		printf("%c",b[j]);
		j--;
	}
	printf("\n");
}
int main ()
{
	char ch[1200];
	cin>>ch;
	int i,c,sum=0;
	for ( i = 0; i < 10; i++ )
		a[i] = 0;
	for ( i = 0; ch[i] != NULL; i++ )
	{
		a[ch[i]-'0']++;
		sum += ch[i]-'0';
	}
	if ( a[0] == 0 && a[5] == 0 )
	{
		printf("impossible\n");
		return 0;
	}
	if ( sum % 3 == 0 )
	{
		if ( a[0] != 0 )
		{
			b[j++] = '0';
			a[0]--;
		}
		else
		{
			b[j++] = '5';
			a[5]--;
		}
		p();
	}
	else if ( sum % 3 == 1 )
	{
		if ( a[0] != 0 )
		{
			b[j++] = '0';
			a[0]--;
		}
		else
		{
			b[j++] = '5';
			a[5]--;
		}
		if ( a[1] != 0 )
			a[1]--;
		else if ( a[4] != 0 )
			a[4]--;
		else if ( a[7] != 0 )
			a[7]--;
		else if ( a[2] + a[5] + a[8] >= 2 )
		{
			c = 2;
			for ( i = 2; i <= 8; i+=3 )
			{
				while ( a[i] != 0 )
				{
					a[i]--;
					c--;
					if ( c == 0 )
						break;
				}
				if ( c == 0 )
					break;
			}
		}
		else 
		{
			printf("impossible\n");
			return 0;
		}
		p();
	}
	else
	{
		if ( a[0] != 0 )
		{
			b[j++] = '0';
			a[0]--;
		}
		else
		{
			b[j++] = '5';
			a[5]--;
		}
		if ( a[2] != 0 )
			a[2]--;
		else if ( a[5] != 0 )
			a[5]--;
		else if ( a[8] != 0 )
			a[8]--;
		else if ( a[1]+a[4]+a[7] >= 2 )
		{
			c = 2;
			for ( i = 1; i <= 7; i+= 3 )
			{
				while ( a[i] != 0 )
				{
					a[i]--;
					c--;
					if ( c == 0 )
						break;
				}
				if ( c == 0 )
					break;
			}
		}
		else
		{
			printf("impossible\n");
			return 0;
		}
		p();
	}
	return 0;
}