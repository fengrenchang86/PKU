
#include <iostream>
using namespace std;
int main ()
{
	int n;
	cin>>n;
	int begin;
	int *a = new int[n+1];
	int i;
	for ( i =0 ;i  < n; i++ )
		scanf("%d",&a[i]);
	int pre=0;
	int max =0;
	i = 1;
	if ( a[1] > a[0] )
	{
		max = a[1];
		pre++;
	}
	else
		max = a[0];
	i = pre+1;
	while ( i < n )
	{
		if ( a[i] <= a[pre] )
		{
			i++;
			pre++;
			continue;
		}
		max -= a[pre];
		max += a[i];
		pre++;
		i++;
	}
	printf("%d\n",max);
	return 1;
}