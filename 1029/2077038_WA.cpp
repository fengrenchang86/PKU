#include <iostream>
using namespace std;

int main ()
{
	int n,t;
	scanf("%d%d",&n,&t);
	int *a = new int[n+1];
	int *l = new int[n+1];
	int *input = new int [n+1];
	int i,j,k,x;
	int m;
	char ch;
	for ( i = 0; i <= n; i++ )
		a[i] = l[i] = 0;
	for ( j = 0; j < t; j++ )
	{
		scanf("%d",&m);
		for ( i = 1; i <= 2*m; i++ )
			scanf("%d",&input[i]);
		cin>>ch;
		if ( ch == '=' )
		{
			for ( i = 1; i <= 2*m; i++ )
				l[input[i]] = 1;
		}
		else if ( ch == '<' )
		{
			for ( i = 1; i <= n; i++ )
			{
				x = 0;
				for ( k = 1; k <= 2*m; k++ )
				{
					if ( i == input[k] )
					{
						x ++;
						break;
					}
				}
				if ( x == 0 )
					l[i] = 1;
			}
			for ( i = 1; i <= m; i++ )
			{
				if ( l[input[i]] == 1 )
					continue;
				if ( a[input[i]] > 0 )
					l[input[i]] = 1;
				else
					a[input[i]]--;
			}
			for ( i = m+1; i <= 2*m; i++ )
			{
				if ( l[input[i]] == 1 )
					continue;
				if ( a[input[i]] < 0 )
					l[input[i]] = 1;
				else
					a[input[i]]++;
			}
		}
		else
		{
			for ( i = 1; i <= n; i++ )
			{
				x = 0;
				for ( k = 1; k <= 2*m; k++ )
				{
					if ( i == input[k] )
					{
						x ++;
						break;
					}
				}
				if ( x == 0 )
					l[i] = 1;
			}
			for ( i = 1; i <= m; i++ )
			{
				if ( l[input[i]] == 1 )
					continue;
				if ( a[input[i]] > 0 )
					l[input[i]] = 1;
				else
					a[input[i]]--;
			}
			for ( i = m+1; i <= 2*m; i++ )
			{
				if ( l[input[i]] == 1 )
					continue;
				if ( a[input[i]] > 0 )
					l[input[i]] = 1;
				else
					a[input[i]]--;
			}
		}
	}
	j = 0;
	m = 0;
	for ( i = 1; i <= n; i++ )
	{
		if ( l[i] == 0 )
		{
			m++;
			j = i;
		}
	}
	if ( m == 1 )
		printf("%d\n",j);
	else
		printf("0\n");
	return 0;
}