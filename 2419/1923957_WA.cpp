#include <iostream>
using namespace std;
int main ()
{
	int a[101];
	int p,t;
	int x,y;
	int i;
	int j = 0;
	scanf("%d %d",&p,&t);
	for ( i = 0; i < t; i++ )
		a[i] = 0;
	while ( scanf("%d %d",&x,&y) != EOF )
	{
		a[y]++;
		if ( a[y] == 2 )
			j++;
	}
	printf("%d\n",j);
	return 1;
}