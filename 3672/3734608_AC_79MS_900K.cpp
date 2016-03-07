#include <iostream>
using namespace std;
char ch[1001000];
int main ()
{
	int m,n,u,f,d;
	int i;
	int k=0,j=0;
	scanf("%d %d %d %d %d",&m,&n,&u,&f,&d);
	for ( i = 0; i < n; i++ )
	{
		scanf(" %c",&ch[i]);
		if ( k > m )
			continue;
		if ( ch[i] == 'f' )
			k += 2*f;
		else
			k += d+u;
		if ( k > m )
			j = i;
	}
	printf("%d\n",j);
	return 0;
}