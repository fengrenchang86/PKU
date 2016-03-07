#include <iostream>
using namespace std;
int main ()
{
	double left[30];
	double right[30];
	int l,r;
	double d;
	double a[31];
	bool b[31];
	int i;
	int maxl;
	a[0] = 1;
	for ( i = 1; i <= 30; i++ )
		a[i] = a[i-1]*3;
	int n;
	int key;
	scanf("%d",&n);
	for ( int o = 0; o < n; o++ )
	{
		scanf("%d",&key);
		for (i = 0; i < 31; i++ )
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
			while ( b[i] == 1 )
				i--;
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
			printf("%.0lf",left[l-1]);
			for ( i = l-2; i>=0; i-- )
				printf(",%.0lf",left[i]);
			printf(" ");
		}
		if ( r == 0 )
			printf("empty\n");
		else
		{
			printf("%0.lf",right[r-1]);
			for ( i = r-2; i>=0; i-- )
				printf(",%.0lf",right[i]);
			printf("\n");
		}
	}
	return 1;
}