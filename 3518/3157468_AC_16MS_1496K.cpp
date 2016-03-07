#include <iostream>
using namespace std;
bool p[1300000];
void init ()
{
	int i,j;
	for ( i = 0; i <= 1299709; i++ )
		p[i] = true;
	for ( i = 2; i <= 1299709; i++ )
	{
		if ( p[i] == false )
			continue;
		j = 2;
		while ( i*j <= 1299709 )
		{
			p[i*j] = false;
			j++;
		}
	}
	p[0] = p[1] = false;
}
int main ()
{
	init();
	int n,ans,i;
	while ( scanf("%d",&n) && n )
	{
		ans = 0;
		if ( p[n] == true )
			printf("0\n");
		else
		{
			i = n-1;
			while ( i > 1 && p[i] == false )
				i--;
			ans += n-i;
			i = n+1; 
			while ( i <= 1299709 && p[i] == false )
				i++;
			ans += i-n;
			printf("%d\n",ans);
		}
	}
	return 0;
}