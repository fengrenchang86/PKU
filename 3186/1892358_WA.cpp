#include <iostream>
using namespace std;
int main ()
{
	int a[2001];
	int i;
	int j;
	int n;
	int max = 0;
	scanf("%d",&n);
	for ( int k = 0; k < n ; k++ )
	{
		scanf("%d",&a[k]);
	}
	i = 0;
	j = n-1;
	for ( k = 0; k < n; k++ )
	{
		if ( a[i] < a[j] )
		{
			max += (k+1)*a[i];
			i++;
		}
		else
		{
			max += (k+1)*a[j];
			j--;
		}
	}
	printf("%d\n",max);
	return 1;
}