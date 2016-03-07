#include <iostream>
using namespace std;
int list[300];
void make ()
{
	int i;
	int c = 0;
	for ( i = 'A'; i <= 'Z'; c++,i++ )
		list[i] = 2*c;
	c = 0;
	for ( i = 'a'; i <= 'z'; c++,i++ )
		list[i] = 2*c+1;
}

void swap ( int &a, int &b )
{
	int c;
	c = a;
	a =b;
	b = c;
}
void print ( int len, char *input, int v[] )
{
	int i;
	for ( i = 1; i <= len; i++ )
	{
		if ( v[i] % 2 ==0 )
			printf("%c",char(v[i]/2+'A'));
		else
			printf("%c",char((v[i]-1)/2+'a'));
	}
	printf("\n");
}
void main ()
{
	char input[300];
	int v[300];
	int h[300];
	char ch;
	int m,c;
	int i,j;
	int tcase,it;
	int len;
	bool exit;
//	scanf("%d",&tcase);
//	for ( it = 0; it < tcase; it++ )
	{
		make();
		exit = 0;
		scanf("%s",input);
		c = 1;
		len = strlen(input);
		for ( i = 0; i < 300; i++ )
			h[i] = 0;
		for ( i = 0; i < len; i++ )
		{
			v[c++] = list[input[i]];
		}
		for ( i = 1; i < c-1; i++ )
		{
			for ( j = i+1; j < c; j++ )
			{
				if ( v[i] > v[j] )
				{
					ch = v[i];
					v[i] = v[j];
					v[j] = ch;
				}
			}
		}
		v[0] = 0;
		while ( v[0] == 0 )
		{
			print(len, input, v );
			i = len;
			if ( v[i-1] < v[i] )
			{
				swap(v[i-1],v[i]);
				continue;
			}
			c = 0;
			m = v[len];
			while ( v[i-1] >= v[i] )
			{
				h[c++] = v[i];
				i--;
				if ( i == 1 )
				{
					exit = 1;
					break;
				}
			}
			if ( exit == 1 )
				break;
			h[c++] = v[i];
			c = 0;
			while ( v[i-1] >= h[c] )
				c++;
			swap ( v[i-1],h[c]);
			c = 0;
			while ( i <= len )
				v[i++] = h[c++];
		}
	}
}