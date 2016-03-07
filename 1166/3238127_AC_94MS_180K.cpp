#include <iostream>
using namespace std;
int ans[12],count = 2000000;
int v[12];
int clock[12];
void f ( int i, int t )
{
	if ( i == 1 )
	{
		clock['a'-'a'+1] += t;
		clock['b'-'a'+1] += t;
		clock['d'-'a'+1] += t;
		clock['e'-'a'+1] += t;
	}
	else if ( i == 2 )
	{
		clock['a'-'a'+1] += t;
		clock['b'-'a'+1] += t;
		clock['c'-'a'+1] += t;
	}
	else if ( i == 3 )
	{
		clock['b'-'a'+1] += t;
		clock['c'-'a'+1] += t;
		clock['e'-'a'+1] += t;
		clock['f'-'a'+1] += t;
	}
	else if ( i == 4 )
	{
		clock['a'-'a'+1] += t;
		clock['d'-'a'+1] += t;
		clock['g'-'a'+1] += t;
	}
	else if ( i == 5 )
	{
		clock['b'-'a'+1] += t;
		clock['d'-'a'+1] += t;
		clock['e'-'a'+1] += t;
		clock['f'-'a'+1] += t;
		clock['h'-'a'+1] += t;
	}
	else if ( i == 6 )
	{
		clock['c'-'a'+1] += t;
		clock['f'-'a'+1] += t;
		clock['i'-'a'+1] += t;
	}
	else if ( i == 7 )
	{
		clock['d'-'a'+1] += t;
		clock['e'-'a'+1] += t;
		clock['g'-'a'+1] += t;
		clock['h'-'a'+1] += t;
	}
	else if ( i == 8 )
	{
		clock['g'-'a'+1] += t;
		clock['h'-'a'+1] += t;
		clock['i'-'a'+1] += t;
	}
	else
	{
		clock['e'-'a'+1] += t;
		clock['f'-'a'+1] += t;
		clock['h'-'a'+1] += t;
		clock['i'-'a'+1] += t;
	}
	for ( i = 1; i <= 9; i++ )
	{
		clock[i] += 20;
		clock[i] %= 4;
	}
}
void dfs ( int lay )
{
	int i,j=0;
	if ( lay == 10 )
	{
		for ( i = 1; i <= 9; i++ )
		{
			if ( clock[i] % 4 != 0 )
				break;
			j += v[i];
		}
		if ( i > 9 )
		{
			if ( j < count )
			{
				count = j;
				for ( i = 1; i <= 9; i++ )
					ans[i] = v[i];
			}
		}
		return;
	}
	v[lay] = 0;
	dfs(lay+1);
	for ( i = 1; i < 4; i++ )
	{
		f(lay,1);
		v[lay] = i;
		dfs(lay+1);
	}
	f(lay,1);
	v[lay] = 0;
}
int main ()
{
	int i,j;
	for ( i = 1; i <= 9; i++ )
		scanf("%d",&clock[i]);
	memset(v,0,sizeof(v));
	dfs(1);
	for ( i = 1; i <= 9; i++ )
	{
		for ( j = 0; j < ans[i]; j++ )
			printf("%d ",i);
	}
	printf("\n");
	return 0;
}
