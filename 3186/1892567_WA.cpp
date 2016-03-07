#include <iostream>
using namespace std;
int main ()
{
	int a[2030];
	int i;
	int j;
	int pi,pj;
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
		else if ( a[i] > a[j] )
		{
			max += (k+1)*a[j];
			j--;
		}
		else
		{
			pi = i;
			pj = j;
			while ( a[pi] == a[pj] )
			{
//				pi++;
//				pj--;
				if ( a[pi] > a[pj] )
				{	
					max+= (k+1)*a[j];
					j--;
					break;
				}
				else if ( a[pj] > a[pi] )
				{
					max += (k+1)*a[i];
					i++;
					break;
				}
				else if ( pi == pj || pi+1==pj&&a[pi]==a[pj] )
				{
					max += (k+1)*a[i];
					i++;
					break;
				}
				pi++;
				pj--;
			}
		}
	}
	printf("%d\n",max);
	return 1;
}