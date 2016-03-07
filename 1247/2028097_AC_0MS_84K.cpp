#include <iostream>
using namespace std;
int main ()
{
	int n;
	int i;
	int low,high;
	int a,b;
	while ( scanf("%d",&n) && n != 0 )
	{
		int *c = new int[n+1];
		a = b = 0;
		for ( i = 0; i < n; i++ )
			scanf("%d",&c[i]);
		low = 0;
		high = n-1;
		
		while ( low <= high )
		{
			if ( a > b )
				b +=c[high--];
			else
				a += c[low++];
		}
//		cout<<a<<" "<<b<<endl;
		if ( a== b )
			printf("Sam stops at position %d and Ella stops at position %d.\n",high+1,low+1);
		else
			printf("No equal partitioning.\n");
	}
	return 1;
}