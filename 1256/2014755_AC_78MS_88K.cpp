#include <iostream>
using namespace std;
int list[128];
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

char pre[20];
void copy ( char *a, char *b )
{
	int i;
	for ( i = 0; a[i] != NULL; i++ )
		b[i] = a[i];
	b[i] = NULL;
}
void sort ( int v[], int len )
{
	void swap ( int &a, int &b );
	int i,j;
	for ( i = 0; i < len-1; i++ )
		for ( j = 0; j <len; j++ )
			if ( v[i] > v[j] )
				swap(v[i],v[j]);
}
void swap ( int &a, int &b )
{
	int c;
	c = a;
	a =b;
	b = c;
}
void print ( int v[], int len )
{
	int i;
	
	for ( i = 1; i <= len; i++ )
		printf("%d ",v[i]);
	printf("\n");
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
//		printf("%d",v[i]);
	}
	printf("\n");
}
void main ()
{
	char input[30];
	int v[15];
	int h[120];
	char ch;
	int m,c;
	int i,j;
	int tcase,it;
	int len;
	bool exit;
	scanf("%d",&tcase);
	for ( it = 0; it < tcase; it++ )
	{
		make();
		exit = 0;
		scanf("%s",input);
		c = 1;
		len = strlen(input);
		for ( i = 0; i < 50; i++ )
			h[i] = 0;
		for ( i = 0; i < len; i++ )
		{
			v[c++] = list[input[i]];
		}
/*		for ( i = 0; i < len-1; i++ )
		{
			for ( j = i+1; j < len; j++ )
			{
				if ( v[i] > v[j] )
				{
					ch = v[i];
					v[i] = v[j];
					v[j] = ch;
				}
			}
		}*/
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
//		for ( i = 0; i < 10; i++ )
//			v[i] = i;
	//	print( len, input, v );
		v[0] = 0;
		while ( v[0] == 0 )
		{
	//		print(v,len);
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
		//	t = v[i-1];
//			v[i-1]++;
	//		v[i-1] = h[0];
		//	h[c] = t;
	//		sort(v,len);
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