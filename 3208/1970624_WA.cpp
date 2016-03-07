#include <iostream>
#include <math.h>
using namespace std;
int ans[12];
int list[] = {0,19,280,3700,46000,550000,6400000,73000000};
int l[] = { 0, 9,90,900,9000,90000,900000,9000000};
void f ( int x )
{
	int i,j,k;
	if ( x > 19 )
	{
		i = 1;
		while (list[i] < x)
			i++;
		k = i-1;
		i = 0;
		while ( x > 0 && i <= 5 )
		{
			x -= list[k];
			i++;
		}
		int g;
		if ( x > 0 )
			g = 1;
		else 
			g = 0;
		if ( x > 0 )
		{
			x -= list[k];
			x -= l[k+1];
			i++;
		}
		if ( g == 1 && x < 0 )
		{
			x+=list[k];
			x+= l[k+1];
			j = x-i;
			k = 1;
			while ( j > 0 )
			{
				ans[k] = j%10;
				j/=10;
				k++;
			}
			x = 0;
			return ;
		}
		while ( x > 0 && i <= 9 )
		{
			x-=list[k];
			i++;
		}
		ans[k+4] = i-1;
	//	if ( x == 0 )
	//		return ;
		i--;
		x+=list[i];
		f(x);
	}
	else
	{
		if ( x >=1 && x <= 6 )
			ans[4] = x-1;
		else if ( x >= 7 && x <= 16 )
			ans[1] = x-7;
		else
			ans[4] = x - 10;
	}
}
int main ()
{
	int tcase,it;
	
	scanf("%d",&tcase);
	int n,i,j;
	int v[10];
	int a,b,c;
	int k;
	int m;
	for ( it = 0; it  < tcase; it++ )
	{
		scanf("%d",&n);
		i = 1;
		while ( list[i] < n )
			i++;
		if ( list[i] == n )
		{
			for ( k = 0; k < i; k++ )
				printf("9");
			printf("666\n");
			continue;
		}
		for ( j = 0; j < 12; j++ )
			ans[j] = 6;
		a = i-1;
		k = n-list[a];
		f(n);
		j = i+3;
		while ( ans[j] == 0 )
			j--;
		for ( ; j >= 1; j-- )
			printf("%d",ans[j]);
		printf("\n");
	}
	return 1;

}