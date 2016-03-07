#include <iostream>
#include <math.h>
using namespace std;
int main ()
{
	int left[31];
	int right[31];
	int l,r;
	int d;
	int a[31];
	int c[30];
	bool b[31];
	int i;
	int maxl;
	a[0] = 1;
	c[0] = 1;
	int t;
	for ( i = 1; i <= 20; i++ )
	{
		a[i] = a[i-1]*3;
		c[i] = c[i-1] + a[i];
	}
	int n;
	int key;
	scanf("%d",&n);
	for ( int o = 0; o < n; o++ )
	{
		scanf("%d",&key);
		for (i = 0; i < 20; i++ )
			b[i] = 0;
		l = r = 0;
		left[0] = right[0] = 0;
		maxl = 1;
		d = key;
		while ( d != 0 )
		{
			i = 0;
			while ( a[i] < d )
				i++;
			t = i;
			while ( b[i] == 1 )
			{
				i--;
				if ( c[i] < d )
				{
					i = -1;
					break;
				}
			}
			if ( i == -1 )
			{
				i = t;
				while ( b[i] == 1 )
					i++;
			}
			if ( a[i] > d )
			{
				d = a[i] - d;
				if ( maxl == 1 )
					right[r++] = a[i];
				else
					left[l++] = a[i];
				b[i] = 1;
				maxl *= -1;
			}
			else if ( a[i] < d )
			{
				d -= a[i];
				if ( maxl == 1 )
					right[r++] = a[i];
				else
					left[l++] = a[i];
				b[i] = 1;
			}
			else
			{
				if ( maxl == 1 )
					right[r++] = a[i];
				else
					left[l++] = a[i];
				d = 0;
			}
		}
		if ( l == 0 )
			printf("empty ");
		else
		{
			printf("%d",left[l-1]);
			for ( i = l-2; i>=0; i-- )
				printf(",%d",left[i]);
			printf(" ");
		}
		if ( r == 0 )
			printf("empty\n");
		else
		{
			printf("%d",right[r-1]);
			for ( i = r-2; i>=0; i-- )
				printf(",%d",right[i]);
			printf("\n");
		}
	}
	return 1;
}