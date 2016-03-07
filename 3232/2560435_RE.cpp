#include <iostream>
using namespace std;
int main ()
{
	int a[100001];
	int tcase,n,m,k,i;
	int begin,end,mid;
	_int64 t;
	scanf("%d",&tcase);
	while ( tcase )
	{
		tcase--;
		scanf("%d",&n);
		for ( i = 0; i < n; i++ )
			scanf("%d",&a[i]);
		scanf("%d%d",&m,&k);
		k--;
		begin = 0;
		end = 100000000;
		while ( begin < end )
		{
			mid = (begin+end)/2;
			t = mid*m;
			for ( i = 0; i < n; i++ )
			{
				if ( a[i] > mid )
				{
					t -= (a[i]-mid)/k;
					if ( (a[i]-mid)%k != 0 )
						t--;
					if ( t < 0 )
						break;
				}
			}
			if ( t < 0 )
				begin = mid+1;
			else 
				end = mid;
			
		}
		printf("%d\n",end);
	}
	return 0;
}